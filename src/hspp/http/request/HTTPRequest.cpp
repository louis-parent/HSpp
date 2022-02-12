#include "HTTPRequest.h"

using namespace hspp;

const std::string HTTPRequest::EMPTY_HEADER_VALUE = "";

HTTPRequest::HTTPRequest(const Request& request) : Request(request)
{
	this->parseRequest();
}

HTTPMethod HTTPRequest::getMethod() const
{
	return this->method;
}

const std::string& HTTPRequest::getTarget() const
{
	return this->target;
}

const std::string& HTTPRequest::getVersion() const
{
	return this->version;
}

const std::map<std::string, std::string>& HTTPRequest::getHeaders() const
{
	return this->headers;
}

const std::string& HTTPRequest::getHeader(const std::string& key) const
{
	if(this->headers.find(key) != this->headers.end())
	{
		return this->headers.at(key);
	}
	else
	{
		return HTTPRequest::EMPTY_HEADER_VALUE;
	}
}

const std::string& HTTPRequest::getBody() const
{
	return this->body;
}

void HTTPRequest::parseRequest()
{
	
}
