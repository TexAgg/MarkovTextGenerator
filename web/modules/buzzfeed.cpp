#include <string>

#include <boost/python.hpp>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

std::string get_titles()
{
	std::string url = "http://www.buzzfeed.com/api/v2/feeds/news";
	web::http::client::http_client client(U(url));
	
	pplx::task<web::http::http_response> request_task = client.request(web::http::methods::GET);
	
	return "dawg";
}

// Create the module.
BOOST_PYTHON_MODULE(buzzfeed)
{
	using namespace boost::python;
	def("get_titles", &get_titles);
}