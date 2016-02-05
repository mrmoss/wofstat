#include <iostream>
#include "generate.hpp"

int main()
{
	std::cout<<generate_iptables(netstat())<<std::flush;
	return 0;
}