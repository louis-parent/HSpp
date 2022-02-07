#include "HTTPRequest.h"

using namespace hspp;

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

const std::string& HTTPRequest::getBody() const
{
	return this->body;
}

void HTTPRequest::parseRequest()
{
	
}
