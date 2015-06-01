//http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/include/net/tcp_states.h
//Tested on:
//	Ubuntu 14.04 (g++)
//	Kali 1.0.9 (g++)
//	Fedora 10 (g++)
//	Debian 3.2.0 (g++)
//	openSUSE 13.1 (g++)
//	CentOS 5.7 (g++)

#include "netstat.hpp"

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

#include "netstat_util.hpp"
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

static netstat_list_t netstat_linux_parse(const std::string& proto,const std::string& data,const lookup_list_t& pid_lookups)
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

	netstat_list_t netstats;
	list_t inodes;

	for(size_t ii=0;ii<table.size();++ii)
	{
		netstat_t netstat;
		netstat.proto=proto;

		if(proto=="tcp4"||proto=="udp4")
		{
			netstat.local_address=hex_to_ipv4(table[ii][1]);
			netstat.foreign_address=hex_to_ipv4(table[ii][3]);
		}
		else if(proto=="tcp6"||proto=="udp6")
		{
			netstat.local_address=hex_to_ipv6(table[ii][1]);
			netstat.foreign_address=hex_to_ipv6(table[ii][3]);
		}

		netstat.local_port=hex_to_port(table[ii][2]);
		netstat.foreign_port=hex_to_port(table[ii][4]);

		if(proto=="udp4"||proto=="udp6")
			netstat.state="-";
		else
			netstat.state=hex_to_state(table[ii][5]);

		inodes.push_back(table[ii][13]);
		netstat.pid="-";
		netstats.push_back(netstat);
	}

	for(size_t ii=0;ii<netstats.size();++ii)
	{
		for(size_t jj=0;jj<pid_lookups.size();++jj)
		{
			if(starts_with(pid_lookups[jj].second,"socket:[")&&ends_with(pid_lookups[jj].second,"]"))
			{
				if(inodes[ii]==pid_lookups[jj].second.substr(8,pid_lookups[jj].second.size()-9))
				{
					netstats[ii].pid=pid_lookups[jj].first;
					break;
				}
			}
		}
	}

	return netstats;
}

netstat_list_t netstat()
{
	lookup_list_t pid_lookups;
	list_t directories=list_directories("/proc");

	for(size_t ii=0;ii<directories.size();++ii)
	{
		if(is_int(directories[ii]))
		{
			std::string directory="/proc/"+directories[ii]+"/fd";

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

	netstat_list_t tcp4=netstat_linux_parse("tcp4",tcp4_data,pid_lookups);
	netstat_list_t tcp6;
	netstat_list_t udp4=netstat_linux_parse("udp4",udp4_data,pid_lookups);
	netstat_list_t udp6;

	bool ipv6_support=file_to_string("/proc/net/tcp6",tcp6_data)&&file_to_string("/proc/net/udp6",udp6_data);

	if(ipv6_support)
	{
		tcp6=netstat_linux_parse("tcp6",tcp6_data,pid_lookups);
		udp6=netstat_linux_parse("udp6",udp6_data,pid_lookups);
	}

	netstat_list_t netstats;

	for(size_t ii=0;ii<tcp4.size();++ii)
		netstats.push_back(tcp4[ii]);

	if(ipv6_support)
		for(size_t ii=0;ii<tcp6.size();++ii)
			netstats.push_back(tcp6[ii]);

	for(size_t ii=0;ii<udp4.size();++ii)
		netstats.push_back(udp4[ii]);

	if(ipv6_support)
		for(size_t ii=0;ii<udp6.size();++ii)
			netstats.push_back(udp6[ii]);

	return netstats;
}