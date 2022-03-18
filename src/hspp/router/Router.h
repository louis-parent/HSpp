#ifndef __ROUTER_H__
#define __ROUTER_H__

#include <string>
#include <map>
#include "../http/HTTPServlet.h"
#include "RouteAction.h"

namespace hspp
{
	class Router : public HTTPServlet
	{
		private:
			std::map<const HTTPMethod, std::map<const std::string, RouteAction*>> routes;
		
			bool process(const HTTPMethod& method, HTTPRequest& request, HTTPResponse& response);
			RouteAction* findMatchingRoute(const HTTPMethod& method, const std::string& path);
		
		public:
			Router(Port port, int queueLength = 256);
			~Router();
		
			void get(const std::string& path, RouteAction* action);
			void head(const std::string& path, RouteAction* action);
			void post(const std::string& path, RouteAction* action);
			void put(const std::string& path, RouteAction* action);
			void del(const std::string& path, RouteAction* action);
			void connect(const std::string& path, RouteAction* action);
			void options(const std::string& path, RouteAction* action);
			void trace(const std::string& path, RouteAction* action);
			void patch(const std::string& path, RouteAction* action);
		
			void route(const HTTPMethod& method, const std::string& path, RouteAction* action);
		
			void mount(const std::string& routePath, const std::string& mountPath);
		
			bool get(HTTPRequest& request, HTTPResponse& response) override;
			bool head(HTTPRequest& request, HTTPResponse& response) override;
			bool post(HTTPRequest& request, HTTPResponse& response) override;
			bool put(HTTPRequest& request, HTTPResponse& response) override;
			bool del(HTTPRequest& request, HTTPResponse& response) override;
			bool connect(HTTPRequest& request, HTTPResponse& response) override;
			bool options(HTTPRequest& request, HTTPResponse& response) override;
			bool trace(HTTPRequest& request, HTTPResponse& response) override;
			bool patch(HTTPRequest& request, HTTPResponse& response) override;
	};
}

#endif
