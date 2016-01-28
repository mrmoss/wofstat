//http://www.solarisinternals.com/si/sample/solaris_internals_ch14_file_system_framework.pdf
//http://www.solarisinternals.com/si/reading/vnode.pdf
//http://www.brendangregg.com/DTrace/socketsnoop.d

//compile with:
//	g++ testing.cpp -lkvm -lelf -lnsl -lsocket -m64

#define	_KMEMUSER 1
#define _KERNEL 1

#include <kvm.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/param.h>
#include <sys/proc.h>
#include <sys/segments.h>
#include <sys/vnode.h>
#include <sys/strsubr.h>
#include <sys/sysmacros.h>
#include <sys/systm.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/vnode.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/strsubr.h>
#include <sys/sysmacros.h>
#include <sys/systm.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/vnode.h>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <stdint.h>
#include <vector>

static const size_t states_size=11;
static const std::string states[states_size]=
{
	"CLOSED",
	"LISTEN",
	"SYN_SENT",
	"SYN_RECV",
	"ESTABLISHED",
	"CLOSE_WAIT",
	"FIN_WAIT1",
	"CLOSING",
	"LAST_ACK",
	"FIN_WAIT2",
	"TIME_WAIT"
};

std::string to_string(const uint32_t val)
{
	std::ostringstream ostr;
	ostr<<val;
	return ostr.str();
}

std::string uint32_t_to_ipv4(const uint32_t address)
{
	std::ostringstream ostr;
	ostr<<(uint32_t)((uint8_t*)&address)[0]<<"."<<
		(uint32_t)((uint8_t*)&address)[1]<<"."<<
		(uint32_t)((uint8_t*)&address)[2]<<"."<<
		(uint32_t)((uint8_t*)&address)[3];
	return ostr.str();
}

std::string uint8_t_16_to_ipv6(const uint8_t address[16])

{
	std::ostringstream ostr;

	for(int ii=0;ii<16;ii+=2)
	{
		ostr<<std::hex<<std::setw(2)<<std::setfill('0')<<(unsigned int)(unsigned char)address[ii+0];
		ostr<<std::hex<<std::setw(2)<<std::setfill('0')<<(unsigned int)(unsigned char)address[ii+1];

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
	std::string pid;
};

template<typename T> T kernel_get(kvm_t* kd,const T* kernel_pointer)
{
	T temp;

	if(kvm_read(kd,(uintptr_t)kernel_pointer,&temp,sizeof(T))==-1)
		throw std::runtime_error("Error reading from kernel memory.");

	return temp;
}

int main()
{
	char err[4096];
	kvm_t* kd=kvm_open(NULL,NULL,NULL,O_RDONLY,err);

	if(kd==NULL)
	{
		std::cout<<"Could not open kernel virtual memory."<<std::endl;
		return 1;
	}

	std::vector<netstat_t> netstats;

	while(true)
	{
		proc_t* proc=kvm_nextproc(kd);

		if(proc==NULL)
			break;

		pid_t pid=kernel_get(kd,proc->p_pidp).pid_id;

		user_t* user=&proc->p_user;
		size_t num_entries=user->u_finfo.fi_nfiles;
		size_t socket_count=0;

		for(size_t ii=0;ii<num_entries;++ii)
		{
			uf_entry_t entry=kernel_get(kd,user->u_finfo.fi_list+ii);

			if(entry.uf_file!=NULL)
			{
				file_t file=kernel_get(kd,entry.uf_file);
				vnode_t vnode=kernel_get(kd,file.f_vnode);

				if(vnode.v_type==VSOCK)
				{
					netstat_t netstat;
					//AF_INET or PF_INET???
					sonode sn=kernel_get(kd,(sonode*)(vnode.v_data));

					if(sn.so_type==SOCK_STREAM)
						netstat.proto="tcp";
					else if(sn.so_type==SOCK_DGRAM)
						netstat.proto="udp";
					else
						continue;

					if(sn.so_family==PF_INET)
					{
						netstat.proto+="4";
						netstat.local_address=uint32_t_to_ipv4(0);
						netstat.foreign_address=uint32_t_to_ipv4(0);
					}
					#if(defined(AF_INET6))
					else if(sn.so_family==PF_INET6)
					{
						netstat.proto+="6";
						netstat.local_address="0000:0000:0000:0000:0000:0000:0000:0000";
						netstat.foreign_address="0000:0000:0000:0000:0000:0000:0000:0000";
					}
					#endif
					else
					{
						continue;
					}

					netstat.pid=to_string(pid);
					netstat.local_port="0";
					netstat.foreign_port="0";
					netstat.state="-";

					sockaddr local_addr=kernel_get(kd,sn.so_laddr.soa_sa);
					netstat.local_port=uint16_t_to_port(*(uint16_t*)local_addr.sa_data);

					if(netstat.proto[3]=='4')
						netstat.local_address=uint32_t_to_ipv4(*(uint32_t*)(local_addr.sa_data+2));
					else
						netstat.local_address=uint8_t_16_to_ipv6((const uint8_t*)(local_addr.sa_data+2));

					if(sn.so_type==SOCK_STREAM)
					{
						if(sn.so_state<0&&sn.so_state>states_size)
							continue;

						//netstat.state=states[sn.so_state];
						sockaddr foreign_addr=kernel_get(kd,sn.so_faddr.soa_sa);
						netstat.foreign_port=uint16_t_to_port(*(uint16_t*)foreign_addr.sa_data);

						if(netstat.proto[3]=='4')
							netstat.foreign_address=uint32_t_to_ipv4(*(uint32_t*)(local_addr.sa_data+2+4));
						else
							netstat.foreign_address=uint8_t_16_to_ipv6((const uint8_t*)(foreign_addr.sa_data+2));
					}

					netstats.push_back(netstat);
				}
			}
		}
	}

	kvm_close(kd);

	for(size_t ii=0;ii<netstats.size();++ii)
		std::cout<<netstats[ii].pid<<"\t"<<netstats[ii].proto<<"\t"<<netstats[ii].local_address<<":"<<netstats[ii].local_port<<"\t"<<netstats[ii].foreign_address<<":"<<netstats[ii].foreign_port<<std::endl;

	return 0;
}
