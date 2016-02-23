#include "netstat_util.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

void netstat_print(const netstat_t& netstat)
{
	std::ostringstream lstr;
	lstr<<netstat.laddr+":"<<netstat.lport;

	std::ostringstream rstr;
	rstr<<netstat.faddr+":"<<netstat.fport;

	std::cout<<
		std::setw(4)<<netstat.proto<<" "<<
		std::setw(46)<<lstr.str()<<" "<<
		std::setw(46)<<rstr.str()<<" "<<
		std::setw(16)<<netstat.state<<" "<<
		std::setw(8)<<netstat.pid<<" "<<
		std::endl;
}

void netstat_list_print(const netstat_list_t& netstats)
{
	std::cout<<
		std::setw(4)<<"proto "<<
		std::setw(46)<<"local address "<<
		std::setw(46)<<"foreign address "<<
		std::setw(16)<<"state "<<
		std::setw(8)<<"pid "<<
		std::endl;

	for(size_t ii=0;ii<netstats.size();++ii)
			netstat_print(netstats[ii]);
}
