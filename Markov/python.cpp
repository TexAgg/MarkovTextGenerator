#include <boost/python.hpp>
#include "Markov.h"

BOOST_PYTHON_MODULE(markovp) 
{
    // An established convention for using boost.python.
    using namespace boost::python;

	class_<matt::Markov>("Markov", init<std::string, int>())
		.def("generate", &matt::Markov::generate);
}