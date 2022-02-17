#include "Plugin.h"

using namespace hspp;			
			
long Plugin::nextId = 0;

Plugin::Plugin() : Plugin(0)
{
}

Plugin::Plugin(long priority) : id(Plugin::nextId++), priority(priority)
{
}

long Plugin::getPriority() const
{
	return this->priority;
}

void Plugin::onCreate(HTTPServlet& servlet)
{
}

void Plugin::onDestroy(HTTPServlet& servlet)
{
}

bool Plugin::beforeRequest(const HTTPServlet& servlet, const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool Plugin::afterRequest(const HTTPServlet& servlet, const HTTPRequest& request, HTTPResponse& response)
{
	return false;
}

bool Plugin::operator==(const Plugin& other)
{
	return this->id == other.id;
}
