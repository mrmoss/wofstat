#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>

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

//pcblist

std::string uint32_t_to_ipv4(const uint32_t address)
{
	std::ostringstream ostr;
	ostr<<(uint32_t)((uint8_t*)&address)[0]<<"."<<
		(uint32_t)((uint8_t*)&address)[1]<<"."<<
		(uint32_t)((uint8_t*)&address)[2]<<"."<<
		(uint32_t)((uint8_t*)&address)[3];
	return ostr.str();
}

std::string uint16_t_to_port(const uint16_t port)
{
	std::ostringstream ostr;
	ostr<<((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
	return ostr.str();
}

int main()
{
	size_t len=0;

	if(sysctlbyname("net.inet.tcp.pcblist",NULL,&len,NULL,0)==-1)
	{
		std::cout<<"error getting data size"<<std::endl;
		return 1;
	}

	char* buf=(char*)malloc(len);

	if(sysctlbyname("net.inet.tcp.pcblist",buf,&len,NULL,0)==-1)
	{
		std::cout<<"error getting data"<<std::endl;
		return 1;
	}

	for(size_t ii=0;ii<len;)
	{
		xtcpcb* entry=(xtcpcb*)(buf+ii);

		if(entry->xt_inp.inp_vflag&INP_IPV4)
		{
			std::cout<<
				uint32_t_to_ipv4(*(uint32_t*)&entry->xt_inp.inp_laddr)<<
				":"<<
				uint16_t_to_port(entry->xt_inp.inp_lport)<<
				"\t"<<
				uint32_t_to_ipv4(*(uint32_t*)&entry->xt_inp.inp_faddr)<<
				":"<<
				uint16_t_to_port(entry->xt_inp.inp_fport)<<
				std::endl;
		}

		ii+=((xinpgen*)(buf+ii))->xig_len;
	}

	free(buf);

	return 0;
}
