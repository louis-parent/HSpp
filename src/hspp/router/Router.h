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
		
			bool process(const HTTPMethod& method, const HTTPRequest& request, HTTPResponse& response);
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
		
			bool get(const HTTPRequest& request, HTTPResponse& response) override;
			bool head(const HTTPRequest& request, HTTPResponse& response) override;
			bool post(const HTTPRequest& request, HTTPResponse& response) override;
			bool put(const HTTPRequest& request, HTTPResponse& response) override;
			bool del(const HTTPRequest& request, HTTPResponse& response) override;
			bool connect(const HTTPRequest& request, HTTPResponse& response) override;
			bool options(const HTTPRequest& request, HTTPResponse& response) override;
			bool trace(const HTTPRequest& request, HTTPResponse& response) override;
			bool patch(const HTTPRequest& request, HTTPResponse& response) override;
	};
}

#endif
