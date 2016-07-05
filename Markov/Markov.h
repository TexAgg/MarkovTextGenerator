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
	int order;
	std::string input_text;
	// A map of strings to a vector of strings.
	std::map<std::string, std::vector<std::string>> chain;

public:
	Markov(std::string input, int ord=1);
	~Markov();

}; // !Markov class

} // !Namespace matt

#endif // !MARKOV_H