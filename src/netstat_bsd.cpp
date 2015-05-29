#include <iostream>
#include <sys/sysctl.h>
#include <sys/socket.h>

#define PF_LIST_INET	1

#ifdef INET6
	#define PF_LIST_INET6	2
#endif

int main()
{
	int mib[]={CTL_NET,PF_LIST_INET,0,0,0,0};
	size_t len;
	std::cout<<sysctl(mib,6,NULL,&len,NULL,0)<<"\t"<<len<<std::endl;
	return 0;
}