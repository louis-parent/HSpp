#ifndef __ROUTE_ACTION_H__
#define __ROUTE_ACTION_H__

#include "../http/request/HTTPRequest.h"
#include "../http/response/HTTPResponse.h"

namespace hspp
{
	class RouteAction
	{
		public:
			virtual bool operator()(const HTTPRequest& request, HTTPResponse& response);
	};
}

#endif
