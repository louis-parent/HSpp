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

#include <stdlib.h>

#include "exception/RoutingError.h"
#include "exception/MountingError.h"
#include "exception/MountPathError.h"
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

std::string Router::tryToGetMountPath(const std::string& mountPath)
{
	char* rawPath = realpath(mountPath.c_str(), nullptr); 
	
	if(rawPath != nullptr)
	{
		std::string path(rawPath);
		std::string currentPath(fs::current_path().string() + "/");
		
		delete rawPath;
		
		// To be a subfolder : must start with the current path add be bigger
		if(path.rfind(currentPath, 0) == 0 && path.size() > currentPath.size())
		{
			return path;
		}
		else
		{
			throw MountPathError(mountPath, "mount path must be a subfolder / subfile of the server");
		}
	}
	else
	{
		throw MountPathError(mountPath, "the target doesn't exist");
	}
}

std::string& Router::slashPrefixed(std::string& str)
{
	if(str[0] != '/')
	{
		str = "/" + str;
	}
	
	return str;
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
	std::string path(this->tryToGetMountPath(mountPath));
	std::string currentPath(fs::current_path().string());

	if(fs::is_regular_file(path))
	{
		std::string route(path.substr(currentPath.size())); // Making path relative to the current path
		this->route(HTTPMethod::GET, this->slashPrefixed(route), new StaticFileDelivery(path));
	}
	else if(fs::is_directory(path))
	{
		for(const fs::directory_entry& entry : fs::directory_iterator(path))
		{
			this->mount(routePath, entry.path());
		}
	}
	else
	{
		throw MountingError(mountPath);
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
