#ifndef MARKOV_H
#define MARKOV_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Utility.h"

namespace matt 
{

class Markov
{
	// Number of words.
	int order;
	std::string input_text;
	// A map of strings to a vector of strings.
	// Also, the frequency table.
	std::map<std::string, std::vector<std::string>> chain;

public:
	Markov(std::string input, int ord=1);
	~Markov();

	// Create output.
	std::string generate();

}; // !Markov class

} // !Namespace matt

#endif // !MARKOV_H