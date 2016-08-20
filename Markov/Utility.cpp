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
#include <regex>

#include "Utility.h"

namespace utility
{

/**
* Combines the first size elements of a vector of strings.
*
* @param std::vector<std::string> vec A vector of strings.
* @param int size The number of elements to combine.
* @param int start The position in the vector to start at.
*/
std::string combine(std::vector<std::string> vec, int size, int start)
{
	std::string str;
	for (int i = start; i < start + size; i++)
	{
		str += vec.at(i);
		//if (i != size)
		str += " ";
	}
	return str;
}

std::string get_first_word(std::string str)
{
	std::stringstream ss(str);
	std::string word;
	getline(ss, word, ' ');
	return word;
}

/**
* Gets a random element from a vector of strings.
* The name is because of PHP's method.
* I should have used a template but I didn't
* want to deal with that.
*/
std::string array_rand(std::vector<std::string> vec)
{
	int rank = rand() % vec.size();
	return vec[rank];
}

/**
* Checks to see if a string is at the end of a sentence.
*/
bool check_sentence_end(std::string str)
{
	int len = str.length();
	std::string punct = str.substr(len - 1);
	if (punct == "!" || punct == "." || punct == "?")
		return true;
	else
		return false;
}

/**
* Strip input of special characters and replace them with spaces.
*/
std::string strip(std::string str)
{
	std::regex reg(" +|\n|\r|\f");
	std::string output = std::regex_replace(str, reg, " ");
	return output;
}

}