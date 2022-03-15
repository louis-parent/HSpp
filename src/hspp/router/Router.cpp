#include "Router.h"

#include "exception/RoutingError.h"

using namespace hspp;

bool Router::process(const HTTPMethod& method, const HTTPRequest& request, HTTPResponse& response)
{
	RouteAction* action = this->findMatchingRoute(method, request.getTarget());
	
	if(action != nullptr)
	{
		return action->process(request, response);
	}
	else
	{
		throw RoutingError("Undefined route " + method.getName() + " " + request.getTarget());
	}
}

RouteAction* Router::findMatchingRoute(const HTTPMethod& method, const std::string& path)
{
	if(this->routes.count(method) > 0)
	{
		if(this->routes[method].count(path))
		{
			return this->routes[method][path];
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

Router::Router(Port port, int queueLength) : HTTPServlet(port, queueLength)
{
}

Router::~Router()
{
	for(const std::pair<const HTTPMethod, std::map<const std::string, RouteAction*>>& routesOfMethod : this->routes)
	{
		for(const std::pair<const std::string, RouteAction*>& actionOfPath : routesOfMethod.second)
		{
			delete actionOfPath.second;
		}
	}
}

void Router::get(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::GET, path, action);
}

void Router::head(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::HEAD, path, action);
}

void Router::post(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::POST, path, action);
}

void Router::put(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::PUT, path, action);
}

void Router::del(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::DELETE, path, action);
}

void Router::connect(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::CONNECT, path, action);
}

void Router::options(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::OPTIONS, path, action);
}

void Router::trace(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::TRACE, path, action);
}

void Router::patch(const std::string& path, RouteAction* action)
{
	this->route(HTTPMethod::PATCH, path, action);
}

void Router::route(const HTTPMethod& method, const std::string& path, RouteAction* action)
{
	if(this->routes.count(method) == 0)
	{
		this->routes.insert(std::pair<const HTTPMethod, std::map<const std::string, RouteAction*>>(method, std::map<const std::string, RouteAction*>()));
	}
	
	this->routes[method].insert(std::pair<const std::string, RouteAction*>(path, action));
}

bool Router::get(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::GET, request, response);
}

bool Router::head(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::HEAD, request, response);
}

bool Router::post(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::POST, request, response);
}

bool Router::put(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::PUT, request, response);
}

bool Router::del(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::DELETE, request, response);
}

bool Router::connect(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::CONNECT, request, response);
}

bool Router::options(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::OPTIONS, request, response);
}

bool Router::trace(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::TRACE, request, response);
}

bool Router::patch(const HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::PATCH, request, response);
}
