#ifndef NETSTAT_UTIL_HPP
#define NETSTAT_UTIL_HPP

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

void netstat_print(const netstat_t& netstat);
void netstat_list_print(const netstat_list_t& netstats);

#endif