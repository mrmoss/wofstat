#include <cstdlib>
#include <iostream>
#include "netstat.hpp"
#include "netstat_util.hpp"
#include <stdexcept>

void show_help(const int return_code)
{
	std::ostream* ostr=&std::cout;

	if(return_code!=0)
		ostr=&std::cerr;

	*ostr<<"  Usage:  ./mikestat [-j][-h][--help]"<<std::endl;
	*ostr<<"  --help  Show help menu."<<std::endl;
	*ostr<<"  -h      Print in human readable format (default)."<<std::endl;
	*ostr<<"  -j      Print in JSON format."<<std::endl;
	exit(return_code);
}

int main(int argc,char* argv[])
{
	try
	{
		bool human_readable=true;

		for(int ii=1;ii<argc;++ii)
		{
			std::string cli(argv[ii]);

			if(cli=="--help")
				show_help(0);
			else if(cli=="-h")
				human_readable=1;
			else if(cli=="-j")
				human_readable=0;
			else
				throw std::runtime_error("Unknown cli argument \""+cli+"\".");
		}

		netstat_list_t netstats=netstat();

		if(human_readable)
			print_human(netstats);
		else
			print_json(netstats);
	}
	catch(std::runtime_error& error)
	{
		std::cerr<<"Error - "<<error.what()<<std::endl;
		show_help(1);
	}
	catch(...)
	{
		std::cerr<<"Unknown error occured."<<std::endl;
		show_help(1);
	}

	return 0;
}
