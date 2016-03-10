#ifndef NETSTAT_UTIL_HPP
#define NETSTAT_UTIL_HPP

#include <string>
#include <vector>

#include "netstat.hpp"

void print_human(const netstat_t& netstat);
void print_human(const netstat_list_t& netstats);
void print_wof(const netstat_t& netstat);
void print_wof(const netstat_list_t& netstats);

#endif