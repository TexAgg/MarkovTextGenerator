#include <iostream>

#include "Markov.h"
#include "Utility.h"

int main() 
{
	std::string file1 = "nodejs.txt";
	std::string file2 = "nodejs2.txt";

	std::string str1 = markov::utility::file_to_string(file1);

	markov::Markov mark = markov::Markov(str1,1);
	std::cout << mark.generate() << std::endl;

	std::string str2 = markov::utility::file_to_string(file2);
	mark.add_input(str2);
	std::cout << mark.generate() << std::endl;
}