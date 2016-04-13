#include <cstdlib>
#include <iostream>
#include "wofstat.hpp"
#include "string_util.hpp"
#include <stdexcept>

void show_help()
{
	std::cerr<<"  Usage:  ./wofstat [--help][--continue][-c][--wof][-w]"<<std::endl;
	std::cerr<<"  --help            Show help menu."<<std::endl;
	std::cerr<<"  --continue, -c    Continually capture."<<std::endl;
	std::cerr<<"  --wof, -w         Print in wof format."<<std::endl;
}

int main(int argc,char* argv[])
{
	try
	{
		std::cerr<<"Walls of Fire - Universal netstat program for Linux, Windows, BSD, OSX, and Solaris."<<std::endl;
		bool human_readable=true;
		bool continue_capture=false;
		for(int ii=1;ii<argc;++ii)
		{
			std::string cli(argv[ii]);
			if(cli=="--help")
			{
				show_help();
				return 1;
			}
			if(cli=="--continue"||cli=="-c")
				continue_capture=true;
			else if(cli=="--wof"||cli=="-w")
				human_readable=false;
			else
				throw std::runtime_error("Unknown cli argument \""+cli+"\".");
		}
		wofstat_list_t wofstats(wofstat());
		if(human_readable)
			print_human(wofstats);
		else
			print_wof(wofstats);
		while(continue_capture)
		{
			wofstat_list_t wofstats_more(wofstat());
			wofstat_list_t wofstats_to_print;
			for(size_t ii=0;ii<wofstats_more.size();++ii)
			{
				bool found=false;
				for(size_t jj=0;jj<wofstats.size();++jj)
				{
					if(wofstats_more[ii]==wofstats[jj])
					{
						found=true;
						break;
					}
				}
				if(!found)
					wofstats_to_print.push_back(wofstats_more[ii]);
			}
			if(human_readable)
				print_human(wofstats_to_print,false);
			else
				print_wof(wofstats_to_print);
			for(size_t ii=0;ii<wofstats_to_print.size();++ii)
				wofstats.push_back(wofstats_to_print[ii]);
		}
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
