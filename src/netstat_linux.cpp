//http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/include/net/tcp_states.h
//Tested on:
//	Ubuntu 14.04 (g++)
//	Kali 1.0.9 (g++)
//	Fedora 10 (g++)
//	Debian 3.2.0 (g++)
//	openSUSE 13.1 (g++)

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

const size_t states_size=14;
const std::string states[states_size]=
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

struct netstat_t
{
	std::string proto;
	std::string local_address;
	std::string foreign_address;
	std::string local_port;
	std::string foreign_port;
	std::string state;
	std::string inode;
	std::string pid;
};

typedef std::vector<std::string> list_t;
typedef std::vector<list_t> table_t;
typedef std::vector<netstat_t> netstat_list_t;
typedef std::pair<std::string,std::string> lookup_t;
typedef std::vector<lookup_t> lookup_list_t;

list_t string_to_lines(const std::string& str)
{
	std::istringstream istr(str.c_str());
	list_t lines;
	std::string line;

	while(std::getline(istr,line))
		lines.push_back(line);

	return lines;
}

std::string replace_all(std::string str,const std::string& find,const std::string& replace)
{
	size_t pos=0;

	while((pos=str.find(find,pos))!=std::string::npos)
	{
		str.replace(pos,find.size(),replace);
		pos+=replace.size();
	}

	return str;
}

list_t read_line_columns(const std::string& line)
{
	std::istringstream istr(line);
	list_t columns;
	std::string column;

	while(istr>>column)
		columns.push_back(column);

	return columns;
}

bool is_int(const std::string& str)
{
	for(size_t ii=0;ii<str.size();++ii)
		if(str[ii]<'0'||str[ii]>'9')
			return false;

	return str.size()!=0;
}

bool file_to_string(const std::string& filename,std::string& data)
{
	char buffer;
	std::ifstream istr(filename.c_str(),std::ios_base::in|std::ios_base::binary);
	istr.unsetf(std::ios_base::skipws);

	if(!istr)
		return false;

	data="";

	while(istr>>buffer)
		data+=buffer;

	istr.close();
	return true;
}

list_t list_directories(const std::string& path)
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

list_t list_files(const std::string& path)
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

std::string readlink(const std::string& path)
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

bool starts_with(const std::string& str,const std::string& prefix)
{
	return (str.size()>=prefix.size()&&str.compare(0,prefix.size(),prefix)==0);
}

bool ends_with(const std::string& str,const std::string& suffix)
{
	return (str.size()>=suffix.size()&&starts_with(str.substr(str.size()-suffix.size(),suffix.size()),suffix));
}

std::string to_lower(std::string str)
{
	std::transform(str.begin(),str.end(),str.begin(),tolower);
	return str;
}

bool is_hex(const std::string& hex)
{
	std::string lower_hex=to_lower(hex);

	for(size_t ii=0;ii<lower_hex.size();++ii)
		if(!(lower_hex[ii]>='0'&&lower_hex[ii]<='9')&&!(lower_hex[ii]>='a'&&lower_hex[ii]<='f'))
			return false;

	return true;
}

unsigned int hex_to_decimal(const std::string& hex)
{
	if(hex.size()!=2)
		throw std::runtime_error("hex_to_decimal - Invalid single byte hex value \""+hex+"\".");

	if(!is_hex(hex))
		throw std::runtime_error("hex_to_decimal - Invalid single byte hex value \""+hex+"\".");

	std::string lower_hex=to_lower(hex);
	unsigned int decimal=0;

	if(lower_hex[1]>='0'&&lower_hex[1]<='9')
		decimal+=lower_hex[1]-'0';
	if(lower_hex[1]>='a'&&lower_hex[1]<='f')
		decimal+=10+lower_hex[1]-'a';

	if(lower_hex[0]>='0'&&lower_hex[0]<='9')
		decimal+=(lower_hex[0]-'0')<<4;
	if(lower_hex[0]>='a'&&lower_hex[0]<='f')
		decimal+=(10+lower_hex[0]-'a')<<4;

	return decimal;
}

std::string hex_to_ipv4(const std::string& hex)
{
	if(!hex.size()==4||!is_hex(hex))
		throw std::runtime_error("hex_to_ipv4 - Invalid hex value \""+hex+"\".");

	std::ostringstream ostr;
	ostr<<hex_to_decimal(hex.substr(6,2))<<".";
	ostr<<hex_to_decimal(hex.substr(4,2))<<".";
	ostr<<hex_to_decimal(hex.substr(2,2))<<".";
	ostr<<hex_to_decimal(hex.substr(0,2));

	return ostr.str();
}

std::string hex_to_ipv6(const std::string& hex)
{
	if(!hex.size()==4||!is_hex(hex))
		throw std::runtime_error("hex_to_ipv4 - Invalid hex value \""+hex+"\".");

	std::string lower_hex=to_lower(hex);
	std::ostringstream ostr;
	ostr<<lower_hex.substr(2,2)<<lower_hex.substr(0,2)<<":";
	ostr<<lower_hex.substr(6,2)<<lower_hex.substr(4,2)<<":";
	ostr<<lower_hex.substr(10,2)<<lower_hex.substr(8,2)<<":";
	ostr<<lower_hex.substr(14,2)<<lower_hex.substr(12,2)<<":";
	ostr<<lower_hex.substr(18,2)<<lower_hex.substr(16,2)<<":";
	ostr<<lower_hex.substr(22,2)<<lower_hex.substr(20,2)<<":";
	ostr<<lower_hex.substr(26,2)<<lower_hex.substr(24,2)<<":";
	ostr<<lower_hex.substr(30,2)<<lower_hex.substr(28,2);

	return ostr.str();
}

std::string hex_to_port(const std::string& hex)
{
	if(!hex.size()==4||!is_hex(hex))
		throw std::runtime_error("hex_to_port - Invalid hex value \""+hex+"\".");

	std::ostringstream ostr;
	ostr<<(hex_to_decimal(hex.substr(0,2))<<8)+hex_to_decimal(hex.substr(2,2));
	return ostr.str();
}

std::string hex_to_state(const std::string& hex)
{
	unsigned int state=hex_to_decimal(hex);

	if(state>=states_size)
		throw std::runtime_error("hex_to_state - Value \""+hex+"\" is out of bounds.");

	return states[state];
}

netstat_list_t netstat_linux_parse(const std::string& proto,const std::string& data,const lookup_list_t& pid_lookups)
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

		netstat.inode=table[ii][13];
		netstat.pid="-";
		netstats.push_back(netstat);
	}

	for(size_t ii=0;ii<netstats.size();++ii)
	{
		for(size_t jj=0;jj<pid_lookups.size();++jj)
		{
			if(starts_with(pid_lookups[jj].second,"socket:[")&&ends_with(pid_lookups[jj].second,"]"))
			{
				if(netstats[ii].inode==pid_lookups[jj].second.substr(8,pid_lookups[jj].second.size()-9))
				{
					netstats[ii].pid=pid_lookups[jj].first;
					break;
				}
			}
		}
	}

	return netstats;
}

netstat_list_t netstat_linux()
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

void netstat_print(const netstat_t& netstat)
{
	std::cout<<
		std::setw(4)<<netstat.proto<<" "<<
		std::setw(64)<<netstat.local_address+":"+netstat.local_port<<" "<<
		std::setw(64)<<netstat.foreign_address+":"+netstat.foreign_port<<" "<<
		std::setw(16)<<netstat.state<<" "<<
		std::setw(8)<<netstat.pid<<" "<<
		std::endl;
}

void netstat_list_print(const netstat_list_t& netstats)
{
	std::cout<<
		std::setw(4)<<"proto "<<
		std::setw(64)<<"local_address "<<
		std::setw(64)<<"foreign_address "<<
		std::setw(16)<<"state "<<
		std::setw(8)<<"pid "<<
		std::endl;

	for(size_t ii=0;ii<netstats.size();++ii)
		netstat_print(netstats[ii]);
}

int main()
{
	netstat_list_t netstats=netstat_linux();
	netstat_list_print(netstats);

	return 0;
}
