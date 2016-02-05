#include "netstat.hpp"
#include "netstat_util.hpp"

int main()
{
	netstat_list_t netstats=netstat();
	netstat_list_print(netstats);
	return 0;
}
