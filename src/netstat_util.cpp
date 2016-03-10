#include "netstat_util.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

void print_human(const netstat_t& netstat)
{
	bool V6=false;
	if(netstat.proto.substr(3,1)=="6")
		V6=true;
	std::ostringstream lstr;
	if(V6)
		lstr<<"["<<netstat.laddr<<"]:"<<netstat.lport;
	else
		lstr<<netstat.laddr<<":"<<netstat.fport;
	std::ostringstream rstr;
	if(V6)
		rstr<<"["<<netstat.faddr<<"]:"<<netstat.fport;
	else
		rstr<<netstat.faddr<<":"<<netstat.fport;
	std::cout<<
		std::setw(5)<<netstat.proto<<
		std::setw(46)<<lstr.str()<<
		std::setw(46)<<rstr.str()<<
		std::setw(16)<<netstat.state<<
		std::setw(8)<<netstat.pid<<
		std::endl;
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

void print_wof(const netstat_t& netstat)
{
	std::cout<<netstat.proto.substr(0,3)<<" ";
	bool V6=false;
	if(netstat.proto.substr(3,1)=="6")
		V6=true;
	if(V6)
		std::cout<<"["<<netstat.laddr<<"]";
	else
		std::cout<<netstat.laddr;
	std::cout<<":"<<netstat.lport;
	if(netstat.state=="ESTABLISHED")
		std::cout<<">";
	else if(netstat.state=="LISTEN")
		std::cout<<"<";
	else if(netstat.proto.substr(0,3)=="udp"&&netstat.state=="-")
		std::cout<<"<>";
	if(V6)
		std::cout<<"["<<netstat.faddr<<"]";
	else
		std::cout<<netstat.faddr;
	std::cout<<":"<<netstat.fport;
	std::cout<<" #pid "<<netstat.pid;
	std::cout<<std::endl;
}

void print_wof(const netstat_list_t& netstats)
{
	for(size_t ii=0;ii<netstats.size();++ii)
		print_wof(netstats[ii]);
}