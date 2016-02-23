#include "string_util.hpp"

#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <sstream>

std::string u32_to_ipv4(const uint32_t address)
{
	std::ostringstream ostr;
	ostr<<(uint32_t)((uint8_t*)&address)[0]<<"."<<
		(uint32_t)((uint8_t*)&address)[1]<<"."<<
		(uint32_t)((uint8_t*)&address)[2]<<"."<<
		(uint32_t)((uint8_t*)&address)[3];
	return ostr.str();
}

std::string hex_to_ipv4(const std::string& hex)
{
	if(hex.size()!=8||!is_hex(hex))
		throw std::runtime_error("hex_to_ipv4 - Invalid hex value \""+hex+"\".");

	std::ostringstream ostr;
	ostr<<hex_to_decimal(hex.substr(6,2))<<".";
	ostr<<hex_to_decimal(hex.substr(4,2))<<".";
	ostr<<hex_to_decimal(hex.substr(2,2))<<".";
	ostr<<hex_to_decimal(hex.substr(0,2));

	return ostr.str();
}

std::string hex_to_ipv6(const std::string& hex)
{
	if(hex.size()!=32||!is_hex(hex))
		throw std::runtime_error("hex_to_ipv6 - Invalid hex value \""+hex+"\".");

	std::string lower_hex=to_lower(hex);
	std::ostringstream ostr;
	ostr<<lower_hex.substr(2,2)<<lower_hex.substr(0,2)<<":";
	ostr<<lower_hex.substr(6,2)<<lower_hex.substr(4,2)<<":";
	ostr<<lower_hex.substr(10,2)<<lower_hex.substr(8,2)<<":";
	ostr<<lower_hex.substr(14,2)<<lower_hex.substr(12,2)<<":";
	ostr<<lower_hex.substr(18,2)<<lower_hex.substr(16,2)<<":";
	ostr<<lower_hex.substr(22,2)<<lower_hex.substr(20,2)<<":";
	ostr<<lower_hex.substr(26,2)<<lower_hex.substr(24,2)<<":";
	ostr<<lower_hex.substr(30,2)<<lower_hex.substr(28,2);

	return ostr.str();
}

std::string u8x16_to_ipv6(const uint8_t address[16])
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

uint16_t u16_to_port(const uint16_t port)
{
	return ((((uint32_t)((uint8_t*)&port)[0])<<8)+((uint8_t*)&port)[1]);
}

uint16_t hex_to_port(const std::string& hex)
{
	if(hex.size()!=4||!is_hex(hex))
		throw std::runtime_error("hex_to_port - Invalid hex value \""+hex+"\".");

	return (hex_to_decimal(hex.substr(0,2))<<8)+hex_to_decimal(hex.substr(2,2));
}

#if(defined(_WIN32)||defined(__CYGWIN__))
	uint16_t dword_to_port(const DWORD port)
	{
		return u16_to_port((uint16_t)port);
	}
#endif

bool file_to_string(const std::string& filename,std::string& data)
{
	char buffer;
	std::ifstream istr(filename.c_str(),std::ios_base::in|std::ios_base::binary);
	istr.unsetf(std::ios_base::skipws);

	if(!istr)
		return false;

	data="";

	while(istr>>buffer)
		data+=buffer;

	istr.close();
	return true;
}

std::string replace_all(std::string str,const std::string& find,const std::string& replace)
{
	size_t pos=0;

	while((pos=str.find(find,pos))!=std::string::npos)
	{
		str.replace(pos,find.size(),replace);
		pos+=replace.size();
	}

	return str;
}

list_t string_to_lines(const std::string& str)
{
	std::istringstream istr(str.c_str());
	list_t lines;
	std::string line;

	while(std::getline(istr,line))
		lines.push_back(line);

	return lines;
}

list_t read_line_columns(const std::string& line)
{
	std::istringstream istr(line);
	list_t columns;
	std::string column;

	while(istr>>column)
		columns.push_back(column);

	return columns;
}

uint32_t hex_to_decimal(const std::string& hex)
{
	if(hex.size()!=2)
		throw std::runtime_error("hex_to_decimal - Invalid single byte hex value \""+hex+"\".");

	if(!is_hex(hex))
		throw std::runtime_error("hex_to_decimal - Invalid single byte hex value \""+hex+"\".");

	std::string lower_hex=to_lower(hex);
	unsigned int decimal=0;

	if(lower_hex[1]>='0'&&lower_hex[1]<='9')
		decimal+=lower_hex[1]-'0';
	if(lower_hex[1]>='a'&&lower_hex[1]<='f')
		decimal+=10+lower_hex[1]-'a';

	if(lower_hex[0]>='0'&&lower_hex[0]<='9')
		decimal+=(lower_hex[0]-'0')<<4;
	if(lower_hex[0]>='a'&&lower_hex[0]<='f')
		decimal+=(10+lower_hex[0]-'a')<<4;

	return decimal;
}

std::string to_string(const uint32_t val)
{
	std::ostringstream ostr;
	ostr<<val;
	return ostr.str();
}

std::string to_lower(std::string str)
{
	std::transform(str.begin(),str.end(),str.begin(),tolower);
	return str;
}

bool is_int(const std::string& str)
{
	for(size_t ii=0;ii<str.size();++ii)
		if(str[ii]<'0'||str[ii]>'9')
			return false;

	return str.size()!=0;
}

bool is_hex(const std::string& hex)
{
	std::string lower_hex=to_lower(hex);

	for(size_t ii=0;ii<lower_hex.size();++ii)
		if(!(lower_hex[ii]>='0'&&lower_hex[ii]<='9')&&!(lower_hex[ii]>='a'&&lower_hex[ii]<='f'))
			return false;

	return true;
}

bool starts_with(const std::string& str,const std::string& prefix)
{
	return (str.size()>=prefix.size()&&str.compare(0,prefix.size(),prefix)==0);
}

bool ends_with(const std::string& str,const std::string& suffix)
{
	return (str.size()>=suffix.size()&&starts_with(str.substr(str.size()-suffix.size(),suffix.size()),suffix));
}
