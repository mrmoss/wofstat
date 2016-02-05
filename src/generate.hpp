#ifndef GENFIREWALL_HPP
#define GENFIREWALL_HPP

#include <string>
#include "netstat.hpp"

std::string generate_iptables(const netstat_list_t& netstats);

#endif