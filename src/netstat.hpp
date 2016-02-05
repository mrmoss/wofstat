#ifndef NETSTAT_HPP
#define NETSTAT_HPP

#include <stdint.h>
#include <string>
#include <vector>

struct netstat_t
{
	std::string proto;
	std::string local_address;
	std::string foreign_address;
	uint16_t local_port;
	uint16_t foreign_port;
	std::string state;
	std::string pid;
};

typedef std::vector<netstat_t> netstat_list_t;

netstat_list_t netstat();

#endif