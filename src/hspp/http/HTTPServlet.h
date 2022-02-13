#ifndef __HTTP_SERVLET_H__
#define __HTTP_SERVLET_H__

#include <set>
#include <vector>

#include "../servlet/Servlet.h"
#include "request/HTTPRequest.h"
#include "response/HTTPResponse.h"
#include "plugin/Plugin.h"

namespace hspp
{
	class PluginComparator
	{
		public:
			bool operator()(const Plugin& left, const Plugin& right);
	};
	
	class HTTPServlet : public Servlet
	{
		private:
			static const std::vector<Plugin> DEFAULT_PLUGINS;
		
			std::set<Plugin, PluginComparator> plugins;
		
		public:
			static const std::string HTTP_VERSION_0_9;
			static const std::string HTTP_VERSION_1_0;
			static const std::string HTTP_VERSION_1_1;
			static const std::string HTTP_VERSION_2_0;

			static const Port HTTP_PORT_PROD;
			static const Port HTTP_PORT_DEV;
			
			HTTPServlet(Port port, int queueLength = 256);
			HTTPServlet(Port port, const std::vector<Plugin>& plugins, int queueLength = 256);
		
			bool add(const Plugin& plugin);
			bool remove(const Plugin& plugin);
		
		protected:
			virtual void onCreate() override;
			virtual void onDestroy() override;
		
			bool request(const Request& request, Response& response) override;
			virtual bool request(const HTTPRequest& request, HTTPResponse& response);
		
			virtual bool get(const HTTPRequest& request, HTTPResponse& response);
			virtual bool head(const HTTPRequest& request, HTTPResponse& response);
			virtual bool post(const HTTPRequest& request, HTTPResponse& response);
			virtual bool put(const HTTPRequest& request, HTTPResponse& response);
			virtual bool del(const HTTPRequest& request, HTTPResponse& response);
			virtual bool connect(const HTTPRequest& request, HTTPResponse& response);
			virtual bool options(const HTTPRequest& request, HTTPResponse& response);
			virtual bool trace(const HTTPRequest& request, HTTPResponse& response);
			virtual bool patch(const HTTPRequest& request, HTTPResponse& response);
	};
}

#endif
