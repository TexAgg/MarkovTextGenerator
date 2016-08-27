#include <string>
#include <iostream>

#include <boost/python.hpp>
#include <boost/python/list.hpp>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

// This file is over 10,000 lines long and makes compilation slow.
#include <json.hpp>

namespace buzzfeed
{

/**
* Returns a string representation of the JSON news feed
* from the Buzzfeed API.
*
* @return std:string A JSON encoded string containing the entire news feed.
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

/**
* Iterates through get_feed to return the titles of all the articles.
*/
boost::python::list get_titles()
{
	nlohmann::json j = nlohmann::json::parse(get_feed());

	//std::vector<std::string> titles;
	boost::python::list titles;

	// Iterate through j and get all values with key 'title'.
	for (nlohmann::json::iterator it = j["big_stories"].begin(); it != j["big_stories"].end(); it++)
	{
		std::string temp = it->at("title");
		// Uncomment for debugging.
		//std::cout << temp << std::endl;
		titles.append(temp);
	}

	return titles;
}

} // !buzzfeed

// Create the module.
BOOST_PYTHON_MODULE(buzzfeed)
{
	using namespace boost::python;

	def("get_feed", &buzzfeed::get_feed);
	def("get_titles", &buzzfeed::get_titles);
}