#ifndef NETSTAT_UTIL_HPP
#define NETSTAT_UTIL_HPP

#include <string>
#include <vector>

#include "netstat.hpp"

void netstat_print(const netstat_t& netstat);
void netstat_list_print(const netstat_list_t& netstats);

#endif