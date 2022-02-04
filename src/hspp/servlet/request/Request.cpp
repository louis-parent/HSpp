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

void Request::readAllFromSource()
{
	char c = '\0';
	size_t readed = 0;
	bool keepReceiving = true;
	
	while(keepReceiving)
	{
		readed = sizeof(c);
		keepReceiving = this->source.receive(&c, &readed, false);
		
		if(keepReceiving)
		{
			this->content += c;
		}
	}
}
