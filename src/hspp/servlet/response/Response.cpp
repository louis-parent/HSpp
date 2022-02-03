#include "Response.h"

using namespace hspp;

Response::Response(const ConnectedClient& destination) : socket(destination)
{
}

const ConnectedClient& Response::getDestination() const
{
	return this->socket;
}

const std::string& Response::getContent() const
{
	return this->content;
}

void Response::setContent(const std::string& content)
{
	this->content = content;
}

std::string& Response::getContent()
{
	return this->content;
}

void Response::send()
{
	this->socket.send(this->content.c_str(), this->content.size());
}
