#ifndef NETSTAT_HPP
#define NETSTAT_HPP

#include <stdint.h>
#include <string>
#include <vector>

struct netstat_t
{
	std::string proto;
	std::string laddr;
	std::string faddr;
	uint16_t lport;
	uint16_t fport;
	std::string state;
	std::string pid;
};

typedef std::vector<netstat_t> netstat_list_t;

netstat_list_t netstat();

#endif