#include "ServerNamePlugin.h"

using namespace hspp;

const std::string ServerNamePlugin::CURRENT_VERSION = "HSpp/1.0.0";
		
ServerNamePlugin::ServerNamePlugin() : name(ServerNamePlugin::CURRENT_VERSION)
{
}

ServerNamePlugin::ServerNamePlugin(const std::string& name) : name(name)
{
}

bool ServerNamePlugin::beforeRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response)
{
	response.addHeader("Server", this->name);
	return false;
}
