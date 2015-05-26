#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <string>
#include <sstream>

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

std::string dword_to_port(const uint32_t port)
{
        std::ostringstream ostr;
        ostr<<((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
        return ostr.str();
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








	strbuf buf2;
	void* data;
	int data_size=-1;
	int ret;
	int flags=0;

	reply_t reply;

	while(true)
	{
		buf2.maxlen=sizeof(reply);
		buf2.buf=(char*)&reply;
		ret=getmsg(fd,&buf2,NULL,&flags);

		if (ret<0)
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

		if(getmsg(fd,NULL,&buf2,&flags)>=0&&reply.opt_header.level==MIB2_TCP&&
			reply.opt_header.name==MIB2_TCP_CONN)
		{
			std::cout<<"Got data of size "<<buf2.len<<std::endl;
			data_size=buf2.len;
			break;
		}

		free(data);
	}

	if(data_size>=0)
	{
		for (mib2_tcpConnEntry_t* entry=(mib2_tcpConnEntry_t*)data;(char*)(entry+1)<=(char*)data+data_size;++entry)
		{
			std::cout<<uint32_t_to_ipv4(entry->tcpConnLocalAddress)<<":"<<
				dword_to_port(htons(entry->tcpConnLocalPort))<<"\t";
			std::cout<<uint32_t_to_ipv4(entry->tcpConnRemAddress)<<":"<<
				dword_to_port(htons(entry->tcpConnRemPort))<<"\t";
			std::cout<<entry->tcpConnState<<std::endl;
		}

		free(data);
	}








/*	std::cout<<"getting"<<std::endl;
	int flags=0;
	std::cout<<"\tgetmsg\t\t"<<getmsg(fd,&ctl.buf,NULL,&flags)<<std::endl;

	for(int ii=0;ii<ctl.buf.len;++ii)
		std::cout<<"\t["<<ii<<"]\t"<<(unsigned int)(unsigned char)ctl.buffer[ii]<<std::endl;
*/
	return 0;
}
