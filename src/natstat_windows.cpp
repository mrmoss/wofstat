//-lIPHlpApi -lWs2_32
//http://forums.codeguru.com/showthread.php?188092.html
//Tested on:
//	Windows XP SP3 (VS2008, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)
//	Windows 7 (VS2013, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)
//	Windows 8.1 (VS2013, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)

#include "natstat.hpp"

#include <winsock2.h>
#include <IPHlpApi.h>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <stdint.h>

#include "natstat_util.hpp"
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
static natstat_list_t natstat_windows_parse_tcp4()
{
	natstat_list_t natstats;
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
		throw std::runtime_error("natstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	error=GetExtendedTcpTable(table,&table_size,true,AF_INET,TCP_TABLE_OWNER_PID_ALL,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		natstat_t natstat;
		natstat.proto="tcp4";
		natstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		natstat.faddr=u32_to_ipv4(table->table[ii].dwRemoteAddr);
		natstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		natstat.fport=dword_to_port(table->table[ii].dwRemotePort);
		natstat.pid="-";
		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("natstat_windows_parse_tcp4 - Invalid state returned.");
		}
		natstat.state=states[table->table[ii].dwState];
		if(table->table[ii].dwState==2)
		{
			natstat.faddr="0.0.0.0";
			natstat.fport=0;
		}
		if(natstat.pid!="0"&&natstat.state!="TIME_WAIT")
			natstat.pid=to_string(table->table[ii].dwOwningPid);
		natstats.push_back(natstat);
	}
	free(table);
	return natstats;
}

static natstat_list_t natstat_windows_parse_udp4()
{
	natstat_list_t natstats;
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
		throw std::runtime_error("natstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	error=GetExtendedUdpTable(table,&table_size,true,AF_INET,UDP_TABLE_OWNER_PID,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		natstat_t natstat;
		natstat.proto="udp4";
		natstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		natstat.faddr="0.0.0.0";
		natstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		natstat.fport=0;
		natstat.state="-";
		natstat.pid="-";
		if(natstat.pid!="0"&&natstat.state!="TIME_WAIT")
			natstat.pid=to_string(table->table[ii].dwOwningPid);
		natstats.push_back(natstat);
	}
	free(table);
	return natstats;
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

static natstat_list_t natstat_windows_parse_tcp6()
{
	natstat_list_t natstats;
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
		throw std::runtime_error("natstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	error=GetExtendedTcpTable(table,&table_size,true,AF_INET6,TCP_TABLE_OWNER_PID_ALL,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		natstat_t natstat;
		natstat.proto="tcp6";
		natstat.laddr=u8x16_to_ipv6(table->table[ii].ucLocalAddr);
		natstat.faddr=u8x16_to_ipv6(table->table[ii].ucRemoteAddr);
		natstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		natstat.fport=dword_to_port(table->table[ii].dwRemotePort);
		natstat.pid="-";
		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("natstat_windows_parse_tcp6 - Invalid state returned.");
		}
		natstat.state=states[table->table[ii].dwState];
		if(table->table[ii].dwState==2)
		{
			natstat.faddr="0000:0000:0000:0000:0000:0000:0000:0000";
			natstat.fport=0;
		}
		if(natstat.pid!="0"&&natstat.state!="TIME_WAIT")
			natstat.pid=to_string(table->table[ii].dwOwningPid);
		natstat.laddr=ipv6_prettify(natstat.laddr);
		natstat.faddr=ipv6_prettify(natstat.faddr);
		natstats.push_back(natstat);
	}
	free(table);
	return natstats;
}

static natstat_list_t natstat_windows_parse_udp6()
{
	natstat_list_t natstats;
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
		throw std::runtime_error("natstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	error=GetExtendedUdpTable(table,&table_size,true,AF_INET6,UDP_TABLE_OWNER_PID,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("natstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return natstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		natstat_t natstat;
		natstat.proto="udp6";
		natstat.laddr=u8x16_to_ipv6(table->table[ii].ucLocalAddr);
		natstat.faddr="0000:0000:0000:0000:0000:0000:0000:0000";
		natstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		natstat.fport=0;
		natstat.state="-";
		natstat.pid="-";
		if(natstat.pid!="0"&&natstat.state!="TIME_WAIT")
			natstat.pid=to_string(table->table[ii].dwOwningPid);
		natstat.laddr=ipv6_prettify(natstat.laddr);
		natstat.faddr=ipv6_prettify(natstat.faddr);
		natstats.push_back(natstat);
	}
	free(table);
	return natstats;
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

static natstat_list_t natstat_windows_parse_tcp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");
	if(hModule==NULL)
		throw std::runtime_error("natstat_windows_parse_tcp4 - Could not load iphlpapi.dll.");
	PROCALLOCATEANDGETTCPEXTABLEFROMSTACK AllocateAndGetTcpExTableFromStack=(PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetTcpExTableFromStack");
	if(AllocateAndGetTcpExTableFromStack==NULL)
		throw std::runtime_error("natstat_windows_parse_tcp4 - Could not locate function AllocateAndGetUdpExTableFromStack from iphlpapi.dll.");
	MIB_TCPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetTcpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	natstat_list_t natstats;
	if(error!=NO_ERROR)
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("natstat_windows_parse_tcp4 - External DLL call AllocateAndGetTcpExTableFromStack failed.");
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		if(table->table[ii].dwState>=states_size)
		{
			HeapFree(GetProcessHeap(),0,table);
			throw std::runtime_error("natstat_windows_parse_tcp4 - Invalid state returned.");
		}
		natstat_t natstat;
		natstat.proto="tcp4";
		natstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		natstat.faddr=u32_to_ipv4(table->table[ii].dwRemoteAddr);
		natstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		natstat.fport=dword_to_port(table->table[ii].dwRemotePort);
		natstat.state=states[table->table[ii].dwState];
		natstat.pid="-";
		if(table->table[ii].dwState==2)
		{
			natstat.faddr="0.0.0.0";
			natstat.fport=0;
		}
		if(natstat.pid!="0"&&natstat.state!="TIME_WAIT")
			natstat.pid=to_string(table->table[ii].dwProcessId);
		natstats.push_back(natstat);
	}
	HeapFree(GetProcessHeap(),0,table);
	return natstats;
}

static natstat_list_t natstat_windows_parse_udp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");
	if(hModule==NULL)
		throw std::runtime_error("natstat_windows_parse_udp4 - Could not load iphlpapi.dll.");
	PROCALLOCATEANDGETUDPEXTABLEFROMSTACK AllocateAndGetUdpExTableFromStack=(PROCALLOCATEANDGETUDPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetUdpExTableFromStack");
	if(AllocateAndGetUdpExTableFromStack==NULL)
		throw std::runtime_error("natstat_windows_parse_udp4 - Could not locate function AllocateAndGetUdpExTableFromStack from iphlpapi.dll.");
	MIB_UDPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetUdpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	natstat_list_t natstats;
	if(error!=NO_ERROR)
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("natstat_windows_parse_udp4 - External DLL call AllocateAndGetUdpExTableFromStack failed.");
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		natstat_t natstat;
		natstat.proto="udp4";
		natstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		natstat.faddr="0.0.0.0";
		natstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		natstat.fport=0;
		natstat.state="-";
		if(natstat.pid!="0"&&natstat.state!="TIME_WAIT")
			natstat.pid=to_string(table->table[ii].dwProcessId);
		natstats.push_back(natstat);
	}
	HeapFree(GetProcessHeap(),0,table);
	return natstats;
}

#endif

natstat_list_t natstat()
{
	natstat_list_t tcp4=natstat_windows_parse_tcp4();
	natstat_list_t udp4=natstat_windows_parse_udp4();
	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
	natstat_list_t tcp6=natstat_windows_parse_tcp6();
	natstat_list_t udp6=natstat_windows_parse_udp6();
	#endif
	natstat_list_t natstats;
	for(size_t ii=0;ii<tcp4.size();++ii)
		natstats.push_back(tcp4[ii]);
	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
	for(size_t ii=0;ii<tcp6.size();++ii)
		natstats.push_back(tcp6[ii]);
	#endif
	for(size_t ii=0;ii<udp4.size();++ii)
		natstats.push_back(udp4[ii]);
	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
	for(size_t ii=0;ii<udp6.size();++ii)
		natstats.push_back(udp6[ii]);
	#endif
	return natstats;
}
