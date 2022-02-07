#include "HTTPServlet.h"
#include "HTTPMethod.h"

using namespace hspp;

HTTPServlet::HTTPServlet(Port port, int queueLength) : Servlet(port, queueLength)
{
}

void HTTPServlet::request(const Request& request, Response& response)
{
	HTTPRequest httpRequest(request);
	HTTPResponse httpResponse(response);
	this->request(httpRequest, httpResponse);
}

void HTTPServlet::request(const HTTPRequest& request, HTTPResponse& response)
{
	switch(request.getMethod())
	{
		case HTTPMethod::GET:
			this->get(request, response);
			break;
			
		case HTTPMethod::HEAD:
			this->head(request, response);
			break;
			
		case HTTPMethod::POST:
			this->post(request, response);
			break;
			
		case HTTPMethod::PUT:
			this->put(request, response);
			break;
			
		case HTTPMethod::DELETE:
			this->del(request, response);
			break;
			
		case HTTPMethod::CONNECT:
			this->connect(request, response);
			break;
			
		case HTTPMethod::OPTIONS:
			this->options(request, response);
			break;
			
		case HTTPMethod::TRACE:
			this->trace(request, response);
			break;
			
		case HTTPMethod::PATCH:
			this->patch(request, response);
			break;
	}
}
