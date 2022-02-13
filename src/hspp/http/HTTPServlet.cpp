#include "HTTPServlet.h"
#include "HTTPMethod.h"

#include "plugins/KeepAlivePlugin.h"

using namespace hspp;

bool PluginComparator::operator()(const Plugin& left, const Plugin& right)
{
	return left.getPriority() > right.getPriority();
}

const std::vector<Plugin> HTTPServlet::DEFAULT_PLUGINS = std::vector<Plugin>();

const std::string HTTPServlet::HTTP_VERSION_0_9 = "HTTP/0.9";
const std::string HTTPServlet::HTTP_VERSION_1_0 = "HTTP/1.0";
const std::string HTTPServlet::HTTP_VERSION_1_1 = "HTTP/1.1";
const std::string HTTPServlet::HTTP_VERSION_2_0 = "HTTP/2.0";

const Port HTTPServlet::HTTP_PORT_PROD = 80;
const Port HTTPServlet::HTTP_PORT_DEV = 8080;

HTTPServlet::HTTPServlet(Port port, int queueLength) : HTTPServlet(port, HTTPServlet::DEFAULT_PLUGINS, queueLength)
{
}

HTTPServlet::HTTPServlet(Port port, const std::vector<Plugin>& plugins, int queueLength) : Servlet(port, queueLength)
{
	for(const Plugin& plugin : plugins)
	{
		this->plugins.insert(plugin);
	}
}

bool HTTPServlet::add(const Plugin& plugin)
{
	this->plugins.insert(plugin);
	return true;
}

bool HTTPServlet::remove(const Plugin& plugin)
{
	return this->plugins.erase(plugin) > 0;
}

void HTTPServlet::onCreate()
{
	for(Plugin plugin : this->plugins)
	{
		plugin.onCreate(*this);
	}
}

void HTTPServlet::onDestroy()
{
	for(Plugin plugin : this->plugins)
	{
		plugin.onDestroy(*this);
	}
}

bool HTTPServlet::request(const Request& request, Response& response)
{
	bool keepAlive = false;
	HTTPRequest httpRequest(request);
	HTTPResponse httpResponse(response);
	
	for(Plugin plugin : this->plugins)
	{
		keepAlive |= plugin.beforeRequest(*this, httpRequest, httpResponse);
	}
	
	keepAlive |= this->request(httpRequest, httpResponse);

	for(Plugin plugin : this->plugins)
	{
		keepAlive |= plugin.afterRequest(*this, httpRequest, httpResponse);
	}

	response.setContent(httpResponse.getContent());
	return keepAlive;
}

bool HTTPServlet::request(const HTTPRequest& request, HTTPResponse& response)
{
	switch(request.getMethod())
	{
		case HTTPMethod::GET:
			return this->get(request, response);
			
		case HTTPMethod::HEAD:
			return this->head(request, response);
			
		case HTTPMethod::POST:
			return this->post(request, response);
			
		case HTTPMethod::PUT:
			return this->put(request, response);
			
		case HTTPMethod::DELETE:
			return this->del(request, response);
			
		case HTTPMethod::CONNECT:
			return this->connect(request, response);
			
		case HTTPMethod::OPTIONS:
			return this->options(request, response);
			
		case HTTPMethod::TRACE:
			return this->trace(request, response);
			
		case HTTPMethod::PATCH:
			return this->patch(request, response);
			
		default:
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
