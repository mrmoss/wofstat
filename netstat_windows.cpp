//-liphlpapi

#include <Windows.h>
#include <iphlpapi.h>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <stdint.h>

const size_t states_size=13;
std::string states[states_size]=
{
	"UNKNOWN",
	"CLOSE",
	"LISTEN",
	"SYN_SENT",
	"SYN_RECV",
	"ESTABLISHED",
	"FIN_WAIT1",
	"FIN_WAIT2",
	"CLOSE_WAIT",
	"CLOSING",
	"LAST_ACK",
	"TIME_WAIT",
	"CLOSE"
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

typedef std::vector<netstat_t> netstat_list_t;

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

std::string uint32_t_to_ipv4(const uint32_t address)
{
	std::ostringstream ostr;
	ostr<<(uint32_t)((uint8_t*)&address)[0]<<"."<<
		(uint32_t)((uint8_t*)&address)[1]<<"."<<
		(uint32_t)((uint8_t*)&address)[2]<<"."<<
		(uint32_t)((uint8_t*)&address)[3];
	return ostr.str();
}

std::string uint16_t_to_port(const uint16_t port)
{
	std::ostringstream ostr;
	ostr<<((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
	return ostr.str();
}

netstat_list_t netstat_windows_parse_tcp4()
{
	MIB_TCPTABLE* table=(MIB_TCPTABLE*)malloc(sizeof(MIB_TCPTABLE));
	DWORD table_size=sizeof(MIB_TCPTABLE);
	DWORD error=GetTcpTable(table,&table_size,true);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		table=(MIB_TCPTABLE*)malloc(table_size);
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		throw std::runtime_error("");
	}

	error=GetTcpTable(table,&table_size,true);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		throw std::runtime_error("");
	}

	netstat_list_t netstats;

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("");
		}

		netstat_t netstat;
		netstat.proto="tcp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address=uint32_t_to_ipv4(table->table[ii].dwRemoteAddr);
		netstat.local_port=uint16_t_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=uint16_t_to_port(table->table[ii].dwRemotePort);
		netstat.state=states[table->table[ii].dwState];
		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

netstat_list_t netstat_windows_parse_udp4()
{
	MIB_UDPTABLE* table=(MIB_UDPTABLE*)malloc(sizeof(MIB_UDPTABLE));
	DWORD table_size=sizeof(MIB_UDPTABLE);
	DWORD error=GetUdpTable(table,&table_size,true);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		table=(MIB_UDPTABLE*)malloc(table_size);
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		throw std::runtime_error("");
	}

	error=GetUdpTable(table,&table_size,true);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		throw std::runtime_error("");
	}

	netstat_list_t netstats;

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		netstat_t netstat;
		netstat.proto="udp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address=uint32_t_to_ipv4(0);
		netstat.local_port=uint16_t_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=uint16_t_to_port(0);
		netstat.state="-";
		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

netstat_list_t netstat_windows()
{
	netstat_list_t tcp4=netstat_windows_parse_tcp4();
	//netstat_list_t tcp6=netstat_windows_parse_tcp6();
	netstat_list_t udp4=netstat_windows_parse_udp4();
	//netstat_list_t udp6=netstat_windows_parse_udp6();

	netstat_list_t netstats;

	for(size_t ii=0;ii<tcp4.size();++ii)
		netstats.push_back(tcp4[ii]);
	//for(size_t ii=0;ii<tcp6.size();++ii)
	//	netstats.push_back(tcp6[ii]);
	for(size_t ii=0;ii<udp4.size();++ii)
		netstats.push_back(udp4[ii]);
	//for(size_t ii=0;ii<udp6.size();++ii)
	//	netstats.push_back(udp6[ii]);

	return netstats;
}

int main()
{

	netstat_list_t netstats=netstat_windows();
	netstat_list_print(netstats);
	return 0;
}
