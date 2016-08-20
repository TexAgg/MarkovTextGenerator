#ifndef MARKOV_H
#define MARKOV_H

#include <vector>
#include <string>
#include <map>

#include "Utility.h"

namespace matt 
{

class Markov
{
	/** Number of words to use as current state. */
	int order;
	/** A vector of all the input texts. */
	std::vector<std::string> input_texts;
	/**
	* A map of strings to a vector of strings.
	* Also, the frequency table.
	*/
	std::map<std::string, std::vector<std::string>> chain;
	/** Maximum number of words, to prevent infinite loops. */
	int limit;

public:

	/**
	* Constructor for Markov object.
	*
	* @param string input The string to use as an
	* initial state.
	* @param int ord The order of the Markov Chain.
	* Defaults to 1.
	*/
	Markov(std::string input, int ord=1);
	~Markov();

	void add_input(std::string input);

	/** Create output. */
	std::string generate();

}; // !Markov class

} // !Namespace matt

#endif // !MARKOV_H