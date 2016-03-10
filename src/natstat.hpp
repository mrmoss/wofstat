#ifndef NATSTAT_HPP
#define NATSTAT_HPP

#include <stdint.h>
#include <string>
#include <vector>

struct natstat_t
{
	std::string proto;
	std::string laddr;
	std::string faddr;
	uint16_t lport;
	uint16_t fport;
	std::string state;
	std::string pid;
};

typedef std::vector<natstat_t> natstat_list_t;

natstat_list_t natstat();

#endif