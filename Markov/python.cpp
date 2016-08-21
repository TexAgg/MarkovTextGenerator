/*
	Uses Boost's Python library to create a Python
	module wrapping the Markov class.
*/

#include <boost/python.hpp>

#include "Markov.h"

// Create a Python module named markovp (MarkovPython).
BOOST_PYTHON_MODULE(markovp) 
{
    // An established convention for using boost.python.
    using namespace boost::python;

	/*
		Expose the class matt::Markov to the module. 
		Only the public methods need to be exposed.
	*/
	class_<matt::Markov>("Markov", init<std::string, int>())
		.def("generate", &matt::Markov::generate)
		.def("add_input", &matt::Markov::add_input);
}