#include <cstdlib>
#include <iostream>
#include "natstat.hpp"
#include "natstat_util.hpp"
#include "string_util.hpp"
#include <stdexcept>

void show_help()
{
	std::cerr<<"  Usage:  ./natstat [--help][h][--wof][-w]"<<std::endl;
	std::cerr<<"  --help, -h  Show help menu."<<std::endl;
	std::cerr<<"  --wof, -w   Print in wof format."<<std::endl;
}

int main(int argc,char* argv[])
{
	try
	{
		std::cerr<<"Not Another Netstat"<<std::endl;
		bool human_readable=true;
		for(int ii=1;ii<argc;++ii)
		{
			std::string cli(argv[ii]);
			if(cli=="--help"||cli=="-h")
			{
				show_help();
				return 1;
			}
			else if(cli=="--wof"||cli=="-w")
			{
				human_readable=false;
			}
			else
			{
				throw std::runtime_error("Unknown cli argument \""+cli+"\".");
			}
		}
		natstat_list_t natstats(natstat());
		if(human_readable)
			print_human(natstats);
		else
			print_wof(natstats);
	}
	catch(std::runtime_error& error)
	{
		std::cerr<<"Error - "<<error.what()<<std::endl;
		show_help();
		exit(1);
	}
	catch(...)
	{
		std::cerr<<"Unknown error occured."<<std::endl;
		show_help();
		exit(1);
	}
	return 0;
}
