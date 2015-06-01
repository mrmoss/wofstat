#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>
#include <vector>
#include <stdexcept>

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/socketvar.h>

#include <netinet/in.h>
#include <netinet/in_pcb.h>

#include <netinet/ip.h>
#include <netinet/ip_var.h>

#include <netinet/tcp.h>
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_var.h>

std::string uint32_t_to_ipv4(const uint32_t address)
{
	std::ostringstream ostr;
	ostr<<(uint32_t)((uint8_t*)&address)[0]<<"."<<
		(uint32_t)((uint8_t*)&address)[1]<<"."<<
		(uint32_t)((uint8_t*)&address)[2]<<"."<<
		(uint32_t)((uint8_t*)&address)[3];
	return ostr.str();
}

std::string in6_addr_to_ipv6(const in6_addr& address)
{
	uint8_t* addr=(uint8_t*)&address;

	std::ostringstream ostr;
	for(int ii=0;ii<16;ii+=2)
	{
		ostr<<std::hex<<std::setw(2)<<std::setfill('0')<<(unsigned int)(unsigned char)addr[ii+0];
		ostr<<std::hex<<std::setw(2)<<std::setfill('0')<<(unsigned int)(unsigned char)addr[ii+1];

		if(ii<14)
			ostr<<":";
	}

	return ostr.str();
}

std::string uint16_t_to_port(const uint16_t port)
{
	std::ostringstream ostr;
	ostr<<((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
	return ostr.str();
}

struct netstat_t
{
	std::string proto;
	std::string local_address;
	std::string foreign_address;
	std::string local_port;
	std::string foreign_port;
	std::string state;
	std::string inode;
	std::string pid;
};

typedef std::vector<netstat_t> netstat_list_t;

void netstat_print(const netstat_t& netstat)
{
	std::cout<<
		std::setw(4)<<netstat.proto<<" "<<
		std::setw(64)<<netstat.local_address+":"+netstat.local_port<<" "<<
		std::setw(64)<<netstat.foreign_address+":"+netstat.foreign_port<<" "<<
		std::setw(16)<<netstat.state<<" "<<
		std::setw(8)<<netstat.pid<<" "<<
		std::endl;
}

void netstat_list_print(const netstat_list_t& netstats)
{
	std::cout<<
		std::setw(4)<<"proto "<<
		std::setw(64)<<"local_address "<<
		std::setw(64)<<"foreign_address "<<
		std::setw(16)<<"state "<<
		std::setw(8)<<"pid "<<
		std::endl;

	for(size_t ii=0;ii<netstats.size();++ii)
			netstat_print(netstats[ii]);
}

netstat_list_t netstat_bsd_parse(const std::string& proto)
{
	netstat_list_t netstats;

	size_t len=0;
	std::string sysctl_path="";

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

	char* buf=(char*)malloc(len);

	if(sysctlbyname(sysctl_path.c_str(),buf,&len,NULL,0)==-1)
		throw std::runtime_error("error getting data.");

	for(size_t ii=0;ii<len;)
	{
		xtcpcb* entry=(xtcpcb*)(buf+ii);

		if(proto=="tcp4"&&entry->xt_inp.inp_vflag&INP_IPV4)
		{
			netstat_t netstat;
			netstat.proto=proto;
			netstat.local_address=uint32_t_to_ipv4(*(uint32_t*)&entry->xt_inp.inp_laddr);
			netstat.foreign_address=uint32_t_to_ipv4(*(uint32_t*)&entry->xt_inp.inp_faddr);
			netstat.local_port=uint16_t_to_port(entry->xt_inp.inp_lport);
			netstat.foreign_port=uint16_t_to_port(entry->xt_inp.inp_fport);
			netstat.state="UNKNOWN";
			netstat.pid="-";
			netstats.push_back(netstat);
		}

		if(proto=="udp4"&&entry->xt_inp.inp_vflag&INP_IPV4)
		{
			netstat_t netstat;
			netstat.proto=proto;
			netstat.local_address=uint32_t_to_ipv4(*(uint32_t*)&entry->xt_inp.inp_laddr);
			netstat.foreign_address="0.0.0.0";
			netstat.local_port=uint16_t_to_port(entry->xt_inp.inp_lport);
			netstat.foreign_port="0";
			netstat.state="ESTABLISHED";

				if(netstat.foreign_address=="0.0.0.0")
					netstat.state="LISTEN";

			netstat.pid="-";
			netstats.push_back(netstat);
		}

		#if(defined(AF_INET6))
			if(proto=="tcp6"&&entry->xt_inp.inp_vflag&INP_IPV6)
			{
				netstat_t netstat;
				netstat.proto=proto;
				netstat.local_address=in6_addr_to_ipv6(entry->xt_inp.in6p_laddr);
				netstat.foreign_address=in6_addr_to_ipv6(entry->xt_inp.in6p_faddr);
				netstat.local_port=uint16_t_to_port(entry->xt_inp.inp_lport);
				netstat.foreign_port=uint16_t_to_port(entry->xt_inp.inp_fport);
				netstat.state="ESTABLISHED";

				if(netstat.foreign_address=="0000:0000:0000:0000:0000:0000:0000:0000")
					netstat.state="LISTEN";

				netstat.pid="-";
				netstats.push_back(netstat);
			}

			if(proto=="udp6"&&entry->xt_inp.inp_vflag&INP_IPV6)
			{
				netstat_t netstat;
				netstat.proto=proto;
				netstat.local_address=in6_addr_to_ipv6(entry->xt_inp.in6p_laddr);
				netstat.foreign_address="0000:0000:0000:0000:0000:0000:0000:0000";
				netstat.local_port=uint16_t_to_port(entry->xt_inp.inp_lport);
				netstat.foreign_port="0";
				netstat.state="-";
				netstat.pid="-";
				netstats.push_back(netstat);
			}
		#endif

		ii+=((xinpgen*)(buf+ii))->xig_len;
	}

	free(buf);
	return netstats;
}

netstat_list_t netstat_bsd()
{
	netstat_list_t netstats;
	netstat_list_t tcp4=netstat_bsd_parse("tcp4");
	netstat_list_t udp4=netstat_bsd_parse("udp4");

	#if(defined(AF_INET6))
		netstat_list_t tcp6=netstat_bsd_parse("tcp6");
		netstat_list_t udp6=netstat_bsd_parse("udp6");
	#endif

	for(size_t ii=0;ii<tcp4.size();++ii)
		netstats.push_back(tcp4[ii]);

	#if(defined(AF_INET6))
		for(size_t ii=0;ii<tcp6.size();++ii)
			netstats.push_back(tcp6[ii]);
	#endif

	for(size_t ii=0;ii<udp4.size();++ii)
		netstats.push_back(udp4[ii]);

	#if(defined(AF_INET6))
		for(size_t ii=0;ii<udp6.size();++ii)
			netstats.push_back(udp6[ii]);
	#endif

	return netstats;
}

int main()
{
	netstat_list_print(netstat_bsd());
	return 0;
}
