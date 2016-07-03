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
*/
std::string combine(std::vector<std::string> vec, int size)
{
	std::string str;
	for (int i = 0; i < size; i++)
	{
		str += vec.at(i);
		if (i != 0 || i != size - 1)
			str += " ";
	}
	return str;
}

}