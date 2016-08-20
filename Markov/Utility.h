#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace utility
{

std::string combine(std::vector<std::string> vec, int size, int start = 0);

std::string get_first_word(std::string str);

std::string array_rand(std::vector<std::string> vec);

bool check_sentence_end(std::string str);

std::string strip(std::string str);

}

#endif // !UTILITY_H