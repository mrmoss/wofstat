#include <iostream>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

int main()
{
	int mib[]={CTL_NET,PF_ROUTE,0,0,NET_RT_IFLIST2,0};
	size_t len;
	std::cout<<sysctl(mib,6,NULL,&len,NULL,0)<<"\t"<<len<<std::endl;
	return 0;
}