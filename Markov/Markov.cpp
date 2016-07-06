#include "Markov.h"

namespace matt 
{

/**
	Constructor for Markov object.

	@param string input The string to use as an
	initial state.
	@param int ord The order of the Markov Chain.
	Defaults to 1.
*/
Markov::Markov(std::string input, int ord): 
	input_text(input),
	order(ord)
{
	std::vector<std::string> strings = utility::split(input, ' ');
	limit = strings.size();

	// Get frequencies.
	for (int i = 0; i < strings.size()-ord+1; i++)
	{
		std::string combined = utility::rtrim(utility::combine(strings, ord, i));
		chain.insert(std::pair<std::string, std::vector<std::string>>(combined, std::vector<std::string>()));
		if (i+ord < strings.size())
			chain[combined].push_back(strings[i + ord]);
	}
	// Just to have a place to break for debugging.
	int five = 5;
}

Markov::~Markov()
{
}

std::string Markov::generate()
{
	std::string output;

	/*
		1. Get random starting point from chain, elem, 
		and append it to output.
		2. Select a random element from the vector elem.second,
		3. Append this to the output string.
		4. Change elem to the random element from elem.second.
		5. Continue until the size of elem.second==0.
		6. Profit.

		Remember to make sure this works for other cases of order.
		(TODO!)
	*/

	// 1. Get random starting point from chain, elem.
	std::string elem = chain.begin()->first;
	output = elem;

	// 2. Select a random element from the vector elem.second.
	elem = utility::array_rand(chain.at(elem));

	// 3. Append this to the output string.
	output += " " + elem;

	// 4. Change elem to the random element from elem.second.
	// 5. Continue until the size of elem.second == 0.
	int i = 0;
	while (chain.at(elem).size() != 0)
	{
		elem = utility::array_rand(chain.at(elem));
		output += " " + elem;
		// http://stackoverflow.com/a/11765524/5415895
		if (!chain.count(elem)) 
			break;
		i++;
		if (i == limit)
			break;
	}

	return output;
}

} // !Namespace matt