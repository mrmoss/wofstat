#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stropts.h>

#include <cstring>

#include <sys/tihdr.h>
#include <inet/mib2.h>

class buffer_t
{
	public:
		char buffer[512];
		strbuf buf;

		buffer_t()
		{
			memset(buffer,0,512);
			buf.buf=(char*)buffer;
			buf.len=512;
		}
};

struct request_t
{
	T_optmgmt_req req_header;
	opthdr opt_header;
};

struct reply_t
{
	T_optmgmt_ack ack_header;
	opthdr opt_header;
};

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
                ostr<<std::hex<<std::setw(2)<<std::setfill('0')<<(unsigned int)(unsigned char)address[ii+0];
                ostr<<std::hex<<std::setw(2)<<std::setfill('0')<<(unsigned int)(unsigned char)address[ii+1];

                if(ii<14)
                        ostr<<":";
        }

        return ostr.str();
}

std::string dword_to_port(const uint32_t port)
{
        std::ostringstream ostr;
        ostr<<((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
        return ostr.str();
}

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

int main()
{
	std::cout<<"opening"<<std::endl;
	int fd=open("/dev/arp",O_RDWR);
	std::cout<<"\tfd\t\t"<<fd<<std::endl;
	std::cout<<"\tioctl tcp\t"<<ioctl(fd,I_PUSH,"tcp")<<std::endl;
	std::cout<<"\tioctl udp\t"<<ioctl(fd,I_PUSH,"udp")<<std::endl;
	std::cout<<std::endl;

	std::cout<<"putting"<<std::endl;

	request_t request;
	request.req_header.PRIM_type=T_SVR4_OPTMGMT_REQ;
	request.req_header.OPT_length=sizeof(request.opt_header);
	request.req_header.OPT_offset=(long)offsetof(request_t,opt_header);
	request.req_header.MGMT_flags=T_CURRENT;
	request.opt_header.level=MIB2_IP;
	request.opt_header.name=0;
	request.opt_header.len=0;

	strbuf buf;
	buf.len=sizeof(request);
	buf.buf=(char*)&request;

	std::cout<<"\tputmsg\t\t"<<putmsg(fd,&buf,NULL,0)<<std::endl;
	std::cout<<std::endl;

	while(true)
	{
		strbuf buf2;
		void* data=NULL;
		int flags=0;
		reply_t reply;
		buf2.maxlen=sizeof(reply);
		buf2.buf=(char*)&reply;
		int ret=getmsg(fd,&buf2,NULL,&flags);

		if(ret<0)
		{
			std::cout<<"ret<0"<<std::endl;
			break;
		}
		if (ret!=MOREDATA)
		{
			std::cout<<"moredata"<<std::endl;
			break;
		}
		if (reply.ack_header.PRIM_type != T_OPTMGMT_ACK)
		{
			std::cout<<"primtype"<<std::endl;
			break;
		}
		if ((unsigned int)buf2.len < sizeof(reply.ack_header))
		{
			std::cout<<"buf2len"<<std::endl;
			break;
		}
		if ((unsigned int)reply.ack_header.OPT_length < sizeof(reply.opt_header))
		{
			std::cout<<"optlength"<<std::endl;
			break;
		}

		data=malloc(reply.opt_header.len);

		if(data==NULL)
			break;

		buf2.maxlen = reply.opt_header.len;
		buf2.buf = (char*)data;
		flags = 0;

		if(getmsg(fd,NULL,&buf2,&flags)>=0)
		{
			if(reply.opt_header.level==MIB2_TCP&&reply.opt_header.name==MIB2_TCP_CONN)
			{
				for (mib2_tcpConnEntry_t* entry=(mib2_tcpConnEntry_t*)data;(char*)(entry+1)<=(char*)data+buf2.len;++entry)
				{
					std::cout<<"tcp4\t";
					std::cout<<uint32_t_to_ipv4(entry->tcpConnLocalAddress)<<":"<<
						dword_to_port(htons(entry->tcpConnLocalPort))<<"\t";
					std::cout<<uint32_t_to_ipv4(entry->tcpConnRemAddress)<<":"<<
						dword_to_port(htons(entry->tcpConnRemPort))<<"\t";
					std::cout<<entry->tcpConnState<<std::endl;
				}
			}

			if(reply.opt_header.level==MIB2_TCP6&&reply.opt_header.name==MIB2_TCP6_CONN)
			{
				for (mib2_tcp6ConnEntry_t* entry=(mib2_tcp6ConnEntry_t*)data;(char*)(entry+1)<=(char*)data+buf2.len;++entry)
				{
					std::cout<<"tcp6\t";
					std::cout<<uint8_t_16_to_ipv6(entry->tcp6ConnLocalAddress.s6_addr)<<":"<<
						dword_to_port(htons(entry->tcp6ConnLocalPort))<<"\t";
					std::cout<<uint8_t_16_to_ipv6(entry->tcp6ConnRemAddress.s6_addr)<<":"<<
						dword_to_port(htons(entry->tcp6ConnRemPort))<<"\t";
					std::cout<<entry->tcp6ConnState<<std::endl;
				}
			}

			if(reply.opt_header.level==MIB2_UDP&&reply.opt_header.name==MIB2_UDP_ENTRY)
			{
				for (mib2_udpEntry_t* entry=(mib2_udpEntry_t*)data;(char*)(entry+1)<=(char*)data+buf2.len;++entry)
				{
					std::cout<<"udp4\t";
					std::cout<<uint32_t_to_ipv4(entry->udpLocalAddress)<<":"<<
						dword_to_port(htons(entry->udpLocalPort))<<"\t";
					std::cout<<"0.0.0.0:0\t";
					std::cout<<"-"<<std::endl;
				}
			}

			if(reply.opt_header.level==MIB2_UDP6&&reply.opt_header.name==MIB2_UDP6_ENTRY)
			{
				for (mib2_udp6Entry_t* entry=(mib2_udp6Entry_t*)data;(char*)(entry+1)<=(char*)data+buf2.len;++entry)
				{
					std::cout<<"udp6\t";
					std::cout<<uint8_t_16_to_ipv6(entry->udp6LocalAddress.s6_addr)<<":"<<
						dword_to_port(htons(entry->udp6LocalPort))<<"\t";
					std::cout<<"0000:0000:0000:0000:0000:0000:0000:0000:0\t";
					std::cout<<"-"<<std::endl;
				}
			}
		}

		free(data);
	}

	return 0;
}
