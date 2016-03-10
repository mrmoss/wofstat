#ifndef STRING_UTIL_HPP
#define STRING_UTIL_HPP

#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

typedef std::vector<std::string> list_t;
typedef std::vector<list_t> table_t;
typedef std::pair<std::string,std::string> lookup_t;
typedef std::vector<lookup_t> lookup_list_t;

std::string ipv6_prettify(std::string addr);

std::string u32_to_ipv4(const uint32_t address);
std::string hex_to_ipv4(const std::string& hex);

std::string hex_to_ipv6(const std::string& hex);
std::string u8x16_to_ipv6(const uint8_t address[16]);

uint16_t u16_to_port(const uint16_t port);
uint16_t hex_to_port(const std::string& hex);

#if(defined(_WIN32)||defined(__CYGWIN__))
	#include <Windows.h>
	uint16_t dword_to_port(const DWORD port);
#endif

std::string to_string(const uint32_t val);
bool file_to_string(const std::string& filename,std::string& data);
std::string replace_all(std::string str,const std::string& find,const std::string& replace);

list_t string_to_lines(const std::string& str);
list_t read_line_columns(const std::string& line);

uint32_t hex_to_decimal(const std::string& hex);
std::string to_string(const uint32_t val);
std::string to_lower(std::string str);

bool is_int(const std::string& str);
bool is_hex(const std::string& hex);

bool starts_with(const std::string& str,const std::string& prefix);
bool ends_with(const std::string& str,const std::string& suffix);

#endif
