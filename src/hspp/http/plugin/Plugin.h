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
			static long nextId;
		
			long id;
			long priority;
			
		public:
			Plugin();
			Plugin(long priority);
		
			long getPriority() const;
		
			virtual void onCreate(HTTPServlet& servlet);
			virtual void onDestroy(HTTPServlet& servlet);
			virtual bool beforeRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response);
			virtual bool afterRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response);
		
			bool operator==(const Plugin& other);
	};
}

#endif
