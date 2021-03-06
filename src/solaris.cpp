//Tested on:
//	Solaris 11.2 (g++)

#include "wofstat.hpp"

#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>
#include <vector>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stropts.h>

#include <cstring>

#include <sys/tihdr.h>
#include <inet/mib2.h>

#include "string_util.hpp"

class buffer_t
{
	public:
		char buffer[512];
		strbuf buf;

		buffer_t()
		{
			memset(buffer,0,512);
			buf.buf=(char*)buffer;
			buf.len=512;
		}
};

struct request_t
{
	public:
		request_t()
		{
			req_header.PRIM_type=T_SVR4_OPTMGMT_REQ;
			req_header.OPT_length=sizeof(opt_header);
			req_header.OPT_offset=offsetof(request_t,opt_header);
			req_header.MGMT_flags=T_CURRENT;
			opt_header.level=MIB2_IP;
			opt_header.name=0;
			opt_header.len=0;
		}

		T_optmgmt_req req_header;
		opthdr opt_header;
};

struct reply_t
{
	T_optmgmt_ack ack_header;
	opthdr opt_header;
};

static std::string state_int_to_string(const uint32_t state)
{
	if(state==MIB2_TCP_established)
		return "ESTABLISHED";
	if(state==MIB2_TCP_synSent)
		return "SYN_SENT";
	if(state==MIB2_TCP_synReceived)
		return "SYN_RECV";
	if(state==MIB2_TCP_finWait1)
		return "FIN_WAIT1";
	if(state==MIB2_TCP_finWait2)
		return "FIN_WAIT2";
	if(state==MIB2_TCP_timeWait)
		return "TIME_WAIT";
	if(state==MIB2_TCP_closed)
		return "CLOSE";
	if(state==MIB2_TCP_closeWait)
		return "CLOSE_WAIT";
	if(state==MIB2_TCP_lastAck)
		return "LAST_ACK";
	if(state==MIB2_TCP_listen)
		return "LISTEN";
	if(state==MIB2_TCP_closing||state==MIB2_TCP_deleteTCB)
		return "CLOSING";
	return "UNKNOWN";
}

wofstat_list_t wofstat()
{
	int fd=open("/dev/arp",O_RDWR);
	if(fd==-1)
		throw std::runtime_error("wofstat_solaris() - Could not find /dev/arp.");
	if(ioctl(fd,I_PUSH,"tcp")==-1)
		throw std::runtime_error("wofstat_solaris() - Could not push module tcp into /dev/arp.");
	if(ioctl(fd,I_PUSH,"udp")==-1)
		throw std::runtime_error("wofstat_solaris() - Could not push module udp into /dev/arp.");
	request_t request;
	strbuf buf;
	buf.len=sizeof(request);
	buf.buf=(char*)&request;
	if(putmsg(fd,&buf,NULL,0)<0)
		throw std::runtime_error("wofstat_solaris() - putmsg failed for /dev/arp.");
	wofstat_list_t tcp4;
	wofstat_list_t tcp6;
	wofstat_list_t udp4;
	wofstat_list_t udp6;
	while(true)
	{
		strbuf buf2;
		int flags=0;
		reply_t reply;
		buf2.maxlen=sizeof(reply);
		buf2.buf=(char*)&reply;
		int ret=getmsg(fd,&buf2,NULL,&flags);
		if(ret<0)
			throw std::runtime_error("wofstat_solaris() - getmsg failed for /dev/arp.");
		if(ret!=MOREDATA)
			break;
		if(reply.ack_header.PRIM_type!=T_OPTMGMT_ACK)
			throw std::runtime_error("wofstat_solaris() - Invalid acknowledgement header primative type from getmsg.");
		if((size_t)buf2.len<sizeof(reply.ack_header))
			throw std::runtime_error("wofstat_solaris() - Invalid buffer length received from getmsg.");
		if((size_t)reply.ack_header.OPT_length<sizeof(reply.opt_header))
			throw std::runtime_error("wofstat_solaris() - Invalid option length received from getmsg.");
		std::vector<uint8_t> data;
		data.resize(reply.opt_header.len);
		buf2.maxlen=reply.opt_header.len;
		buf2.buf=(char*)&data[0];
		flags=0;
		if(getmsg(fd,NULL,&buf2,&flags)>=0)
		{
			if(reply.opt_header.level==MIB2_TCP&&reply.opt_header.name==MIB2_TCP_CONN)
			{
				for(int ii=0;ii<buf2.len;ii+=sizeof(mib2_tcpConnEntry_t))
				{
					mib2_tcpConnEntry_t* entry=(mib2_tcpConnEntry_t*)((char*)&data[0]+ii);
					wofstat_t wofstat;
					wofstat.proto="tcp4";
					wofstat.laddr=u32_to_ipv4(entry->tcpConnLocalAddress);
					wofstat.faddr=u32_to_ipv4(entry->tcpConnRemAddress);
					wofstat.lport=u16_to_port(htons(entry->tcpConnLocalPort));
					wofstat.fport=u16_to_port(htons(entry->tcpConnRemPort));
					wofstat.state=state_int_to_string(entry->tcpConnState);
					wofstat.pid="-";
					#if(defined(NEWSOLARIS))
					if(wofstat.state!="TIME_WAIT")
						wofstat.pid=to_string(entry->tcpConnCreationProcess);
					#endif
					tcp4.push_back(wofstat);
				}
			}
			#if(defined(MIB2_TCP6))
				if(reply.opt_header.level==MIB2_TCP6&&reply.opt_header.name==MIB2_TCP6_CONN)
				{
					for(int ii=0;ii<buf2.len;ii+=sizeof(mib2_tcp6ConnEntry_t))
					{
						mib2_tcp6ConnEntry_t* entry=(mib2_tcp6ConnEntry_t*)((char*)&data[0]+ii);

						wofstat_t wofstat;
						wofstat.proto="tcp6";
						wofstat.laddr=u8x16_to_ipv6(entry->tcp6ConnLocalAddress.s6_addr);
						wofstat.faddr=u8x16_to_ipv6(entry->tcp6ConnRemAddress.s6_addr);
						wofstat.lport=u16_to_port(htons(entry->tcp6ConnLocalPort));
						wofstat.fport=u16_to_port(htons(entry->tcp6ConnRemPort));
						wofstat.state=state_int_to_string(entry->tcp6ConnState);
						wofstat.pid="-";
						#if(defined(NEWSOLARIS))
						if(wofstat.state!="TIME_WAIT")
							wofstat.pid=to_string(entry->tcp6ConnCreationProcess);
						#endif
						wofstat.laddr=ipv6_prettify(wofstat.laddr);
						wofstat.faddr=ipv6_prettify(wofstat.faddr);
						tcp6.push_back(wofstat);
					}
				}
			#endif
			if(reply.opt_header.level==MIB2_UDP&&reply.opt_header.name==MIB2_UDP_ENTRY)
			{
				for(int ii=0;ii<buf2.len;ii+=sizeof(mib2_udpEntry_t))
				{
					mib2_udpEntry_t* entry=(mib2_udpEntry_t*)((char*)&data[0]+ii);
					wofstat_t wofstat;
					wofstat.proto="udp4";
					wofstat.laddr=u32_to_ipv4(entry->udpLocalAddress);
					wofstat.faddr="0.0.0.0";
					wofstat.lport=u16_to_port(htons(entry->udpLocalPort));
					wofstat.fport=0;
					wofstat.state="-";
					wofstat.pid="-";
					#if(defined(NEWSOLARIS))
					if(wofstat.state!="TIME_WAIT")
						wofstat.pid=to_string(entry->udpCreationProcess);
					#endif
					udp4.push_back(wofstat);
				}
			}
			#if(defined(MIB2_UDP6))
				if(reply.opt_header.level==MIB2_UDP6&&reply.opt_header.name==MIB2_UDP6_ENTRY)
				{
					for(int ii=0;ii<buf2.len;ii+=sizeof(mib2_udp6Entry_t))
					{
						mib2_udp6Entry_t* entry=(mib2_udp6Entry_t*)((char*)&data[0]+ii);
						wofstat_t wofstat;
						wofstat.proto="udp6";
						wofstat.laddr=u8x16_to_ipv6(entry->udp6LocalAddress.s6_addr);
						wofstat.faddr="0000:0000:0000:0000:0000:0000:0000:0000";
						wofstat.lport=u16_to_port(htons(entry->udp6LocalPort));
						wofstat.fport=0;
						wofstat.state="-";
						wofstat.pid="-";
						#if(defined(NEWSOLARIS))
						if(wofstat.state!="TIME_WAIT")
							wofstat.pid=to_string(entry->udp6CreationProcess);
						#endif
						wofstat.laddr=ipv6_prettify(wofstat.laddr);
						wofstat.faddr=ipv6_prettify(wofstat.faddr);
						udp6.push_back(wofstat);
					}
				}
			#endif
		}
	}
	wofstat_list_t wofstats;
	for(size_t ii=0;ii<tcp4.size();++ii)
			wofstats.push_back(tcp4[ii]);
	for(size_t ii=0;ii<tcp6.size();++ii)
			wofstats.push_back(tcp6[ii]);
	for(size_t ii=0;ii<udp4.size();++ii)
			wofstats.push_back(udp4[ii]);
	for(size_t ii=0;ii<udp6.size();++ii)
			wofstats.push_back(udp6[ii]);
	return wofstats;
}
