#ifndef NATSTAT_UTIL_HPP
#define NATSTAT_UTIL_HPP

#include <string>
#include <vector>

#include "natstat.hpp"

void print_human(const natstat_t& natstat);
void print_human(const natstat_list_t& natstats);
void print_wof(const natstat_t& natstat);
void print_wof(const natstat_list_t& natstats);

#endif