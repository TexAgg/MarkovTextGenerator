#include "Markov.h"

namespace matt 
{

Markov::Markov(std::string input, int ord): 
	input_text(input),
	order(ord)
{
	std::vector<std::string> strings = utility::split(input, ' ');

	chain.insert(std::pair<std::string, std::vector<std::string>>(utility::combine(strings, ord), std::vector<std::string>{strings[1]}));
	for (int i = 0; i < strings.size()-1; i++)
	{

	}
}


Markov::~Markov()
{
}

} // !Namespace matt