#include "generate.hpp"

/*
std::string proto;
std::string local_address;
std::string foreign_address;
uint16_t local_port;
uint16_t foreign_port;
std::string state;
std::string pid;
*/

#include <sstream>

std::string generate_iptables(const netstat_list_t& netstats)
{
	std::ostringstream ostr;

	for(size_t ii=0;ii<netstats.size();++ii)
	{
		if((netstats[ii].local_port>0&&netstats[ii].local_port<1024)&&(netstats[ii].foreign_port!=0&&netstats[ii].foreign_port<1024))
		{
			ostr<<"ambiguous"<<std::endl;
			continue;
		}

		if((netstats[ii].local_port>0&&netstats[ii].local_port<1024)||(netstats[ii].foreign_port!=0&&netstats[ii].foreign_port<1024))
		{
			ostr<<"iptables";

			if(netstats[ii].proto[3]=='6')
				ostr<<'6';

			ostr<<" --append ";

			bool dir=true;

			if(netstats[ii].local_port>0&&netstats[ii].local_port<1024)
			{
				ostr<<"INPUT";
			}
			else
			{
				ostr<<"OUTPUT";
				dir=false;
			}

			ostr<<" -p "<<netstats[ii].proto.substr(0,3);

			if(netstats[ii].local_port>0&&netstats[ii].local_port<1024)
			{
				if(!dir)
				{
					ostr<<" -d "<<netstats[ii].local_address;
					ostr<<" --dport "<<netstats[ii].local_port;
				}
				else
				{
					ostr<<" -s "<<netstats[ii].local_address;
					ostr<<" --sport "<<netstats[ii].local_port;
				}
			}

			if(netstats[ii].foreign_port!=0&&netstats[ii].foreign_port<1024)
			{
				if(!dir)
				{
					ostr<<" -s "<<netstats[ii].foreign_address;
					ostr<<" --sport "<<netstats[ii].foreign_port;
				}
				else
				{
					ostr<<" -d "<<netstats[ii].foreign_address;
					ostr<<" --dport "<<netstats[ii].foreign_port;
				}
			}

			ostr<<" --jump ACCEPT";
			ostr<<std::endl;
		}
	}

	return ostr.str();
}