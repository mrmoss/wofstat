//Tested on:
//	Solaris 10.1 (g++)
//	Solaris 11.2 (g++)

#include "netstat.hpp"

#define	_KMEMUSER 1
#define _KERNEL 1

#include "netstat_util.hpp"
#include "string_util.hpp"

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

#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>
#include <vector>

template<typename T> T kernel_get(kvm_t* kd,const T* kernel_pointer)
{
	T temp;

	if(kvm_read(kd,(uintptr_t)kernel_pointer,&temp,sizeof(T))==-1)
		throw std::runtime_error("Error reading from kernel memory.");

	return temp;
}

std::string kernel_get_size(kvm_t* kd,const void* kernel_pointer,const size_t size)
{
	std::string buf;
	buf.resize(size+2);

	if(kvm_read(kd,(uintptr_t)kernel_pointer,(void*)buf.c_str(),size)==-1)
		throw std::runtime_error("Error reading from kernel memory.");

	return buf;
}

netstat_list_t netstat()
{
	char err[4096];
	kvm_t* kd=kvm_open(NULL,NULL,NULL,O_RDONLY,err);

	if(kd==NULL)
	{
		std::cout<<"Could not open kernel virtual memory."<<std::endl;
		throw std::runtime_error("IOAHDJOIFJSDOIFDJS");
	}

	netstat_list_t netstats;

	while(true)
	{
		proc_t* proc=kvm_nextproc(kd);

		if(proc==NULL)
			break;

		pid_t pid=kernel_get(kd,proc->p_pidp).pid_id;

		user_t* user=&proc->p_user;
		size_t num_entries=user->u_finfo.fi_nfiles;

		for(size_t ii=0;ii<num_entries;++ii)
		{
			uf_entry_t entry=kernel_get(kd,user->u_finfo.fi_list+ii);

			if(entry.uf_file!=NULL)
			{
				file_t file=kernel_get(kd,entry.uf_file);
				vnode_t vnode=kernel_get(kd,file.f_vnode);

				//if(vnode.v_type==VSOCK||vnode.v_type==VCHR)
				{
					try
					{
					netstat_t netstat;
					sonode sn=kernel_get(kd,(sonode*)(vnode.v_data));
					netstat.pid=to_string(pid);
					netstat.local_port="0";
					netstat.foreign_port="0";
					netstat.state="-";
					sockaddr local_addr_raw=kernel_get(kd,sn.so_laddr.soa_sa);

					if(sn.so_type==SOCK_STREAM)
						netstat.proto="tcp";
					else if(sn.so_type==SOCK_DGRAM)
						netstat.proto="udp";
					else
						continue;

					if(local_addr_raw.sa_family==AF_INET)
					{
						netstat.proto+="4";
						sockaddr_in local_addr=*(sockaddr_in*)&local_addr_raw;
						netstat.local_address=uint32_t_to_ipv4(local_addr.sin_addr.s_addr);
						netstat.local_port=uint16_t_to_port(local_addr.sin_port);
					}
					#if(defined(AF_INET6))
					else if(local_addr_raw.sa_family==AF_INET6)
					{
						netstat.proto+="6";
						sockaddr_in6 local_addr=*(sockaddr_in6*)&local_addr_raw;
						netstat.local_address=uint8_t_16_to_ipv6(local_addr.sin6_addr.s6_addr);
						netstat.local_port=uint16_t_to_port(local_addr.sin6_port);
					}
					#endif
					else
					{
						continue;
					}

					if(sn.so_type==SOCK_STREAM)
					{
						sockaddr foreign_addr_raw=kernel_get(kd,sn.so_faddr.soa_sa);
						if(netstat.proto[3]=='4')
						{
							sockaddr_in foreign_addr=*(sockaddr_in*)&foreign_addr_raw;
							netstat.foreign_address=uint32_t_to_ipv4(foreign_addr.sin_addr.s_addr);
							netstat.foreign_port=uint16_t_to_port(foreign_addr.sin_port);
						}
						#if(defined(AF_INET6))
						else if(netstat.proto[3]=='6')
						{
							sockaddr_in6 foreign_addr=*(sockaddr_in6*)&foreign_addr_raw;
							netstat.foreign_address=uint8_t_16_to_ipv6(foreign_addr.sin6_addr.s6_addr);
							netstat.foreign_port=uint16_t_to_port(foreign_addr.sin6_port);
						}
						#endif
					}

					netstats.push_back(netstat);
					}
					catch(...)
					{
					}
				}
			}
		}
	}

	kvm_close(kd);

	return netstats;
}
