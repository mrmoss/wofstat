//-lIPHlpApi -lWs2_32
//http://forums.codeguru.com/showthread.php?188092.html
//Tested on:
//	Windows XP SP3 (VS2008, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)
//	Windows 7 (VS2013, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)
//	Windows 8.1 (VS2013, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)

#include "netstat.hpp"

#include <winsock2.h>
#include <IPHlpApi.h>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <stdint.h>

#include "netstat_util.hpp"
#include "string_util.hpp"

static const size_t states_size=13;
static std::string states[states_size]=
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

#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)

static netstat_list_t netstat_windows_parse_tcp4()
{
	netstat_list_t netstats;
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
		throw std::runtime_error("netstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	error=GetExtendedTcpTable(table,&table_size,true,AF_INET,TCP_TABLE_OWNER_PID_ALL,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		netstat_t netstat;
		netstat.proto="tcp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address=uint32_t_to_ipv4(table->table[ii].dwRemoteAddr);
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=dword_to_port(table->table[ii].dwRemotePort);
		netstat.pid="-";

		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("netstat_windows_parse_tcp4 - Invalid state returned.");
		}

		netstat.state=states[table->table[ii].dwState];

		if(table->table[ii].dwState==2)
		{
			netstat.foreign_address="0.0.0.0";
			netstat.foreign_port="0";
		}

		if(netstat.pid!="0"&&netstat.state!="TIME_WAIT")
			netstat.pid=to_string(table->table[ii].dwOwningPid);

		netstats.push_back(netstat);
	}

	free(table);
	return netstats;
}

static netstat_list_t netstat_windows_parse_udp4()
{
	netstat_list_t netstats;
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
		throw std::runtime_error("netstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	error=GetExtendedUdpTable(table,&table_size,true,AF_INET,UDP_TABLE_OWNER_PID,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		netstat_t netstat;
		netstat.proto="udp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address="0.0.0.0";
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port="0";
		netstat.state="-";
		netstat.pid="-";

		if(netstat.pid!="0"&&netstat.state!="TIME_WAIT")
			netstat.pid=to_string(table->table[ii].dwOwningPid);

		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_VISTA)

	struct MIB_TCP6ROW_OWNER_PID
	{
		UCHAR ucLocalAddr[16];
		DWORD dwLocalScopeId;
		DWORD dwLocalPort;
		UCHAR ucRemoteAddr[16];
		DWORD dwRemoteScopeId;
		DWORD dwRemotePort;
		DWORD dwState;
		DWORD dwOwningPid;
	};

	struct MIB_UDP6ROW_OWNER_PID
	{
		UCHAR ucLocalAddr[16];
		DWORD dwLocalScopeId;
		DWORD dwLocalPort;
		DWORD dwOwningPid;
	};

	struct MIB_TCP6TABLE_OWNER_PID
	{
		DWORD dwNumEntries;
		MIB_TCP6ROW_OWNER_PID table[ANY_SIZE];
	};

	struct MIB_UDP6TABLE_OWNER_PID
	{
		DWORD dwNumEntries;
		MIB_UDP6ROW_OWNER_PID table[ANY_SIZE];
	};

#endif

static netstat_list_t netstat_windows_parse_tcp6()
{
	netstat_list_t netstats;
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
		throw std::runtime_error("netstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	error=GetExtendedTcpTable(table,&table_size,true,AF_INET6,TCP_TABLE_OWNER_PID_ALL,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		netstat_t netstat;
		netstat.proto="tcp6";
		netstat.local_address=uint8_t_16_to_ipv6(table->table[ii].ucLocalAddr);
		netstat.foreign_address=uint8_t_16_to_ipv6(table->table[ii].ucRemoteAddr);
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=dword_to_port(table->table[ii].dwRemotePort);
		netstat.pid="-";

		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("netstat_windows_parse_tcp6 - Invalid state returned.");
		}

		netstat.state=states[table->table[ii].dwState];

		if(table->table[ii].dwState==2)
		{
			netstat.foreign_address="0000:0000:0000:0000:0000:0000:0000:0000";
			netstat.foreign_port="0";
		}

		if(netstat.pid!="0"&&netstat.state!="TIME_WAIT")
			netstat.pid=to_string(table->table[ii].dwOwningPid);

		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

static netstat_list_t netstat_windows_parse_udp6()
{
	netstat_list_t netstats;
	MIB_UDP6TABLE_OWNER_PID* table=(MIB_UDP6TABLE_OWNER_PID*)malloc(sizeof(MIB_UDP6TABLE_OWNER_PID));
	DWORD table_size=sizeof(MIB_UDP6TABLE_OWNER_PID);
	DWORD error=GetExtendedUdpTable(table,&table_size,true,AF_INET6,UDP_TABLE_OWNER_PID,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		table=(MIB_UDP6TABLE_OWNER_PID*)malloc(table_size);
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	error=GetExtendedUdpTable(table,&table_size,true,AF_INET6,UDP_TABLE_OWNER_PID,0);

	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("netstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return netstats;
	}

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		netstat_t netstat;
		netstat.proto="udp6";
		netstat.local_address=uint8_t_16_to_ipv6(table->table[ii].ucLocalAddr);
		netstat.foreign_address="0000:0000:0000:0000:0000:0000:0000:0000";
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port="0";
		netstat.state="-";
		netstat.pid="-";

		if(netstat.pid!="0"&&netstat.state!="TIME_WAIT")
			netstat.pid=to_string(table->table[ii].dwOwningPid);

		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

#else

struct MIB_TCPROW_EX
{
	DWORD dwState;
	DWORD dwLocalAddr;
	DWORD dwLocalPort;
	DWORD dwRemoteAddr;
	DWORD dwRemotePort;
	DWORD dwProcessId;
};

struct MIB_UDPROW_EX
{
	DWORD dwLocalAddr;
	DWORD dwLocalPort;
	DWORD dwProcessId;
};

struct MIB_TCPTABLE_EX
{
	DWORD dwNumEntries;
	MIB_TCPROW_EX table[ANY_SIZE];
};


struct MIB_UDPTABLE_EX
{
	DWORD dwNumEntries;
	MIB_UDPROW_EX table[ANY_SIZE];
};

typedef DWORD (WINAPI* PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)(MIB_TCPTABLE_EX**,BOOL,HANDLE,DWORD,DWORD);
typedef DWORD (WINAPI* PROCALLOCATEANDGETUDPEXTABLEFROMSTACK)(MIB_UDPTABLE_EX**,BOOL,HANDLE,DWORD,DWORD);

static netstat_list_t netstat_windows_parse_tcp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");

	if(hModule==NULL)
		throw std::runtime_error("netstat_windows_parse_tcp4 - Could not load iphlpapi.dll.");

	PROCALLOCATEANDGETTCPEXTABLEFROMSTACK AllocateAndGetTcpExTableFromStack=(PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetTcpExTableFromStack");

	if(AllocateAndGetTcpExTableFromStack==NULL)
		throw std::runtime_error("netstat_windows_parse_tcp4 - Could not locate function AllocateAndGetUdpExTableFromStack from iphlpapi.dll.");

	MIB_TCPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetTcpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	netstat_list_t netstats;

	if(error!=NO_ERROR)
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("netstat_windows_parse_tcp4 - External DLL call AllocateAndGetTcpExTableFromStack failed.");
	}

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		if(table->table[ii].dwState>=states_size)
		{
			HeapFree(GetProcessHeap(),0,table);
			throw std::runtime_error("netstat_windows_parse_tcp4 - Invalid state returned.");
		}

		netstat_t netstat;
		netstat.proto="tcp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address=uint32_t_to_ipv4(table->table[ii].dwRemoteAddr);
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=dword_to_port(table->table[ii].dwRemotePort);
		netstat.state=states[table->table[ii].dwState];
		netstat.pid="-";

		if(table->table[ii].dwState==2)
		{
			netstat.foreign_address="0.0.0.0";
			netstat.foreign_port="0";
		}

		if(netstat.pid!="0"&&netstat.state!="TIME_WAIT")
			netstat.pid=to_string(table->table[ii].dwProcessId);

		netstats.push_back(netstat);
	}

	HeapFree(GetProcessHeap(),0,table);
	return netstats;
}

static netstat_list_t netstat_windows_parse_udp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");

	if(hModule==NULL)
		throw std::runtime_error("netstat_windows_parse_udp4 - Could not load iphlpapi.dll.");

	PROCALLOCATEANDGETUDPEXTABLEFROMSTACK AllocateAndGetUdpExTableFromStack=(PROCALLOCATEANDGETUDPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetUdpExTableFromStack");

	if(AllocateAndGetUdpExTableFromStack==NULL)
		throw std::runtime_error("netstat_windows_parse_udp4 - Could not locate function AllocateAndGetUdpExTableFromStack from iphlpapi.dll.");

	MIB_UDPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetUdpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	netstat_list_t netstats;

	if(error!=NO_ERROR)
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("netstat_windows_parse_udp4 - External DLL call AllocateAndGetUdpExTableFromStack failed.");
	}

	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		netstat_t netstat;
		netstat.proto="udp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address="0.0.0.0";
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port="0";
		netstat.state="-";

		if(netstat.pid!="0"&&netstat.state!="TIME_WAIT")
			netstat.pid=to_string(table->table[ii].dwProcessId);

		netstats.push_back(netstat);
	}

	HeapFree(GetProcessHeap(),0,table);
	return netstats;
}

#endif

netstat_list_t netstat()
{
	netstat_list_t tcp4=netstat_windows_parse_tcp4();
	netstat_list_t udp4=netstat_windows_parse_udp4();

	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
		netstat_list_t tcp6=netstat_windows_parse_tcp6();
		netstat_list_t udp6=netstat_windows_parse_udp6();
	#endif

	netstat_list_t netstats;

	for(size_t ii=0;ii<tcp4.size();++ii)
		netstats.push_back(tcp4[ii]);

	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
		for(size_t ii=0;ii<tcp6.size();++ii)
			netstats.push_back(tcp6[ii]);
	#endif

	for(size_t ii=0;ii<udp4.size();++ii)
		netstats.push_back(udp4[ii]);

	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
		for(size_t ii=0;ii<udp6.size();++ii)
			netstats.push_back(udp6[ii]);
	#endif

	return netstats;
}