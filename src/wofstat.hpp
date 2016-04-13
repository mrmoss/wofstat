#ifndef WOFSTAT_HPP
#define WOFSTAT_HPP

#include <stdint.h>
#include <string>
#include <vector>

struct wofstat_t
{
	std::string proto;
	std::string laddr;
	std::string faddr;
	uint16_t lport;
	uint16_t fport;
	std::string state;
	std::string pid;
};

bool operator==(const wofstat_t& lhs,const wofstat_t& rhs);

typedef std::vector<wofstat_t> wofstat_list_t;

wofstat_list_t wofstat();

void print_human(const wofstat_t& wofstat,std::vector<size_t> cols=std::vector<size_t>());
void print_human(const wofstat_list_t& wofstats,bool print_header=true);
void print_wof(const wofstat_t& wofstat);
void print_wof(const wofstat_list_t& wofstats);

#endif