/*
	Main.cpp
	This is the main interface for the application.
*/

#include <iostream>

#include "Markov.h"
#include "Utility.h"

/**
* TODO: Accept command-line arguments.
* http://www.cplusplus.com/articles/DEN36Up4/
*/
int main(int argc, char ** argv) 
{
	if (argc < 2) 
	{
		// Insufficient arguments
		std::cout << "Usage: ./Main + <filename>";
		return 1;
	}

	std::cout << "Howdy!" << std::endl;
	std::cout << "The file input was " << argv[1] << ".\n" << std::endl;
	std::string filename = argv[1];

	std::string str = markov::utility::file_to_string(filename);
	//std::cout << str;

	markov::Markov mark = markov::Markov(str,1);
	std::cout << mark.generate() << std::endl;
}