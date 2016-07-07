#include "Utility.h"

namespace utility
{
/**
Splits a string into a vector of strings using the deliminator.
http://stackoverflow.com/a/236803/5415895
*/
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}

/**
Splits a string into a vector of strings using the deliminator.
http://stackoverflow.com/a/236803/5415895

@param std::string& s The string to split.
@param char delim The deliminator to use to split the string.
*/
std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

/**
	Combines the first size elements of a vector of strings.

	@param std::vector<std::string> vec A vector of strings.
	@param int size The number of elements to combine.
	@param int start The position in the vector to start at.
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
	Gets a random element from a vector of strings.
	The name is because of PHP's method.
	I should have used a template but I didn't
	want to deal with that.
*/
std::string array_rand(std::vector<std::string> vec)
{
	//srand(time(NULL));
	int rank = rand() % vec.size();
	return vec[rank];
}

// trim from start
std::string &ltrim(std::string &s) 
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
std::string &rtrim(std::string &s) 
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// trim from both ends
std::string &trim(std::string &s) 
{
	return ltrim(rtrim(s));
}

/**
	Checks to see if a string is at the end of a sentence.
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

std::string strip(std::string str)
{
	std::regex reg(" +|\n|\r|\f");
	std::string output = std::regex_replace(str, reg, " ");
	return output;
}

}