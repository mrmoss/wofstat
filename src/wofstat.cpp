#include "wofstat.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

void print_human(const wofstat_t& wofstat,std::vector<size_t> cols)
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
	if(wofstat.proto.substr(3,1)=="6")
		V6=true;
	std::ostringstream lstr;
	if(V6)
		lstr<<"["<<wofstat.laddr<<"]:"<<wofstat.lport;
	else
		lstr<<wofstat.laddr<<":"<<wofstat.fport;
	std::ostringstream rstr;
	if(V6)
		rstr<<"["<<wofstat.faddr<<"]:"<<wofstat.fport;
	else
		rstr<<wofstat.faddr<<":"<<wofstat.fport;
	std::cout<<
		std::setw(cols[0])<<wofstat.proto<<
		std::setw(cols[1])<<lstr.str()<<
		std::setw(cols[2])<<rstr.str()<<
		std::setw(cols[3])<<wofstat.state<<
		std::setw(cols[4])<<wofstat.pid<<
		std::endl;
}

void print_human(const wofstat_list_t& wofstats)
{
	size_t pad=1;
	std::vector<size_t> cols;
	cols.push_back(5+pad);
	cols.push_back(15+pad);
	cols.push_back(15+pad);
	cols.push_back(5+pad);
	cols.push_back(3+pad);
	for(size_t ii=0;ii<wofstats.size();++ii)
	{
		if(wofstats[ii].proto.size()+pad>cols[0])
			cols[0]=wofstats[ii].proto.size()+pad;
		if(wofstats[ii].laddr.size()+8+pad>cols[1])
			cols[1]=wofstats[ii].laddr.size()+8+pad;
		if(wofstats[ii].faddr.size()+8>cols[2])
			cols[2]=wofstats[ii].faddr.size()+8+pad;
		if(wofstats[ii].state.size()+pad>cols[3])
			cols[3]=wofstats[ii].state.size()+pad;
		if(wofstats[ii].pid.size()+pad>cols[4])
			cols[4]=wofstats[ii].pid.size()+pad;
	}
	std::cout<<
		std::setw(cols[0])<<"proto"<<
		std::setw(cols[1])<<"local address"<<
		std::setw(cols[2])<<"foreign address"<<
		std::setw(cols[3])<<"state"<<
		std::setw(cols[4])<<"pid"<<
		std::endl;
	for(size_t ii=0;ii<wofstats.size();++ii)
		print_human(wofstats[ii],cols);
}

void print_wof(const wofstat_t& wofstat)
{
	std::string dir;
	if(wofstat.state=="ESTABLISHED")
		dir=">";
	else if(wofstat.state=="LISTEN")
		dir="<";
	else if(wofstat.proto.substr(0,3)=="udp")
		dir="<>";
	if(dir.size()>0)
	{
		std::cout<<wofstat.proto.substr(0,3)<<" ";
		bool V6=(wofstat.proto.substr(3,1)=="6");
		if(V6)
			std::cout<<"["<<wofstat.laddr<<"]";
		else
			std::cout<<wofstat.laddr;
		std::cout<<":"<<wofstat.lport;
		std::cout<<dir;
		if(V6)
			std::cout<<"["<<wofstat.faddr<<"]";
		else
			std::cout<<wofstat.faddr;
		std::cout<<":"<<wofstat.fport;
		std::cout<<" #pid "<<wofstat.pid;
		std::cout<<std::endl;
	}
}

void print_wof(const wofstat_list_t& wofstats)
{
	for(size_t ii=0;ii<wofstats.size();++ii)
		print_wof(wofstats[ii]);
}