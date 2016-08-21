/*
	Uses Boost's Python library to create a Python
	module wrapping the Markov class.
*/

#include <string>

#include <boost/python.hpp>

#include "Markov.h"

// Create a Python module named markovp (MarkovPython).
BOOST_PYTHON_MODULE(markovp) 
{
    // An established convention for using boost.python.
    using namespace boost::python;

	// Create pointers to both overloads of the generate function.
	//http://stackoverflow.com/a/31968302/5415895
	std::string (matt::Markov::*gen1)(int) = &matt::Markov::generate;
	std::string (matt::Markov::*gen2)() = &matt::Markov::generate;

	/*
		Expose the class matt::Markov to the module. 
		Only the public methods need to be exposed.
	*/
	class_<matt::Markov>("Markov", init<std::string, int>())
		.def("generate", gen1)
		.def("generate", gen2)
		.def("add_input", &matt::Markov::add_input);
}