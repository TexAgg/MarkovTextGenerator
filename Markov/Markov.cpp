#include "Markov.h"

namespace matt 
{

Markov::Markov(std::string input, int ord): 
	input_text(input),
	order(ord)
{
	std::vector<std::string> strings = utility::split(input, ' ');

	chain.insert(std::pair<std::string, std::vector<std::string>>(utility::combine(strings, ord), std::vector<std::string>{strings[ord]}));
	for (int i = ord; i < strings.size()-ord; i++)
	{
		std::string combined = utility::combine(strings, ord, i);
		chain.insert(std::pair<std::string, std::vector<std::string>>(combined, std::vector<std::string>()));
	}
	int five = 5;
}

Markov::~Markov()
{
}

} // !Namespace matt