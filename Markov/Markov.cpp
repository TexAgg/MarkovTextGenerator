#include "Markov.h"

namespace matt 
{

Markov::Markov(std::string input, int ord): 
	input_text(input),
	order(ord)
{
	std::vector<std::string> strings = utility::split(input, ' ');

	//chain.insert(std::pair<std::string, std::vector<std::string>>(utility::combine(strings, ord), std::vector<std::string>{strings[ord]}));
	for (int i = 0; i < strings.size()-ord+1; i++)
	{
		std::string combined = utility::combine(strings, ord, i);
		//combined = utility::trim(combined);
		//std::cout << combined << std::endl;
		chain.insert(std::pair<std::string, std::vector<std::string>>(combined, std::vector<std::string>()));
		if (i+ord < strings.size())
			chain[combined].push_back(strings[i + ord]);
	}
	int five = 5;
}

Markov::~Markov()
{
}

} // !Namespace matt