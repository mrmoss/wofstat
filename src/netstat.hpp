#ifndef NETSTAT_HPP
#define NETSTAT_HPP

#include <string>
#include <vector>

struct netstat_t
{
	std::string proto;
	std::string local_address;
	std::string foreign_address;
	std::string local_port;
	std::string foreign_port;
	std::string state;
	std::string inode;
	std::string pid;
};

typedef std::vector<netstat_t> netstat_list_t;

netstat_list_t netstat();

#endif