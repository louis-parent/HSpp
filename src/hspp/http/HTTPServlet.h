#ifndef __HTTP_SERVLET_H__
#define __HTTP_SERVLET_H__

#include "../servlet/Servlet.h"
#include "request/HTTPRequest.h"
#include "response/HTTPResponse.h"

namespace hspp
{
	class HTTPServlet : public Servlet
	{
		public:
			static Port HTTP_PROD_PORT;
			static Port HTTP_DEV_PORT;
			
			HTTPServlet(Port port, int queueLength = 256);
		
		protected:
			bool request(const Request& request, Response& response) override;
			virtual void request(const HTTPRequest& request, HTTPResponse& response);
		
			virtual void get(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void head(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void post(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void put(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void del(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void connect(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void options(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void trace(const HTTPRequest& request, HTTPResponse& response) {}
			virtual void patch(const HTTPRequest& request, HTTPResponse& response) {}
	};
}

#endif
