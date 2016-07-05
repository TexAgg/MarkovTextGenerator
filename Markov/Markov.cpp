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
}

Markov::~Markov()
{
}

std::string Markov::generate()
{
	std::string output = chain.begin()->first;
	output += get_next_word(output);
	std::vector<std::string> vec = utility::split(output, ' ');
	std::string str = vec[vec.size()-2] + " " + vec[vec.size()-1] + " ";
	while (get_next_word(str) != "")
	{
		output += get_next_word(str);
		vec = utility::split(output, ' ');
		str = vec[vec.size() - 2] + " " + vec[vec.size() - 1] + " ";
	}

	return output;
}

/**
	
*/
std::string Markov::get_next_word(std::string str)
{
	if (str.length() == 0 || chain[str ].size() == 0) return "";
	std::vector<std::string> vec = utility::split(str, ' ');
	//if (vec.size() == 0) return "";
	std::string newstring = vec[order - 1] + " " + utility::array_rand(chain[str]);
	return utility::split(newstring, ' ')[1] + " ";
}

} // !Namespace matt