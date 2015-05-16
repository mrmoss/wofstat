//http://forums.codeguru.com/showthread.php?188092.html

#include <Windows.h>
#include <IPHlpApi.h>

#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <sstream>

struct MIB_TCPROW_EX
{
	DWORD dwState;
	DWORD dwLocalAddr;
	DWORD dwLocalPort;
	DWORD dwRemoteAddr;
	DWORD dwRemotePort;
	DWORD dwProcessId;
};

struct MIB_TCPTABLE_EX
{
	DWORD dwNumEntries;
	MIB_TCPROW_EX table[ANY_SIZE];
};

typedef DWORD (WINAPI* PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)(MIB_TCPTABLE_EX**,BOOL,HANDLE,DWORD,DWORD);

int main()
{
	HMODULE hModule=LoadLibrary("iphlpapi.dll");

	if(hModule==NULL)
		throw std::runtime_error("");

	PROCALLOCATEANDGETTCPEXTABLEFROMSTACK AllocateAndGetTcpExTableFromStack=(PROCALLOCATEANDGETTCPEXTABLEFROMSTACK)GetProcAddress(hModule,"AllocateAndGetTcpExTableFromStack");
	if(AllocateAndGetTcpExTableFromStack==NULL)
		throw std::runtime_error("");

	MIB_TCPTABLE_EX* lpBuffer = NULL;
	DWORD error = AllocateAndGetTcpExTableFromStack(&lpBuffer,TRUE,GetProcessHeap(),0,2);

	if(error==NO_ERROR)
	{
		std::cout<<std::setw(21)<<"Local";
		std::cout<<" ";
		std::cout<<std::setw(21)<<"Remote";
		std::cout<<" ";
		std::cout<<std::setw(5)<<"PID";
		std::cout<<std::endl;

		for (DWORD dwSize = 0; dwSize < lpBuffer->dwNumEntries; dwSize++)
		{
			// Local IP Address
			{
				std::ostringstream ostr;
				ostr<<
					(unsigned int)(unsigned char)LOBYTE(LOWORD(lpBuffer->table[dwSize].dwLocalAddr))<<"."<<
					(unsigned int)(unsigned char)HIBYTE(LOWORD(lpBuffer->table[dwSize].dwLocalAddr))<<"."<<
					(unsigned int)(unsigned char)LOBYTE(HIWORD(lpBuffer->table[dwSize].dwLocalAddr))<<"."<<
					(unsigned int)(unsigned char)HIBYTE(HIWORD(lpBuffer->table[dwSize].dwLocalAddr))<<":"<<
					((lpBuffer->table[dwSize].dwLocalPort & 0xFF00) >> 8)+((lpBuffer->table[dwSize].dwLocalPort & 0x00FF) << 8);
				std::cout<<std::setw(21)<<ostr.str();
				std::cout<<" ";
			}

			// Remote IP Address
			{
				std::ostringstream ostr;
				ostr<<
					(unsigned int)(unsigned char)LOBYTE(LOWORD(lpBuffer->table[dwSize].dwRemoteAddr))<<"."<<
					(unsigned int)(unsigned char)HIBYTE(LOWORD(lpBuffer->table[dwSize].dwRemoteAddr))<<"."<<
					(unsigned int)(unsigned char)LOBYTE(HIWORD(lpBuffer->table[dwSize].dwRemoteAddr))<<"."<<
					(unsigned int)(unsigned char)HIBYTE(HIWORD(lpBuffer->table[dwSize].dwRemoteAddr))<<":"<<
					((lpBuffer->table[dwSize].dwRemotePort & 0xFF00) >> 8) + ((lpBuffer->table[dwSize].dwRemotePort & 0x00FF) << 8);
				std::cout<<std::setw(22)<<ostr.str();
				std::cout<<" ";
			}

			// PID
			std::cout<<std::setw(5)<<lpBuffer->table[dwSize].dwProcessId;
			std::cout<<std::endl;
		}
	}

	HeapFree(GetProcessHeap(),0,lpBuffer);

	return 0;
}
