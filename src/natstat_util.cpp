#include "natstat_util.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

void print_human(const natstat_t& natstat,std::vector<size_t> cols)
{
	if(cols.size()<4)
	{
		cols.clear();
		cols.push_back(5);
		cols.push_back(46);
		cols.push_back(46);
		cols.push_back(16);
		cols.push_back(8);
	}
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
		std::setw(cols[0])<<natstat.proto<<
		std::setw(cols[1])<<lstr.str()<<
		std::setw(cols[2])<<rstr.str()<<
		std::setw(cols[3])<<natstat.state<<
		std::setw(cols[4])<<natstat.pid<<
		std::endl;
}

void print_human(const natstat_list_t& natstats)
{
	size_t pad=1;
	std::vector<size_t> cols;
	cols.push_back(5+pad);
	cols.push_back(15+pad);
	cols.push_back(15+pad);
	cols.push_back(5+pad);
	cols.push_back(3+pad);
	for(size_t ii=0;ii<natstats.size();++ii)
	{
		if(natstats[ii].proto.size()+pad>cols[0])
			cols[0]=natstats[ii].proto.size()+pad;
		if(natstats[ii].laddr.size()+7+pad>cols[1])
			cols[1]=natstats[ii].laddr.size()+7+pad;
		if(natstats[ii].faddr.size()+7>cols[2])
			cols[2]=natstats[ii].faddr.size()+7+pad;
		if(natstats[ii].state.size()+pad>cols[3])
			cols[3]=natstats[ii].state.size()+pad;
		if(natstats[ii].pid.size()+pad>cols[4])
			cols[4]=natstats[ii].pid.size()+pad;
	}
	std::cout<<
		std::setw(cols[0])<<"proto"<<
		std::setw(cols[1])<<"local address"<<
		std::setw(cols[2])<<"foreign address"<<
		std::setw(cols[3])<<"state"<<
		std::setw(cols[4])<<"pid"<<
		std::endl;
	for(size_t ii=0;ii<natstats.size();++ii)
		print_human(natstats[ii],cols);
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