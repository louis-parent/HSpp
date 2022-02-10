#ifndef __HTTP_PLUGIN_H__
#define __HTTP_PLUGIN_H__

#include "../response/HTTPResponse.h"
#include "../request/HTTPRequest.h"

namespace hspp
{
	class HTTPServlet;
	
	class Plugin
	{
		private:
			long priority;
			
		public:
			Plugin() : Plugin(0) {}
			Plugin(long priority) : priority(priority) {}
		
			long getPriority() const { return this->priority; }
		
			virtual void onCreate(HTTPServlet& servlet) {}
			virtual void onDestroy(HTTPServlet& servlet) {}
			virtual bool beforeRequest(const HTTPServlet& servlet, const HTTPRequest& request, HTTPResponse& response) { return false; }
			virtual bool afterRequest(const HTTPServlet& servlet, const HTTPRequest& request, HTTPResponse& response) { return false; }
	};
}

#endif
