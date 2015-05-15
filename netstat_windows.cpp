//-liphlpapi

#include <Ws2spi.h>
#include <Windows.h>
#include <Iphlpapi.h>

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

std::string uint8_t_16_to_ipv6(const uint8_t address[16])
{
	/*std::ostringstream ostr;
	ostr<<(uint32_t)((uint8_t*)&address)[0]<<"."<<
		(uint32_t)((uint8_t*)&address)[1]<<"."<<
		(uint32_t)((uint8_t*)&address)[2]<<"."<<
		(uint32_t)((uint8_t*)&address)[3];*/
	//return ostr.str();
	return "hey!";
}

std::string uint16_t_to_port(const uint16_t port)
{
	std::ostringstream ostr;
	ostr<<((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
	return ostr.str();
}

std::string to_string(const uint32_t val)
{
	std::ostringstream ostr;
	ostr<<val;
	return ostr.str();
}

bool is_xp_sp2_or_later()
{
	OSVERSIONINFOEX osvi;
	memset(&osvi,0,sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize=sizeof(OSVERSIONINFOEX);
	osvi.dwMajorVersion=5;
	osvi.dwMinorVersion=1;
	osvi.wServicePackMajor=2;
	osvi.wServicePackMinor=0;

	DWORDLONG dwlConditionMask=0;
	int op=VER_GREATER_EQUAL;
	VER_SET_CONDITION(dwlConditionMask,VER_MAJORVERSION,op);
	VER_SET_CONDITION(dwlConditionMask,VER_MINORVERSION,op);
	VER_SET_CONDITION(dwlConditionMask,VER_SERVICEPACKMAJOR,op);
	VER_SET_CONDITION(dwlConditionMask,VER_SERVICEPACKMINOR,op);

	return VerifyVersionInfo(&osvi,
		VER_MAJORVERSION|VER_MINORVERSION|VER_SERVICEPACKMAJOR|VER_SERVICEPACKMINOR,dwlConditionMask);
}

//only Works for xp sp2 and up
netstat_list_t netstat_windows_parse_tcp4()
{
	if(!is_xp_sp2_or_later())
		throw std::runtime_error("netstat_windows_parse_tcp4 - Only works with XP SP2 and up.");

	MIB_TCPTABLE_OWNER_PID* table=(MIB_TCPTABLE_OWNER_PID*)malloc(sizeof(MIB_TCPTABLE_OWNER_PID));
	DWORD table_size=sizeof(MIB_TCPTABLE_OWNER_PID);
	DWORD error=GetExtendedTcpTable(table,&table_size,true,AF_INET,TCP_TABLE_OWNER_PID_ALL,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		table=(MIB_TCPTABLE_OWNER_PID*)malloc(table_size);
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

	error=GetExtendedTcpTable(table,&table_size,true,AF_INET,TCP_TABLE_OWNER_PID_ALL,0);

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
		netstat.pid=to_string(table->table[ii].dwOwningPid);
		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

netstat_list_t netstat_windows_parse_udp4()
{
	if(!is_xp_sp2_or_later())
		throw std::runtime_error("netstat_windows_parse_udp4 - Only works with XP SP2 and up.");

	MIB_UDPTABLE_OWNER_PID* table=(MIB_UDPTABLE_OWNER_PID*)malloc(sizeof(MIB_UDPTABLE_OWNER_PID));
	DWORD table_size=sizeof(MIB_UDPTABLE_OWNER_PID);
	DWORD error=GetExtendedUdpTable(table,&table_size,true,AF_INET,UDP_TABLE_OWNER_PID,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		table=(MIB_UDPTABLE_OWNER_PID*)malloc(table_size);
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

	error=GetExtendedUdpTable(table,&table_size,true,AF_INET,UDP_TABLE_OWNER_PID,0);

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
		netstat.local_port=uint16_t_to_port(table->table[ii].dwLocalPort);
		netstat.pid=to_string(table->table[ii].dwOwningPid);
		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

#ifdef AF_INET6

//only Works for xp sp2 and up
netstat_list_t netstat_windows_parse_tcp6()
{
	if(!is_xp_sp2_or_later())
		throw std::runtime_error("netstat_windows_parse_tcp6 - Only works with XP SP2 and up.");

	MIB_TCP6TABLE_OWNER_PID* table=(MIB_TCP6TABLE_OWNER_PID*)malloc(sizeof(MIB_TCP6TABLE_OWNER_PID));
	DWORD table_size=sizeof(MIB_TCP6TABLE_OWNER_PID);
	DWORD error=GetExtendedTcpTable(table,&table_size,true,AF_INET6,TCP_TABLE_OWNER_PID_ALL,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		table=(MIB_TCP6TABLE_OWNER_PID*)malloc(table_size);
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

	error=GetExtendedTcpTable(table,&table_size,true,AF_INET6,TCP_TABLE_OWNER_PID_ALL,0);

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
		netstat.proto="tcp6";
		netstat.local_address=uint8_t_16_to_ipv6(table->table[ii].ucLocalAddr);
		netstat.foreign_address=uint8_t_16_to_ipv6(table->table[ii].ucRemoteAddr);
		netstat.local_port=uint16_t_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=uint16_t_to_port(table->table[ii].dwRemotePort);
		netstat.state=states[table->table[ii].dwState];
		netstat.pid=to_string(table->table[ii].dwOwningPid);
		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

#endif

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
