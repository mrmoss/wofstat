#include <iostream>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

int main()
{
	int tcp_sack[]={CTL_NET,NET_IPV4,NET_IPV4_TCP_SACK};
	int curr;
	size_t curr_size=sizeof(curr);

	std::cout<<sysctl(tcp_sack,3,&curr,&curr_size,0,0)<<std::endl;
	std::cout<<curr<<"\t"<<curr_size<<std::endl;

	return 0;
}