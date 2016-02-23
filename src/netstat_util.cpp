#include "netstat_util.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

void print_human(const netstat_t& netstat)
{
	std::ostringstream lstr;
	lstr<<netstat.laddr+":"<<netstat.lport;
	std::ostringstream rstr;
	rstr<<netstat.faddr+":"<<netstat.fport;
	std::cout<<
		std::setw(5)<<netstat.proto<<
		std::setw(46)<<lstr.str()<<
		std::setw(46)<<rstr.str()<<
		std::setw(16)<<netstat.state<<
		std::setw(8)<<netstat.pid<<
		std::endl;
}

void print_json(const netstat_t& netstat)
{
	std::cout<<"{"<<
		"\"proto\":\""<<netstat.proto<<"\","<<
		"\"laddr\":\""<<netstat.laddr<<"\","<<
		"\"faddr\":\""<<netstat.faddr<<"\","<<
		"\"lport\":"<<netstat.lport<<","<<
		"\"fport\":"<<netstat.fport<<","<<
		"\"state\":\""<<netstat.state<<"\","<<
		"\"pid\":\""<<netstat.pid<<"\""<<
		"}";
}

void print_human(const netstat_list_t& netstats)
{
	std::cout<<
		std::setw(5)<<"proto"<<
		std::setw(46)<<"local address"<<
		std::setw(46)<<"foreign address"<<
		std::setw(16)<<"state"<<
		std::setw(8)<<"pid"<<
		std::endl;
	for(size_t ii=0;ii<netstats.size();++ii)
			print_human(netstats[ii]);
}

void print_json(const netstat_list_t& netstats)
{
	std::cout<<"[";
	for(size_t ii=0;ii<netstats.size();++ii)
	{
		print_json(netstats[ii]);
		if(ii+1<netstats.size())
			std::cout<<",";
	}
	std::cout<<"]"<<std::endl;
}