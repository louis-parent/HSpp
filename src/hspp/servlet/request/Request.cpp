#include "Request.h"
#include <iostream>

using namespace hspp;

Request::Request(const ConnectedClient& source) : source(source)
{
	this->readAllFromSource();
}	
		
const ConnectedClient& Request::getSource() const
{
	return this->source;
}

const std::string& Request::getContent() const
{
	return this->content;
}

void Request::readAllFromSource()
{
	char c;
	size_t readed;
	bool keepReceiving;
	
	do
	{
		readed = sizeof(c);
		keepReceiving = this->source.receive(&c, &readed, false);
		this->content += c;
	} while(keepReceiving);
}
