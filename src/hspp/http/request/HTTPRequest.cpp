#include "HTTPRequest.h"

#include <iostream>
#include "../exception/RequestParsingError.h"
#include "../exception/InvalidVersionError.h"
#include "../HTTPServlet.h"
#include "../HTTPMethod.h"

using namespace hspp;

const std::string HTTPRequest::EMPTY_HEADER_VALUE = "";
const std::string HTTPRequest::REQUEST_LINE_SEPARATOR = "\n";
const std::string HTTPRequest::HEADER_KEY_VALUE_SEPARATOR = "=";
const std::string HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR = " ";

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
	const std::string& content = this->getContent();
	
	std::string currentLine;
	bool isRequestLine = true; // True because request line must be the first line of the request
	
	size_t startSubString = 0;
	size_t endSubString = 0;
	
	while(endSubString != std::string::npos) // While end of the request is not reached
	{
		endSubString = content.find(HTTPRequest::REQUEST_LINE_SEPARATOR, startSubString);
		currentLine = content.substr(startSubString, endSubString);
		
		if(isRequestLine) // Is first line aka request line
		{
			this->parseRequestLine(currentLine);
			isRequestLine = false;
		}
		else if(currentLine == HTTPRequest::EMPTY_HEADER_VALUE) // If it's empty line, it's the header/body separator
		{
			startSubString = endSubString + 1;
			endSubString = std::string::npos;
			this->body = content.substr(startSubString, endSubString); // the body is all the content to the end
		}
		else // We still in the headers
		{
			this->parseHeader(currentLine);
		}
		
		startSubString = endSubString + 1;
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
	size_t itemStart = 0;
	size_t itemEnd = std::string::npos;
	
	itemEnd = line.find(HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR);
	
	if(itemEnd != std::string::npos)
	{
		this->method = HTTPMethod::forName(line.substr(itemStart, itemEnd));
		
		itemStart = itemEnd + 1;
		itemEnd = line.find(HTTPRequest::REQUEST_LINE_ITEM_SEPARATOR, itemStart);
		
		if(itemEnd != std::string::npos)
		{
			this->target = line.substr(itemStart, itemEnd);
			this->version = line.substr(itemEnd + 1);
			
			if(!HTTPServlet::isValidHTTPVersion(this->version))
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

void HTTPRequest::parseHeader(const std::string& line)
{
	size_t equalPosition = line.find(HTTPRequest::HEADER_KEY_VALUE_SEPARATOR);
	
	std::string key = line.substr(0, equalPosition);
	std::string value = line.substr(equalPosition + 1);
	
	this->headers.insert(std::pair<std::string, std::string>(key, value));
}
