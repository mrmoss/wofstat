//-liphlpapi
//http://forums.codeguru.com/showthread.php?188092.html

#include <Windows.h>
#include <IPHlpApi.h>

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
	std::ostringstream ostr;
	for(int ii=0;ii<16;ii+=2)
	{
		ostr<<std::setfill('0')<<std::setw(2)<<std::hex<<address[ii+1];
		ostr<<std::setfill('0')<<std::setw(2)<<std::hex<<address[ii+0];

		if(ii<14)
			ostr<<":";
	}

	return ostr.str();
}

std::string dword_to_port(const DWORD port)
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

#if(defined(NTDDI_WINXPSP2))

netstat_list_t netstat_windows_parse_tcp4()
{
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
		netstat_t netstat;
		netstat.proto="tcp4";
		netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
		netstat.foreign_address=uint32_t_to_ipv4(table->table[ii].dwRemoteAddr);
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port=dword_to_port(table->table[ii].dwRemotePort);

		if(table->table[ii].dwState>=states_size)
		{
			free(table);
			throw std::runtime_error("");
		}

		netstat.state=states[table->table[ii].dwState];

		if(table->table[ii].dwState==2)
		{
			netstat.foreign_address="0.0.0.0";
			netstat.foreign_port="0";
		}

		netstat.pid=to_string(table->table[ii].dwOwningPid);
		netstats.push_back(netstat);
	}

	free(table);

	return netstats;
}

netstat_list_t netstat_windows_parse_udp4()
{
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
		netstat.foreign_address="0.0.0.0";
		netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
		netstat.foreign_port="0";
		netstat.state="-";
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

netstat_list_t netstat_windows_parse_tcp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");

	if(hModule==NULL)
		throw std::runtime_error("");

	PROCALLOCATEANDGETTCPEXTABLEFROMSTACK AllocateAndGetTcpExTableFromStack=(PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetTcpExTableFromStack");
	if(AllocateAndGetTcpExTableFromStack==NULL)
		throw std::runtime_error("");

	MIB_TCPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetTcpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	netstat_list_t netstats;

	if(error==NO_ERROR)
	{
		for(size_t ii=0;ii<table->dwNumEntries;++ii)
		{
			if(table->table[ii].dwState>=states_size)
			{
				HeapFree(GetProcessHeap(),0,table);
				throw std::runtime_error("");
			}

			netstat_t netstat;
			netstat.proto="tcp4";
			netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
			netstat.foreign_address=uint32_t_to_ipv4(table->table[ii].dwRemoteAddr);
			netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
			netstat.foreign_port=dword_to_port(table->table[ii].dwRemotePort);
			netstat.state=states[table->table[ii].dwState];

			if(table->table[ii].dwState==2)
			{
				netstat.foreign_address="0.0.0.0";
				netstat.foreign_port="0";
			}

			netstat.pid=to_string(table->table[ii].dwProcessId);
			netstats.push_back(netstat);
		}
	}
	else
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("");
	}

	HeapFree(GetProcessHeap(),0,table);
	return netstats;
}

netstat_list_t netstat_windows_parse_udp4()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");

	if(hModule==NULL)
		throw std::runtime_error("");

	PROCALLOCATEANDGETUDPEXTABLEFROMSTACK AllocateAndGetUdpExTableFromStack=(PROCALLOCATEANDGETUDPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetUdpExTableFromStack");
	if(AllocateAndGetUdpExTableFromStack==NULL)
		throw std::runtime_error("");

	MIB_UDPTABLE_EX* table = NULL;
	DWORD error=AllocateAndGetUdpExTableFromStack(&table,TRUE,GetProcessHeap(),0,2);
	netstat_list_t netstats;

	if(error==NO_ERROR)
	{
		for(size_t ii=0;ii<table->dwNumEntries;++ii)
		{
			netstat_t netstat;
			netstat.proto="udp4";
			netstat.local_address=uint32_t_to_ipv4(table->table[ii].dwLocalAddr);
			netstat.foreign_address="0.0.0.0";
			netstat.local_port=dword_to_port(table->table[ii].dwLocalPort);
			netstat.foreign_port="0";
			netstat.state="-";
			netstat.pid=to_string(table->table[ii].dwProcessId);
			netstats.push_back(netstat);
		}
	}
	else
	{
		HeapFree(GetProcessHeap(),0,table);
		throw std::runtime_error("");
	}

	HeapFree(GetProcessHeap(),0,table);
	return netstats;
}

#endif

netstat_list_t netstat_windows()
{
	netstat_list_t tcp4=netstat_windows_parse_tcp4();
	netstat_list_t udp4=netstat_windows_parse_udp4();

	#if(defined(NTDDI_WINXPSP2))
		//netstat_list_t tcp6=netstat_windows_parse_tcp6();
		//netstat_list_t udp6=netstat_windows_parse_udp6();
	#endif

	netstat_list_t netstats;

	for(size_t ii=0;ii<tcp4.size();++ii)
		netstats.push_back(tcp4[ii]);

	#if(defined(NTDDI_WINXPSP2))
		//for(size_t ii=0;ii<tcp6.size();++ii)
		//	netstats.push_back(tcp6[ii]);
	#endif

	for(size_t ii=0;ii<udp4.size();++ii)
		netstats.push_back(udp4[ii]);

	#if(defined(NTDDI_WINXPSP2))
		//for(size_t ii=0;ii<udp6.size();++ii)
		//	netstats.push_back(udp6[ii]);
	#endif

	return netstats;
}

int main()
{
	netstat_list_t netstats=netstat_windows();
	netstat_list_print(netstats);
	return 0;
}
