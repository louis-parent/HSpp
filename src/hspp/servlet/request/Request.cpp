#include "Request.h"

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

bool Request::hasReceived() const
{
	return !this->content.empty();
}

void Request::readAllFromSource()
{
	char c = '\0';
	size_t readed = 0;
	
	bool keepReceiving = true;
	bool isFirstByte = true;
	
	while(keepReceiving)
	{
		readed = sizeof(c);
		keepReceiving = this->source.receive(&c, &readed, isFirstByte);
		isFirstByte = false;
		
		if(keepReceiving)
		{
			this->content += c;
		}
	}
}
