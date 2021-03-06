#ifndef MARKOV_H
#define MARKOV_H

#include <vector>
#include <string>
#include <map>

#include "Utility.h"

namespace markov 
{

class Markov
{
private:

	/** Number of words to use as current state. */
	int order;
	/** A vector of all the input texts. */
	std::vector<std::string> input_texts;
	/**
	* A map of strings to a vector of strings.
	* Also, the frequency table.
	*/
	std::map<std::string, std::vector<std::string>> chain;
	/** Maximum number of words generated, to prevent infinite loops. */
	int limit;
	// All of the possible strings to start the generated text with.
	std::vector<std::string> start_points;

public:

	/**
	* Constructor for Markov object.
	*
	* @param string input The string to use as an
	* initial state.
	* @param int ord The order of the Markov Chain.
	* Defaults to 1.
	*/
	Markov(std::string input = " ", int ord = 1);
	~Markov();
	
	/** Add an additional text to analyze. */
	void add_input(std::string input);
	/** 
	* Create output roughly lim words long.
	* For some reason it isn't exact,
	* which needs to be fixed.
	* 
	* @param int lim The length of the output.
	*/	
	std::string generate(int lim);
	/** Create output. */
	std::string generate();

}; // !Markov class

} // !Namespace markov

#endif // !MARKOV_H