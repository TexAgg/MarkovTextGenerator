#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>‌​

#include "Markov.h"

namespace markov 
{

// TODO: Fix floating point exception on 1 or 0 length input.
Markov::Markov(std::string input, int ord): 
	order(ord)
{	
	input_texts.push_back(utility::strip(input));
	// Create a vector of all the words.
	std::vector<std::string> strings;
	// http://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring
	boost::split(strings, input, boost::is_any_of(", "), boost::token_compress_on);
	// Arbitrarily set the limit to the number of words in the input text.
	limit = strings.size();

	// Get frequencies.
	for (int i = 0; i < strings.size()-order + 1; i++)
	{
		// Combine ord elements of strings, starting at i.
		std::string combined = utility::combine(strings, order, i);
		// Trim the string.
		boost::trim_right(combined);
		// Add the string to the chain and map it to a vector of following strings.
		chain.insert(std::pair<std::string, std::vector< std::string> >(combined, std::vector<std::string>()));
		// Avoid range errors.
		if (i + ord < strings.size())
		{
			// Push back the string ord words ahead of i.
			chain[combined].push_back(strings[i + order]);
		}
	}
}

Markov::~Markov()
{
	// No pointers are used so this doesn't need to be finished.
}

void Markov::add_input(std::string input)
{
	input = utility::strip(input);
	input_texts.push_back(input);

	// Split the new string into a vector of strings.
	std::vector<std::string> strings;
	boost::split(strings, input, boost::is_any_of(", "), boost::token_compress_on);

	// Add each element to the frequency table.
	// TODO: Rewrite the loop as a private function?
	for (int i = 0; i < strings.size() - order + 1; i++)
	{
		std::string combined = utility::combine(strings, order, i);
		boost::trim_right(combined);

		if (i + order < strings.size())
		{
			chain[combined].push_back(strings[i + order]);
		}
	}
}

std::string Markov::generate(int lim)
{
	limit = lim;
	
	std::string output;
	srand(time(NULL));

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
	elem = utility::array_rand(chain[elem]);

	// 3. Append this to the output string.
	output += " " + elem;

	// 4. Change elem to the random element from elem.second.
	// 5. Continue until the size of elem.second == 0.
	int i = 0;
	while (chain[elem].size() != 0)
	{
		elem = utility::array_rand(chain[elem]);
		output += " " + elem;
		// http://stackoverflow.com/a/11765524/5415895
		if (!chain.count(elem)) 
		{
			// Break if the word has nothing following it.
			break;
		}
		i++;
		if (i == limit)
		{
			// Break if we have reached the limit.
			break;
		}
	}

	return output;
}

std::string Markov::generate()
{
	// Pass the default value: the member variable.
	return Markov::generate(limit);
}

} // !Namespace markov