#include "HTTPResponse.h"

using namespace hspp;

HTTPResponse::HTTPResponse(Response& response) : Response(response)
{
}

void HTTPResponse::send()
{	
	Response::send();
}
