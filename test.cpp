#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/proc_info.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <pwd.h>
#include <iostream>
#include <libproc.h>

int main()
{
	int name[]={CTL_KERN,KERN_PROC,KERN_PROC_ALL};
	size_t len=0;

	if(sysctl(name,3,NULL,&len,NULL,0)!=0)
		throw std::runtime_error("ERROR 0");

	kinfo_proc* procs=(kinfo_proc*)malloc(len);
	if(procs==NULL)
		throw std::runtime_error("ERROR 0");

	if(sysctl(name,3,procs,&len,NULL,0)!=0)
	{
		free(procs);
		throw std::runtime_error("ERROR 0");
	}

	len=len/sizeof(struct kinfo_proc);

	for(size_t ii=0;ii<len;++ii)
	{
		int num_procs=proc_pidinfo(procs[ii].kp_proc.p_pid,PROC_PIDLISTFDS,0,NULL,0);

		if(num_procs<=0)
			continue;

		proc_fdinfo* files=(proc_fdinfo*)malloc(num_procs);
		if(files==NULL)
			continue;

		num_procs=proc_pidinfo(procs[ii].kp_proc.p_pid,PROC_PIDLISTFDS,0,files,num_procs);
		if(num_procs<0)
		{
			free(files);
			continue;
		}

		int count=0;

		for(size_t jj=0;jj<(num_procs/PROC_PIDLISTFD_SIZE);++jj)
		{
			if(files[jj].proc_fdtype==PROX_FDTYPE_SOCKET)
			{
				socket_fdinfo si;

				int test=proc_pidfdinfo(procs[ii].kp_proc.p_pid,files[jj].proc_fd,
					PROC_PIDFDSOCKETINFO,&si,sizeof(si));

				if(test<=0)
					continue;

				if(si.psi.soi_family==AF_INET||si.psi.soi_family==AF_INET6)
				{
						std::cout<<"\t";

						if(si.psi.soi_type==SOCK_STREAM)
							std::cout<<"tcp\t";
						if(si.psi.soi_type==SOCK_DGRAM)
							std::cout<<"udp\t";

						std::cout<<
							ntohs(si.psi.soi_proto.pri_tcp.tcpsi_ini.insi_lport)<<"\t"<<
							ntohs(si.psi.soi_proto.pri_tcp.tcpsi_ini.insi_fport)<<std::endl;

					++count;
				}
			}
		}

		free(files);

		if(count>0)
			std::cout<<procs[ii].kp_proc.p_pid<<"\t"<<count<<std::endl;
	}

	free(procs);

	return 0;
}











/*
if (family == AF_INET) {
	inet_ntop(AF_INET,
			  &si.psi.soi_proto.pri_tcp.tcpsi_ini. \
				  insi_laddr.ina_46.i46a_addr4,
			  lip,
			  sizeof(lip));
	inet_ntop(AF_INET,
			  &si.psi.soi_proto.pri_tcp.tcpsi_ini.insi_faddr. \
				  ina_46.i46a_addr4,
			  rip,
			  sizeof(rip));
}
else {
	inet_ntop(AF_INET6,
			  &si.psi.soi_proto.pri_tcp.tcpsi_ini. \
				  insi_laddr.ina_6,
			  lip, sizeof(lip));
	inet_ntop(AF_INET6,
			  &si.psi.soi_proto.pri_tcp.tcpsi_ini. \
				  insi_faddr.ina_6,
			  rip, sizeof(rip));
}
*/