//http://www.solarisinternals.com/si/sample/solaris_internals_ch14_file_system_framework.pdf
//http://www.solarisinternals.com/si/reading/vnode.pdf
//http://www.brendangregg.com/DTrace/socketsnoop.d

//compile with:
//	g++ testing.cpp -lkvm -lelf -lnsl -lsocket -m64

#define	_KMEMUSER 1

#include <kvm.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/param.h>
#include <sys/proc.h>
#include <sys/segments.h>
#include <sys/strsubr.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/vnode.h>

#include <iostream>
#include <stdexcept>

template<typename T> T kernel_get(kvm_t* kd,const T* kernel_pointer)
{
	T temp;

	if(kvm_read(kd,(uintptr_t)kernel_pointer,&temp,sizeof(T))==-1)
		throw std::runtime_error("Error reading from kernel memory.");

	return temp;
}

void search_it(kvm_t* kd,void* data,const size_t size)
{
	if(data==NULL||size<2)
		return;

	//std::cout<<"\t\tlooking for port"<<std::endl;

	for(size_t ii=0;ii<size-1;++ii)
	{
		unsigned char* bp0=(unsigned char*)data+ii+0;
		unsigned char* bp1=(unsigned char*)data+ii+1;

		unsigned char b0=kernel_get(kd,bp0);
		unsigned char b1=kernel_get(kd,bp1);

		if(b0==0x63&&b1==0x17)
			std::cout<<"FOUND PORT LE"<<std::endl;
		if(b1==0x63&&b0==0x17)
			std::cout<<"FOUND PORT BE"<<std::endl;
	}

	if(data==NULL||size<4)
		return;

	//std::cout<<"\t\tlooking for ip"<<std::endl;

	for(size_t ii=0;ii<size-3;++ii)
	{
		unsigned char* bp0=(unsigned char*)data+ii+0;
		unsigned char* bp1=(unsigned char*)data+ii+1;
		unsigned char* bp2=(unsigned char*)data+ii+2;
		unsigned char* bp3=(unsigned char*)data+ii+3;

		unsigned char b0=kernel_get(kd,bp0);
		unsigned char b1=kernel_get(kd,bp1);
		unsigned char b2=kernel_get(kd,bp2);
		unsigned char b3=kernel_get(kd,bp3);
//10.0.2.15
		if(b0==127&&b1==0&&b2==0&&b3==1)
			std::cout<<"FOUND IP LE"<<std::endl;
		if(b3==127&&b2==0&&b1==0&&b0==1)
			std::cout<<"FOUND IP BE"<<std::endl;
	}
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

	std::cout<<"opened"<<std::endl;

	int data;

	for(uint64_t jj=0;jj<0xffffffffffffffff;++jj)
		if(kvm_read(kd,0+jj,&data,4)==4)
			if(data==0x7f000001||data==0x0100007f)
				std::cout<<"Found it at "<<jj<<std::endl;

/*
	while(true)
	{
		proc_t* proc=kvm_nextproc(kd);

		if(proc==NULL)
			break;

		for(int jj=0;jj<30;++jj)
		{
			int vtest=kernel_get(kd,(int*)kd+jj);
			char* vtest2=(char*)&vtest;

			if(vtest2[jj]==127&&vtest2[jj+1]==0&&vtest2[jj+2]==0&&vtest2[jj+3]==1)
			{
				std::cout<<"FOUND IT1"<<std::endl;
			}
			if(vtest2[jj+3]==127&&vtest2[jj+2]==0&&vtest2[jj+1]==0&&vtest2[jj]==1)
			{
				std::cout<<"FOUND IT2"<<std::endl;
			}
		}

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
				char* vtest=(char*)&(vnode);

				for(int jj=0;jj<100;++jj)
				{
					if(vtest[jj]==127&&vtest[jj+1]==0&&vtest[jj+2]==0&&vtest[jj+3]==1)
					{
						std::cout<<"FOUND IT1"<<std::endl;
					}
					if(vtest[jj+3]==127&&vtest[jj+2]==0&&vtest[jj+1]==0&&vtest[jj]==1)
					{
						std::cout<<"FOUND IT2"<<std::endl;
					}
				}

				if(vnode.v_type==VSOCK)
				{
					++socket_count;
					search_it(kd,user->u_finfo.fi_list+ii,1000);
					search_it(kd,entry.uf_file,1000);
					search_it(kd,file.f_vnode,1000);
					search_it(kd,vnode.v_stream,1000);
					search_it(kd,vnode.v_vfsp,1000);
					search_it(kd,vnode.v_data,1000);//no idea what this is...random number...
				}
			}
		}

		if(socket_count>0)
			std::cout<<pid<<"\t"<<socket_count<<std::endl;
	}*/

	kvm_close(kd);

	return 0;
}
