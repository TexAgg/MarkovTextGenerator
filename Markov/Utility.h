#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace utility
{

/**
* Combines the first size elements of a vector of strings.
*
* @param std::vector<std::string> vec A vector of strings.
* @param int size The number of elements to combine.
* @param int start The position in the vector to start at.
*/
std::string combine(std::vector<std::string> vec, int size, int start = 0);

/**
* Get the first word in a string.
*/
std::string get_first_word(std::string str);

/**
* Gets a random element from a vector of strings.
* The name is because of PHP's method.
* I should have used a template but I didn't
* want to deal with that.
*/
std::string array_rand(std::vector<std::string> vec);

/**
* Checks to see if a string is at the end of a sentence.
*/
bool check_sentence_end(std::string str);

/**
* Strip input of special characters and replace them with spaces.
*/
std::string strip(std::string str);

}

#endif // !UTILITY_H