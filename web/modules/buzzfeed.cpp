#include <string>

#include <boost/python.hpp>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

#include <json.hpp>

namespace buzzfeed
{

/**
* Returns a string representation of the JSON news feed
* from the Buzzfeed API.
*/
std::string get_feed()
{
	std::string url = "http://www.buzzfeed.com/api/v2/feeds/news";
	// Declare the client.
	web::http::client::http_client client(U(url));
	// response is a task that, once executed, returns an http response.
	pplx::task<web::http::http_response> response = client.request(web::http::methods::GET);
	// The multiple calls to get return the result of the executed task.
	// https://msdn.microsoft.com/en-us/library/hh750017.aspx
	std::string body = response.get().extract_string().get();

	return body;
}

// Deprecated I guess.
void get_titles()
{
	nlohmann::json j = nlohmann::json::parse(get_feed());

	// Iterate through j and get all values with key 'title'.
}

} // !buzzfeed

// Create the module.
BOOST_PYTHON_MODULE(buzzfeed)
{
	using namespace boost::python;

	def("get_feed", &buzzfeed::get_feed);
}