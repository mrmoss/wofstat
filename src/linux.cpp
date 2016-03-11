//http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/include/net/tcp_states.h
//Tested on:
//	Ubuntu 14.04 (g++)
//	Kali 1.0.9 (g++)
//	Fedora 10 (g++)
//	Debian 3.2.0 (g++)
//	openSUSE 13.1 (g++)
//	CentOS 5.7 (g++)

#include "wofstat.hpp"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "string_util.hpp"

static const size_t states_size=14;
static const std::string states[states_size]=
{
	"UNKNOWN",
	"ESTABLISHED",
	"SYN_SENT",
	"SYN_RECV",
	"FIN_WAIT1",
	"FIN_WAIT2",
	"TIME_WAIT",
	"CLOSE",
	"CLOSE_WAIT",
	"LAST_ACK",
	"LISTEN",
	"CLOSING",
	"NEW_SYN_RECV",
	"MAX_STATES"
};

static list_t list_directories(const std::string& path)
{
	list_t directories;
	DIR* dp=opendir(path.c_str());
	while(dp!=NULL)
	{
		dirent* np=readdir(dp);
		if(np==NULL)
		{
			closedir(dp);
			break;
		}
		std::string node_name(np->d_name);
		if(node_name!="."&&node_name!=".."&&np->d_type==DT_DIR)
			directories.push_back(node_name);
	}
	return directories;
}

static list_t list_files(const std::string& path)
{
	list_t files;
	DIR* dp=opendir(path.c_str());
	while(dp!=NULL)
	{
		dirent* np=readdir(dp);
		if(np==NULL)
		{
			closedir(dp);
			break;
		}
		std::string node_name(np->d_name);
		if(node_name!="."&&node_name!=".."&&np->d_type!=DT_DIR)
			files.push_back(node_name);
	}
	return files;
}

static std::string readlink(const std::string& path)
{
	char buffer[15];
	ssize_t size=readlink(path.c_str(),buffer,15);
	if(size==-1)
		throw std::runtime_error("insufficient memory");
	std::string ret(buffer,size);
	while(ret.size()>0&&isspace(ret[ret.size()-1])!=0)
		ret.erase(ret.size()-1,1);
	return ret;
}

static std::string hex_to_state(const std::string& hex)
{
	unsigned int state=hex_to_decimal(hex);
	if(state>=states_size)
		throw std::runtime_error("hex_to_state - Value \""+hex+"\" is out of bounds.");
	return states[state];
}

static wofstat_list_t wofstat_linux_parse(const std::string& proto,const std::string& data,const lookup_list_t& pid_lookups)
{
	table_t table;
	list_t lines=string_to_lines(data);
	for(size_t ii=0;ii<lines.size();++ii)
	{
		lines[ii]=replace_all(lines[ii],":"," ");
		list_t columns=read_line_columns(lines[ii]);
		if(columns.size()>0&&is_int(columns[0]))
			table.push_back(columns);
	}
	wofstat_list_t wofstats;
	list_t inodes;
	for(size_t ii=0;ii<table.size();++ii)
	{
		wofstat_t wofstat;
		wofstat.proto=proto;
		if(proto=="tcp4"||proto=="udp4")
		{
			wofstat.laddr=hex_to_ipv4(table[ii][1]);
			wofstat.faddr=hex_to_ipv4(table[ii][3]);
		}
		else if(proto=="tcp6"||proto=="udp6")
		{
			wofstat.laddr=hex_to_ipv6(table[ii][1]);
			wofstat.faddr=hex_to_ipv6(table[ii][3]);
			wofstat.laddr=ipv6_prettify(wofstat.laddr);
			wofstat.faddr=ipv6_prettify(wofstat.faddr);
		}
		wofstat.lport=hex_to_port(table[ii][2]);
		wofstat.fport=hex_to_port(table[ii][4]);
		if(proto=="udp4"||proto=="udp6")
			wofstat.state="-";
		else
			wofstat.state=hex_to_state(table[ii][5]);
		inodes.push_back(table[ii][13]);
		wofstat.pid="-";
		wofstats.push_back(wofstat);
	}
	for(size_t ii=0;ii<wofstats.size();++ii)
	{
		for(size_t jj=0;jj<pid_lookups.size();++jj)
		{
			if(starts_with(pid_lookups[jj].second,"socket:[")&&ends_with(pid_lookups[jj].second,"]"))
			{
				if(inodes[ii]==pid_lookups[jj].second.substr(8,pid_lookups[jj].second.size()-9))
				{
					wofstats[ii].pid=pid_lookups[jj].first;
					break;
				}
			}
		}
	}
	return wofstats;
}

wofstat_list_t wofstat()
{
	lookup_list_t pid_lookups;
	list_t directories=list_directories("/proc");
	for(size_t ii=0;ii<directories.size();++ii)
	{
		if(is_int(directories[ii]))
		{
			std::string directory("/proc/"+directories[ii]+"/fd");
			list_t files=list_files(directory);
			for(size_t jj=0;jj<files.size();++jj)
			{
				try
				{
					std::string linkname=readlink(directory+"/"+files[jj]);
					pid_lookups.push_back(lookup_t(directories[ii],linkname));
				}
				catch(std::exception& e)
				{}
			}
		}
	}
	std::string tcp4_data;
	std::string tcp6_data;
	std::string udp4_data;
	std::string udp6_data;
	if(!file_to_string("/proc/net/tcp",tcp4_data))
		throw std::runtime_error("Could not read file named \"/proc/net/tcp\".");
	if(!file_to_string("/proc/net/udp",udp4_data))
		throw std::runtime_error("Could not read file named \"/proc/net/udp\".");
	wofstat_list_t tcp4=wofstat_linux_parse("tcp4",tcp4_data,pid_lookups);
	wofstat_list_t tcp6;
	wofstat_list_t udp4=wofstat_linux_parse("udp4",udp4_data,pid_lookups);
	wofstat_list_t udp6;
	bool ipv6_support=file_to_string("/proc/net/tcp6",tcp6_data)&&file_to_string("/proc/net/udp6",udp6_data);
	if(ipv6_support)
	{
		tcp6=wofstat_linux_parse("tcp6",tcp6_data,pid_lookups);
		udp6=wofstat_linux_parse("udp6",udp6_data,pid_lookups);
	}
	wofstat_list_t wofstats;
	for(size_t ii=0;ii<tcp4.size();++ii)
		wofstats.push_back(tcp4[ii]);
	if(ipv6_support)
		for(size_t ii=0;ii<tcp6.size();++ii)
			wofstats.push_back(tcp6[ii]);
	for(size_t ii=0;ii<udp4.size();++ii)
		wofstats.push_back(udp4[ii]);
	if(ipv6_support)
		for(size_t ii=0;ii<udp6.size();++ii)
			wofstats.push_back(udp6[ii]);
	return wofstats;
}