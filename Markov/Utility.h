#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <time.h>   

namespace utility
{

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

std::string combine(std::vector<std::string> vec, int size, int start = 0);

std::string get_first_word(std::string str);

std::string array_rand(std::vector<std::string> vec);

// http://stackoverflow.com/a/217605/5415895
std::string &ltrim(std::string &s);
std::string &rtrim(std::string &s);
std::string &trim(std::string &s);

}

#endif // !UTILITY_H