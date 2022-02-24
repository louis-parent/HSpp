#include "HTTPServlet.h"
#include "HTTPMethod.h"

#include <algorithm>
#include "plugins/KeepAlivePlugin.h"

using namespace hspp;

bool PluginComparator::operator()(const Plugin* left, const Plugin* right)
{
	return left->getPriority() > right->getPriority();
}

const std::string HTTPServlet::HTTP_VERSION_0_9 = "HTTP/0.9";
const std::string HTTPServlet::HTTP_VERSION_1_0 = "HTTP/1.0";
const std::string HTTPServlet::HTTP_VERSION_1_1 = "HTTP/1.1";
const std::string HTTPServlet::HTTP_VERSION_2_0 = "HTTP/2.0";

const Port HTTPServlet::HTTP_PORT_PROD = 80;
const Port HTTPServlet::HTTP_PORT_DEV = 8080;

HTTPServlet::HTTPServlet(Port port, int queueLength) : HTTPServlet(port, std::vector<Plugin*>(), queueLength)
{
	this->add(new KeepAlivePlugin());
}

HTTPServlet::HTTPServlet(Port port, const std::vector<Plugin*>& plugins, int queueLength) : Servlet(port, queueLength)
{
	for(Plugin* plugin : plugins)
	{
		this->add(plugin);
	}
}

HTTPServlet::~HTTPServlet()
{
	for(Plugin* plugin : this->plugins)
	{
		delete plugin;
	}
}

bool HTTPServlet::add(Plugin* plugin)
{
	this->plugins.push_back(plugin);
	std::sort(this->plugins.begin(), this->plugins.end(), HTTPServlet::PLUGIN_COMPARATOR);
	return true;
}

bool HTTPServlet::remove(Plugin* plugin)
{
	std::vector<Plugin*>::iterator position = std::find(this->plugins.begin(), this->plugins.end(), plugin);
	
	if (position != this->plugins.end())
	{
    	this->plugins.erase(position);
    	return true;
	}
	else
	{
		return false;
	}
}

bool HTTPServlet::isValidHTTPVersion(const std::string& version)
{
	return version == HTTPServlet::HTTP_VERSION_0_9 || version == HTTPServlet::HTTP_VERSION_1_0 || version == HTTPServlet::HTTP_VERSION_1_1 || version == HTTPServlet::HTTP_VERSION_2_0;
}

void HTTPServlet::onCreate()
{
	for(Plugin* plugin : this->plugins)
	{
		plugin->onCreate(*this);
	}
}

void HTTPServlet::onDestroy()
{
	for(Plugin* plugin : this->plugins)
	{
		plugin->onDestroy(*this);
	}
}

bool HTTPServlet::request(const Request& request, Response& response)
{
	bool keepAlive = false;
	HTTPRequest httpRequest(request);
	HTTPResponse httpResponse(response);
	
	for(Plugin* plugin : this->plugins)
	{
		keepAlive |= plugin->beforeRequest(*this, httpRequest, httpResponse);
	}
	
	keepAlive |= this->request(httpRequest, httpResponse);

	for(Plugin* plugin : this->plugins)
	{
		keepAlive |= plugin->afterRequest(*this, httpRequest, httpResponse);
	}

	response.setContent(httpResponse.getContent());
	return keepAlive;
}

bool HTTPServlet::request(const HTTPRequest& request, HTTPResponse& response)
{
	if(request.getMethod() == HTTPMethod::GET)
	{
		return this->get(request, response);
	}
	else if(request.getMethod() == HTTPMethod::HEAD)
	{
		return this->head(request, response);
	}
	else if(request.getMethod() == HTTPMethod::POST)
	{
		return this->post(request, response);
	}
	else if(request.getMethod() == HTTPMethod::PUT)
	{
		return this->put(request, response);
	}
	else if(request.getMethod() == HTTPMethod::DELETE)
	{
		return this->del(request, response);
	}
	else if(request.getMethod() == HTTPMethod::CONNECT)
	{
		return this->connect(request, response);
	}
	else if(request.getMethod() == HTTPMethod::OPTIONS)
	{
		return this->options(request, response);
	}
	else if(request.getMethod() == HTTPMethod::TRACE)
	{
		return this->trace(request, response);
	}
	else if(request.getMethod() == HTTPMethod::PATCH)
	{
		return this->patch(request, response);
	}
	else
	{
		return false;
	}
}

bool HTTPServlet::get(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::head(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::post(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::put(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::del(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::connect(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::options(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::trace(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool HTTPServlet::patch(const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}
