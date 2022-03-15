#include "HTTPMethod.h"

using namespace hspp;

const HTTPMethod HTTPMethod::GET = HTTPMethod("GET");
const HTTPMethod HTTPMethod::HEAD = HTTPMethod("HEAD");
const HTTPMethod HTTPMethod::POST = HTTPMethod("POST");
const HTTPMethod HTTPMethod::PUT = HTTPMethod("PUT");
const HTTPMethod HTTPMethod::DELETE = HTTPMethod("DELETE");
const HTTPMethod HTTPMethod::CONNECT = HTTPMethod("CONNECT");
const HTTPMethod HTTPMethod::OPTIONS = HTTPMethod("OPTIONS");
const HTTPMethod HTTPMethod::TRACE = HTTPMethod("TRACE");
const HTTPMethod HTTPMethod::PATCH = HTTPMethod("PATCH");

const HTTPMethod& HTTPMethod::forName(const std::string& name)
{
	if(name == "GET")
	{
		return HTTPMethod::GET;				
	}
	else if(name == "HEAD")
	{
		return HTTPMethod::HEAD;				
	}
	else if(name == "POST")
	{
		return HTTPMethod::POST;				
	}
	else if(name == "PUT")
	{
		return HTTPMethod::PUT;				
	}
	else if(name == "DELETE")
	{
		return HTTPMethod::DELETE;				
	}
	else if(name == "CONNECT")
	{
		return HTTPMethod::CONNECT;				
	}
	else if(name == "OPTIONS")
	{
		return HTTPMethod::OPTIONS;				
	}
	else if(name == "TRACE")
	{
		return HTTPMethod::TRACE;				
	}
	else if(name == "PATCH")
	{
		return HTTPMethod::PATCH;				
	}
	else
	{
		throw UnknownMethodError(name);	
	}
}

HTTPMethod::HTTPMethod() : HTTPMethod(HTTPMethod::GET)
{
}

HTTPMethod::HTTPMethod(const HTTPMethod& other) : name(other.name)
{
}

HTTPMethod& HTTPMethod::operator=(const HTTPMethod& other)
{
	this->name = other.name;
	return *this;
}

const std::string HTTPMethod::getName() const
{
	return this->name;
}

bool HTTPMethod::operator==(const HTTPMethod& other) const
{
	return this->name == other.name;
}

bool HTTPMethod::operator<(const HTTPMethod& other) const
{
	return this->name < other.name;
}

bool HTTPMethod::operator<=(const HTTPMethod& other) const
{
	return this->name <= other.name;
}

bool HTTPMethod::operator>(const HTTPMethod& other) const
{
	return this->name > other.name;
}

bool HTTPMethod::operator>=(const HTTPMethod& other) const
{
	return this->name >= other.name;
}

HTTPMethod::HTTPMethod(const std::string& name) : name(name)
{
}
