#include "KeepAlivePlugin.h"
#include <algorithm>

using namespace hspp;

const std::string KeepAlivePlugin::CONNECTION_HEADER_NAME = "Connection";
const std::string KeepAlivePlugin::CONNECTION_HEADER_KEEP_ALIVE = "keep-alive";
const std::string KeepAlivePlugin::CONNECTION_HEADER_CLOSE = "close";
const std::string KeepAlivePlugin::KEEP_ALIVE_HEADER_NAME = "Keep-Alive";
const std::string KeepAlivePlugin::KEEP_ALIVE_TIMEOUT_VALUE = "timeout=";
const std::string KeepAlivePlugin::KEEP_ALIVE_MAX_VALUE = "max=";

KeepAlivePlugin::KeepAlivePlugin(int timeout, int maxTransaction) : timeout(timeout), maxTransaction(maxTransaction)
{
}

bool KeepAlivePlugin::afterRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response)
{
	bool keepAlive = false;
	
	if(request.getVersion() == HTTPServlet::HTTP_VERSION_1_0)
	{
		keepAlive = this->processHTTP10(request, response);
	}
	else if(request.getVersion() == HTTPServlet::HTTP_VERSION_1_1)
	{
		keepAlive = this->processHTTP11(request, response);
	}
	
	if(keepAlive)
	{
		this->setConnectionResponseHeader(response);
	}
	
	return keepAlive;
}

bool KeepAlivePlugin::processHTTP10(HTTPRequest& request, HTTPResponse& response)
{
	if(request.getHeader(KeepAlivePlugin::CONNECTION_HEADER_NAME) == KeepAlivePlugin::CONNECTION_HEADER_KEEP_ALIVE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool KeepAlivePlugin::processHTTP11(HTTPRequest& request, HTTPResponse& response)
{	
	if(request.getHeader(KeepAlivePlugin::CONNECTION_HEADER_NAME) == KeepAlivePlugin::CONNECTION_HEADER_CLOSE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void KeepAlivePlugin::setConnectionResponseHeader(HTTPResponse& response) const
{
	response.setHeader(KeepAlivePlugin::CONNECTION_HEADER_NAME, KeepAlivePlugin::CONNECTION_HEADER_KEEP_ALIVE);
	response.setHeader(KeepAlivePlugin::KEEP_ALIVE_HEADER_NAME, this->getKeepAliveResponseHeaderValue());
}

std::string KeepAlivePlugin::getKeepAliveResponseHeaderValue() const
{
	std::string value = KeepAlivePlugin::KEEP_ALIVE_TIMEOUT_VALUE;
	value += this->timeout;
	value += ", ";
	value += KeepAlivePlugin::KEEP_ALIVE_MAX_VALUE;
	value += this->maxTransaction;
	
	return value;
}
