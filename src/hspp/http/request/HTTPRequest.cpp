#include "HTTPRequest.h"

#include <sstream>
#include "../exception/RequestParsingError.h"
#include "../exception/InvalidVersionError.h"
#include "../HTTPServlet.h"

using namespace hspp;

const std::string HTTPRequest::EMPTY_HEADER_VALUE = "";
const std::string HTTPRequest::REQUEST_LINE_SEPARATOR = "\r\n";
const char HTTPRequest::HEADER_KEY_VALUE_SEPARATOR = ':';
const char HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR = ' ';

HTTPRequest::HTTPRequest(const Request& request) : Request(request)
{
	this->parseRequest();
}

const HTTPMethod& HTTPRequest::getMethod() const
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

void* HTTPRequest::getAdditional(const std::string& key) const
{
	return this->additionals.at(key);
}

void HTTPRequest::setAdditional(const std::string& key, void* data)
{
	this->additionals[key] = data;
}

void HTTPRequest::setMethod(const HTTPMethod& method)
{
	this->method = method;
}

void HTTPRequest::setTarget(const std::string& target)
{
	this->target = target;
}

void HTTPRequest::setVersion(const std::string& version)
{
	this->version = version;
}

void HTTPRequest::setHeader(const std::string& key, const std::string& value)
{
	this->headers[key] = value;
}

void HTTPRequest::setBody(const std::string& body)
{
	this->body = body;
}

void HTTPRequest::parseRequest()
{
	std::string leftToParse = this->getContent();
	std::string currentLine = "";
	bool isRequestLine = true; // True because request line must be the first line of the request
	
	do
	{
		currentLine = leftToParse.substr(0, leftToParse.find(HTTPRequest::REQUEST_LINE_SEPARATOR));
		leftToParse = leftToParse.substr(leftToParse.find(HTTPRequest::REQUEST_LINE_SEPARATOR) + HTTPRequest::REQUEST_LINE_SEPARATOR.size());
	
	
		if(isRequestLine) // Is first line aka request line
		{
			this->parseRequestLine(currentLine);
			isRequestLine = false;
		}
		else if(currentLine == HTTPRequest::EMPTY_HEADER_VALUE) // If it's empty line, it's the header/body separator
		{
			this->setBody(leftToParse); // the body is all the content to the end
			leftToParse = "";
		}
		else // We still in the headers
		{
			this->parseHeader(currentLine);
		}
	}while(leftToParse.size() > 0); // While end of the request is not reached
}

void HTTPRequest::parseRequestLine(const std::string& line)
{
	std::istringstream stream(line);
	std::string token;
	
	if(std::getline(stream, token, HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR))
	{
		this->setMethod(HTTPMethod::forName(token));
		
		if(std::getline(stream, token, HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR))
		{
			this->setTarget(token);
			
			if(std::getline(stream, token, HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR))
			{
				if(HTTPServlet::isValidHTTPVersion(token))
				{
					this->setVersion(token);
				}
				else
				{
					throw InvalidVersionError(this->version);
				}
			}
			else
			{
				throw RequestParsingError(line + " is not a valid request first line");
			}
		}
		else
		{
			throw RequestParsingError(line + " is not a valid request first line");
		}
	}
	else
	{
		throw RequestParsingError(line + " is not a valid request first line");
	}
}

void HTTPRequest::parseHeader(const std::string& line)
{
	std::istringstream stream(line);
	std::string key;
	
	if(std::getline(stream, key, HTTPRequest::HEADER_KEY_VALUE_SEPARATOR))
	{
		std::string value;
		std::getline(stream, value);
		
		this->setHeader(key, value);
	}
	else
	{
		throw RequestParsingError(line + " is not a valid header line");
	}
	

}
