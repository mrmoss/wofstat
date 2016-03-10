#include "natstat_util.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

void print_human(const natstat_t& natstat)
{
	bool V6=false;
	if(natstat.proto.substr(3,1)=="6")
		V6=true;
	std::ostringstream lstr;
	if(V6)
		lstr<<"["<<natstat.laddr<<"]:"<<natstat.lport;
	else
		lstr<<natstat.laddr<<":"<<natstat.fport;
	std::ostringstream rstr;
	if(V6)
		rstr<<"["<<natstat.faddr<<"]:"<<natstat.fport;
	else
		rstr<<natstat.faddr<<":"<<natstat.fport;
	std::cout<<
		std::setw(5)<<natstat.proto<<
		std::setw(46)<<lstr.str()<<
		std::setw(46)<<rstr.str()<<
		std::setw(16)<<natstat.state<<
		std::setw(8)<<natstat.pid<<
		std::endl;
}

void print_human(const natstat_list_t& natstats)
{
	std::cout<<
		std::setw(5)<<"proto"<<
		std::setw(46)<<"local address"<<
		std::setw(46)<<"foreign address"<<
		std::setw(16)<<"state"<<
		std::setw(8)<<"pid"<<
		std::endl;
	for(size_t ii=0;ii<natstats.size();++ii)
			print_human(natstats[ii]);
}

void print_wof(const natstat_t& natstat)
{
	std::cout<<natstat.proto.substr(0,3)<<" ";
	bool V6=false;
	if(natstat.proto.substr(3,1)=="6")
		V6=true;
	if(V6)
		std::cout<<"["<<natstat.laddr<<"]";
	else
		std::cout<<natstat.laddr;
	std::cout<<":"<<natstat.lport;
	if(natstat.state=="ESTABLISHED")
		std::cout<<">";
	else if(natstat.state=="LISTEN")
		std::cout<<"<";
	else if(natstat.proto.substr(0,3)=="udp"&&natstat.state=="-")
		std::cout<<"<>";
	if(V6)
		std::cout<<"["<<natstat.faddr<<"]";
	else
		std::cout<<natstat.faddr;
	std::cout<<":"<<natstat.fport;
	std::cout<<" #pid "<<natstat.pid;
	std::cout<<std::endl;
}

void print_wof(const natstat_list_t& natstats)
{
	for(size_t ii=0;ii<natstats.size();++ii)
		print_wof(natstats[ii]);
}