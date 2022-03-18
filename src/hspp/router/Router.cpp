#include "Router.h"

#ifndef __has_include
  static_assert(false, "__has_include not supported");
#else
#  if __cplusplus >= 201703L && __has_include(<filesystem>)
#    include <filesystem>
     namespace fs = std::filesystem;
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
     namespace fs = std::experimental::filesystem;
#  endif
#endif


#include "exception/RoutingError.h"
#include "exception/MountingError.h"
#include "exception/AbsolutePathError.h"
#include "actions/StaticFileDelivery.h"

using namespace hspp;

bool Router::process(const HTTPMethod& method, HTTPRequest& request, HTTPResponse& response)
{
	RouteAction* action = this->findMatchingRoute(method, request.getTarget());
	
	if(action != nullptr)
	{
		return action->process(request, response);
	}
	else
	{
		return false;
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

void Router::mount(const std::string& routePath, const std::string& mountPath)
{
	if(mountPath[0] != '/')
	{
		if(fs::is_regular_file(mountPath))
		{
			std::string route(routePath); 
			if(route[routes.size() - 1] != '/')
			{
				route += "/";
			}
			route += mountPath;
		
			this->route(HTTPMethod::GET, route, new StaticFileDelivery(mountPath));
		}
		else if(fs::is_directory(mountPath))
		{
			for(const fs::directory_entry& entry : fs::directory_iterator(mountPath))
			{
				this->mount(routePath, entry.path());
			}
		}
		else
		{
			throw MountingError(mountPath);
		}
	}
	else
	{
		throw AbsolutePathError(mountPath);
	}
}

bool Router::get(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::GET, request, response);
}

bool Router::head(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::HEAD, request, response);
}

bool Router::post(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::POST, request, response);
}

bool Router::put(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::PUT, request, response);
}

bool Router::del(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::DELETE, request, response);
}

bool Router::connect(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::CONNECT, request, response);
}

bool Router::options(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::OPTIONS, request, response);
}

bool Router::trace(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::TRACE, request, response);
}

bool Router::patch(HTTPRequest& request, HTTPResponse& response)
{
	return this->process(HTTPMethod::PATCH, request, response);
}
