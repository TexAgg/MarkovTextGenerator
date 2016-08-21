/*
	Main.cpp
	This is the main interface for the application.
*/

#include <iostream>

#include "Markov.h"
#include "Utility.h"

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

	std::string str = utility::file_to_string(filename);
	//std::cout << str;

	matt::Markov mark = matt::Markov(str,1);
	std::cout << mark.generate() << std::endl;
}