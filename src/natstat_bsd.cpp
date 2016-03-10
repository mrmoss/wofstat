//Tested on:
//	FreeBSD 9.2 (g++)
//	FreeBSD 10.0 (g++)

#include "natstat.hpp"

#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>
#include <vector>

#include <sys/file.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/socketvar.h>

#include <netinet/in.h>
#include <netinet/in_pcb.h>
#include <netinet/tcp_var.h>

#include "natstat_util.hpp"
#include "string_util.hpp"

typedef std::vector<xfile*> xfilep_list_t;

static natstat_list_t natstat_bsd_parse(const std::string& proto)
{
	size_t xflen=0;
	if(sysctlbyname("kern.file",NULL,&xflen,NULL,0)==-1)
		throw std::runtime_error("error getting data size.");
	std::vector<uint8_t> xfbuf;
	xfbuf.resize(xflen);
	if(sysctlbyname("kern.file",(char*)&xfbuf[0],&xflen,NULL,0)==-1)
		throw std::runtime_error("error getting data.");
	natstat_list_t natstats;
	size_t len=0;
	std::string sysctl_path("");
	if(proto=="tcp4")
		sysctl_path="net.inet.tcp.pcblist";
	if(proto=="udp4")
		sysctl_path="net.inet.udp.pcblist";
	#if(defined(AF_INET6))
	if(proto=="tcp6")
		sysctl_path="net.inet.tcp.pcblist";
	if(proto=="udp6")
		sysctl_path="net.inet.udp.pcblist";
	#endif
	if(sysctl_path=="")
		throw std::runtime_error("Invalid protocol.");
	if(sysctlbyname(sysctl_path.c_str(),NULL,&len,NULL,0)==-1)
		throw std::runtime_error("error getting data size.");
	std::vector<uint8_t> buf;
	buf.resize(len);
	if(sysctlbyname(sysctl_path.c_str(),(char*)&buf[0],&len,NULL,0)==-1)
		throw std::runtime_error("error getting data.");
	for(size_t ii=0;ii<len;)
	{
		xtcpcb* entry_tcp=(xtcpcb*)((char*)&buf[0]+ii);
		xinpcb* entry_udp=(xinpcb*)((char*)&buf[0]+ii);
		if(proto=="tcp4"&&entry_tcp->xt_inp.inp_vflag&INP_IPV4)
		{
			natstat_t natstat;
			natstat.proto=proto;
			natstat.laddr=u32_to_ipv4(*(uint32_t*)&entry_tcp->xt_inp.inp_laddr);
			natstat.faddr=u32_to_ipv4(*(uint32_t*)&entry_tcp->xt_inp.inp_faddr);
			natstat.lport=u16_to_port(entry_tcp->xt_inp.inp_lport);
			natstat.fport=u16_to_port(entry_tcp->xt_inp.inp_fport);
			natstat.state="ESTABLISHED";
			if(natstat.faddr=="0.0.0.0")
				natstat.state="LISTEN";
			natstat.pid="-";
			for(size_t ii=0;ii<xflen;ii+=sizeof(xfile))
			{
				xfile* xf=(xfile*)((char*)&xfbuf[0]+ii);
				if((void*)entry_tcp->xt_socket.xso_so==xf->xf_data)
				{
					natstat.pid=to_string(xf->xf_pid);
					break;
				}
			}
			if(natstat.pid=="-")
				natstat.state="TIME_WAIT";
			natstats.push_back(natstat);
		}
		if(proto=="udp4"&&entry_udp->xi_inp.inp_vflag&INP_IPV4)
		{
			natstat_t natstat;
			natstat.proto=proto;
			natstat.laddr=u32_to_ipv4(*(uint32_t*)&entry_udp->xi_inp.inp_laddr);
			natstat.faddr="0.0.0.0";
			natstat.lport=u16_to_port(entry_udp->xi_inp.inp_lport);
			natstat.fport=0;
			natstat.state="-";
			natstat.pid="-";
			for(size_t ii=0;ii<xflen;ii+=sizeof(xfile))
			{
				xfile* xf=(xfile*)((char*)&xfbuf[0]+ii);
				if((void*)entry_udp->xi_socket.xso_so==xf->xf_data)
				{
					natstat.pid=to_string(xf->xf_pid);
					break;
				}
			}
			natstats.push_back(natstat);
		}
		#if(defined(AF_INET6))
		if(proto=="tcp6"&&entry_tcp->xt_inp.inp_vflag&INP_IPV6)
		{
			natstat_t natstat;
			natstat.proto=proto;
			natstat.laddr=u8x16_to_ipv6((uint8_t*)&entry_tcp->xt_inp.in6p_laddr);
			natstat.faddr=u8x16_to_ipv6((uint8_t*)&entry_tcp->xt_inp.in6p_faddr);
			natstat.lport=u16_to_port(entry_tcp->xt_inp.inp_lport);
			natstat.fport=u16_to_port(entry_tcp->xt_inp.inp_fport);
			natstat.state="ESTABLISHED";
			if(natstat.faddr=="0000:0000:0000:0000:0000:0000:0000:0000")
				natstat.state="LISTEN";
			natstat.pid="-";
			for(size_t ii=0;ii<xflen;ii+=sizeof(xfile))
			{
				xfile* xf=(xfile*)((char*)&xfbuf[0]+ii);

				if((void*)entry_tcp->xt_socket.xso_so==xf->xf_data)
				{
					natstat.pid=to_string(xf->xf_pid);
					break;
				}
			}
			if(natstat.pid=="-")
				natstat.state="TIME_WAIT";
			natstat.laddr=ipv6_prettify(natstat.laddr);
			natstat.faddr=ipv6_prettify(natstat.faddr);
			natstats.push_back(natstat);
		}
		if(proto=="udp6"&&entry_udp->xi_inp.inp_vflag&INP_IPV6)
		{
			natstat_t natstat;
			natstat.proto=proto;
			natstat.laddr=u8x16_to_ipv6((uint8_t*)&entry_udp->xi_inp.in6p_laddr);
			natstat.faddr="0000:0000:0000:0000:0000:0000:0000:0000";
			natstat.lport=u16_to_port(entry_udp->xi_inp.inp_lport);
			natstat.fport=0;
			natstat.state="-";
			natstat.pid="-";
			for(size_t ii=0;ii<xflen;ii+=sizeof(xfile))
			{
				xfile* xf=(xfile*)((char*)&xfbuf[0]+ii);

				if((void*)entry_udp->xi_socket.xso_so==xf->xf_data)
				{
					natstat.pid=to_string(xf->xf_pid);
					break;
				}
			}
			natstat.laddr=ipv6_prettify(natstat.laddr);
			natstat.faddr=ipv6_prettify(natstat.faddr);
			natstats.push_back(natstat);
		}
		#endif
		ii+=((xinpgen*)((char*)&buf[0]+ii))->xig_len;
	}
	return natstats;
}

natstat_list_t natstat()
{
	natstat_list_t natstats;
	natstat_list_t tcp4=natstat_bsd_parse("tcp4");
	natstat_list_t udp4=natstat_bsd_parse("udp4");
	#if(defined(AF_INET6))
	natstat_list_t tcp6=natstat_bsd_parse("tcp6");
	natstat_list_t udp6=natstat_bsd_parse("udp6");
	#endif
	for(size_t ii=0;ii<tcp4.size();++ii)
		natstats.push_back(tcp4[ii]);
	#if(defined(AF_INET6))
	for(size_t ii=0;ii<tcp6.size();++ii)
		natstats.push_back(tcp6[ii]);
	#endif
	for(size_t ii=0;ii<udp4.size();++ii)
		natstats.push_back(udp4[ii]);
	#if(defined(AF_INET6))
	for(size_t ii=0;ii<udp6.size();++ii)
		natstats.push_back(udp6[ii]);
	#endif
	return natstats;
}