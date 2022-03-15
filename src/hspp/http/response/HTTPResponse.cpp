#include "HTTPResponse.h"

#include <sstream>

using namespace hspp;

HTTPResponse::HTTPResponse(const Response& response)
	: Response(response),
	version("HTTP/1.1"),
	statusCode(404),
	statusText("Not Found")
{
	this->updateRawContent();
}

const std::string& HTTPResponse::getVersion() const
{
	return this->version;
}

void HTTPResponse::setVersion(const std::string& version)
{
	this->version = version;
	this->updateRawContent();
}

StatusCode HTTPResponse::getStatusCode() const
{
	return this->statusCode;
}

void HTTPResponse::setStatusCode(StatusCode code)
{
	this->statusCode = code;
	this->updateRawContent();
}

const std::string& HTTPResponse::getStatusText() const
{
	return this->statusText;
}

void HTTPResponse::setStatusText(const std::string& text)
{
	this->statusText = text;
	this->updateRawContent();
}

std::map<std::string, std::string> HTTPResponse::getHeaders() const
{
	return this->headers;
}

const std::string& HTTPResponse::getHeader(const std::string& key) const
{
	return this->headers.at(key);
}

bool HTTPResponse::setHeader(const std::string& key, const std::string& value)
{
	if(this->headers.find(key) != this->headers.end())
	{
		this->headers[key] = value;
		this->updateRawContent();
		return true;
	}
	else
	{
		return false;
	}
}

bool HTTPResponse::addHeader(const std::string& key, const std::string& value)
{
	std::pair<std::map<std::string, std::string>::iterator, bool> result;
	result = this->headers.insert(std::pair<std::string, std::string>(key, value));
	
	if(result.second)
	{
		this->updateRawContent();
		return true;
	}
	else
	{
		return false;
	} 
}

bool HTTPResponse::removeHeader(const std::string& key)
{
	size_t removed = this->headers.erase(key);
	if(removed > 0)
	{
		this->updateRawContent();
		return true;
	}
	else
	{
		return false;
	}
}

const std::string& HTTPResponse::getBody() const
{
	return this->body;
}

void HTTPResponse::setBody(const std::string& body)
{
	this->body = body;
	this->updateRawContent();
}

void HTTPResponse::updateRawContent()
{
	std::ostringstream builder;

	builder << this->version << " " << this->statusCode << " " << this->statusText << std::endl;

	for(const std::pair<std::string, std::string> header : this->headers)
	{
		builder << header.first << ": " << header.second << std::endl;
	}

	builder << std::endl;
	builder << this->body << std::endl;

	this->setContent(builder.str());
}
