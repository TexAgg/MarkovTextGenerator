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
#include <sstream>
#include <fstream>

#include "Utility.h"

namespace utility
{

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

std::string array_rand(std::vector<std::string> vec)
{
	// Avoid floating point error.
	// http://stackoverflow.com/questions/4236853/floating-point-exception-c-why-and-what-is-it
	if (vec.size() == 0)
		return "";
	else
	{
		int rank = rand() % vec.size();
		return vec[rank];
	}
}

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

std::string file_to_string(std::string filename)
{
	// http://stackoverflow.com/a/2602258/5415895
	std::ifstream infile(filename);
	std::stringstream buffer;
	buffer << infile.rdbuf();
	return buffer.str();
}

}