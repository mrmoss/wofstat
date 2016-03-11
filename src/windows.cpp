//-lIPHlpApi -lWs2_32
//http://forums.codeguru.com/showthread.php?188092.html
//Tested on:
//	Windows XP SP3 (VS2008, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)
//	Windows 7 (VS2013, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)
//	Windows 8.1 (VS2013, MinGW FAILS DUE TO HEADER DECLARATION CHANGES)

#include "wofstat.hpp"

#include <winsock2.h>
#include <IPHlpApi.h>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <stdint.h>

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
static wofstat_list_t wofstat_windows_parse_tcp4()
{
	wofstat_list_t wofstats;
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
		throw std::runtime_error("wofstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	error=GetExtendedTcpTable(table,&table_size,true,AF_INET,TCP_TABLE_OWNER_PID_ALL,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_tcp4 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		wofstat_t wofstat;
		wofstat.proto="tcp4";
		wofstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		wofstat.faddr=u32_to_ipv4(table->table[ii].dwRemoteAddr);
		wofstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		wofstat.fport=dword_to_port(table->table[ii].dwRemotePort);
		wofstat.pid="-";
		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("wofstat_windows_parse_tcp4 - Invalid state returned.");
		}
		wofstat.state=states[table->table[ii].dwState];
		if(table->table[ii].dwState==2)
		{
			wofstat.faddr="0.0.0.0";
			wofstat.fport=0;
		}
		if(wofstat.pid!="0"&&wofstat.state!="TIME_WAIT")
			wofstat.pid=to_string(table->table[ii].dwOwningPid);
		wofstats.push_back(wofstat);
	}
	free(table);
	return wofstats;
}

static wofstat_list_t wofstat_windows_parse_udp4()
{
	wofstat_list_t wofstats;
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
		throw std::runtime_error("wofstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	error=GetExtendedUdpTable(table,&table_size,true,AF_INET,UDP_TABLE_OWNER_PID,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_udp4 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		wofstat_t wofstat;
		wofstat.proto="udp4";
		wofstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		wofstat.faddr="0.0.0.0";
		wofstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		wofstat.fport=0;
		wofstat.state="-";
		wofstat.pid="-";
		if(wofstat.pid!="0"&&wofstat.state!="TIME_WAIT")
			wofstat.pid=to_string(table->table[ii].dwOwningPid);
		wofstats.push_back(wofstat);
	}
	free(table);
	return wofstats;
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

static wofstat_list_t wofstat_windows_parse_tcp6()
{
	wofstat_list_t wofstats;
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
		throw std::runtime_error("wofstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	error=GetExtendedTcpTable(table,&table_size,true,AF_INET6,TCP_TABLE_OWNER_PID_ALL,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_tcp6 - GetExtendedTcpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		wofstat_t wofstat;
		wofstat.proto="tcp6";
		wofstat.laddr=u8x16_to_ipv6(table->table[ii].ucLocalAddr);
		wofstat.faddr=u8x16_to_ipv6(table->table[ii].ucRemoteAddr);
		wofstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		wofstat.fport=dword_to_port(table->table[ii].dwRemotePort);
		wofstat.pid="-";
		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("wofstat_windows_parse_tcp6 - Invalid state returned.");
		}
		wofstat.state=states[table->table[ii].dwState];
		if(table->table[ii].dwState==2)
		{
			wofstat.faddr="0000:0000:0000:0000:0000:0000:0000:0000";
			wofstat.fport=0;
		}
		if(wofstat.pid!="0"&&wofstat.state!="TIME_WAIT")
			wofstat.pid=to_string(table->table[ii].dwOwningPid);
		wofstat.laddr=ipv6_prettify(wofstat.laddr);
		wofstat.faddr=ipv6_prettify(wofstat.faddr);
		wofstats.push_back(wofstat);
	}
	free(table);
	return wofstats;
}

static wofstat_list_t wofstat_windows_parse_udp6()
{
	wofstat_list_t wofstats;
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
		throw std::runtime_error("wofstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	error=GetExtendedUdpTable(table,&table_size,true,AF_INET6,UDP_TABLE_OWNER_PID,0);
	if(error==ERROR_INSUFFICIENT_BUFFER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INSUFFICIENT_BUFFER.");
	}
	if(error==ERROR_INVALID_PARAMETER)
	{
		free(table);
		throw std::runtime_error("wofstat_windows_parse_udp6 - GetExtendedUdpTable returned ERROR_INVALID_PARAMETER.");
	}
	if(error==ERROR_NOT_SUPPORTED)
	{
		free(table);
		return wofstats;
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		wofstat_t wofstat;
		wofstat.proto="udp6";
		wofstat.laddr=u8x16_to_ipv6(table->table[ii].ucLocalAddr);
		wofstat.faddr="0000:0000:0000:0000:0000:0000:0000:0000";
		wofstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		wofstat.fport=0;
		wofstat.state="-";
		wofstat.pid="-";
		if(wofstat.pid!="0"&&wofstat.state!="TIME_WAIT")
			wofstat.pid=to_string(table->table[ii].dwOwningPid);
		wofstat.laddr=ipv6_prettify(wofstat.laddr);
		wofstat.faddr=ipv6_prettify(wofstat.faddr);
		wofstats.push_back(wofstat);
	}
	free(table);
	return wofstats;
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

static wofstat_list_t wofstat_windows_parse_tcp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");
	if(hModule==NULL)
		throw std::runtime_error("wofstat_windows_parse_tcp4 - Could not load iphlpapi.dll.");
	PROCALLOCATEANDGETTCPEXTABLEFROMSTACK AllocateAndGetTcpExTableFromStack=(PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetTcpExTableFromStack");
	if(AllocateAndGetTcpExTableFromStack==NULL)
		throw std::runtime_error("wofstat_windows_parse_tcp4 - Could not locate function AllocateAndGetUdpExTableFromStack from iphlpapi.dll.");
	MIB_TCPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetTcpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	wofstat_list_t wofstats;
	if(error!=NO_ERROR)
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("wofstat_windows_parse_tcp4 - External DLL call AllocateAndGetTcpExTableFromStack failed.");
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		if(table->table[ii].dwState>=states_size)
		{
			HeapFree(GetProcessHeap(),0,table);
			throw std::runtime_error("wofstat_windows_parse_tcp4 - Invalid state returned.");
		}
		wofstat_t wofstat;
		wofstat.proto="tcp4";
		wofstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		wofstat.faddr=u32_to_ipv4(table->table[ii].dwRemoteAddr);
		wofstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		wofstat.fport=dword_to_port(table->table[ii].dwRemotePort);
		wofstat.state=states[table->table[ii].dwState];
		wofstat.pid="-";
		if(table->table[ii].dwState==2)
		{
			wofstat.faddr="0.0.0.0";
			wofstat.fport=0;
		}
		if(wofstat.pid!="0"&&wofstat.state!="TIME_WAIT")
			wofstat.pid=to_string(table->table[ii].dwProcessId);
		wofstats.push_back(wofstat);
	}
	HeapFree(GetProcessHeap(),0,table);
	return wofstats;
}

static wofstat_list_t wofstat_windows_parse_udp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");
	if(hModule==NULL)
		throw std::runtime_error("wofstat_windows_parse_udp4 - Could not load iphlpapi.dll.");
	PROCALLOCATEANDGETUDPEXTABLEFROMSTACK AllocateAndGetUdpExTableFromStack=(PROCALLOCATEANDGETUDPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetUdpExTableFromStack");
	if(AllocateAndGetUdpExTableFromStack==NULL)
		throw std::runtime_error("wofstat_windows_parse_udp4 - Could not locate function AllocateAndGetUdpExTableFromStack from iphlpapi.dll.");
	MIB_UDPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetUdpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	wofstat_list_t wofstats;
	if(error!=NO_ERROR)
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("wofstat_windows_parse_udp4 - External DLL call AllocateAndGetUdpExTableFromStack failed.");
	}
	for(size_t ii=0;ii<table->dwNumEntries;++ii)
	{
		wofstat_t wofstat;
		wofstat.proto="udp4";
		wofstat.laddr=u32_to_ipv4(table->table[ii].dwLocalAddr);
		wofstat.faddr="0.0.0.0";
		wofstat.lport=dword_to_port(table->table[ii].dwLocalPort);
		wofstat.fport=0;
		wofstat.state="-";
		if(wofstat.pid!="0"&&wofstat.state!="TIME_WAIT")
			wofstat.pid=to_string(table->table[ii].dwProcessId);
		wofstats.push_back(wofstat);
	}
	HeapFree(GetProcessHeap(),0,table);
	return wofstats;
}

#endif

wofstat_list_t wofstat()
{
	wofstat_list_t tcp4=wofstat_windows_parse_tcp4();
	wofstat_list_t udp4=wofstat_windows_parse_udp4();
	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
	wofstat_list_t tcp6=wofstat_windows_parse_tcp6();
	wofstat_list_t udp6=wofstat_windows_parse_udp6();
	#endif
	wofstat_list_t wofstats;
	for(size_t ii=0;ii<tcp4.size();++ii)
		wofstats.push_back(tcp4[ii]);
	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
	for(size_t ii=0;ii<tcp6.size();++ii)
		wofstats.push_back(tcp6[ii]);
	#endif
	for(size_t ii=0;ii<udp4.size();++ii)
		wofstats.push_back(udp4[ii]);
	#if(defined(_WIN32_WINNT)&&_WIN32_WINNT>=_WIN32_WINNT_WS03)
	for(size_t ii=0;ii<udp6.size();++ii)
		wofstats.push_back(udp6[ii]);
	#endif
	return wofstats;
}
