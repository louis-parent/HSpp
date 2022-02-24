#include "HTTPRequest.h"

#include <iostream>
#include <sstream>
#include "../exception/RequestParsingError.h"
#include "../exception/InvalidVersionError.h"
#include "../HTTPServlet.h"
#include "../HTTPMethod.h"

using namespace hspp;

const std::string HTTPRequest::EMPTY_HEADER_VALUE = "";
const char HTTPRequest::REQUEST_LINE_SEPARATOR = '\n';
const char HTTPRequest::HEADER_KEY_VALUE_SEPARATOR = '=';
const char HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR = ' ';

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
	std::istringstream stream(this->getContent());
	
	std::string currentLine;
	bool isRequestLine = true; // True because request line must be the first line of the request
	
	while(std::getline(stream, currentLine, HTTPRequest::REQUEST_LINE_SEPARATOR)) // While end of the request is not reached
	{		
		if(isRequestLine) // Is first line aka request line
		{
			this->parseRequestLine(currentLine);
			isRequestLine = false;
		}
		else if(currentLine == HTTPRequest::EMPTY_HEADER_VALUE) // If it's empty line, it's the header/body separator
		{
			 std::getline(stream, this->body); // the body is all the content to the end
		}
		else // We still in the headers
		{
			this->parseHeader(currentLine);
		}
	}	
	
	std::cout << this->method << " " << this->target << " " << this->version << std::endl;
	
	for(std::pair<std::string, std::string> header : this->headers)
	{
		std::cout << header.first << "=" << header.second << std::endl;	
	}
	
	std::cout << std::endl << this->body << std::endl;
}

void HTTPRequest::parseRequestLine(const std::string& line)
{
	std::istringstream stream(line.substr(0, line.size() - 1));
	std::string token;
	
	if(std::getline(stream, token, HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR))
	{
		this->method = HTTPMethod::forName(token);
		
		if(std::getline(stream, token, HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR))
		{
			this->target = token;
			
			if(std::getline(stream, token, HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR))
			{
				if(HTTPServlet::isValidHTTPVersion(token))
				{
					this->version = token;
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
		
		this->headers.insert(std::pair<std::string, std::string>(key, value));
	}
	else
	{
		throw RequestParsingError(line + " is not a valid header line");
	}
	

}
