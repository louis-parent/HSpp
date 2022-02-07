#ifndef __HTTP_RESPONSE_H__
#define __HTTP_RESPONSE_H__

#include <string>
#include <map>
#include "../../servlet/response/Response.h"

namespace hspp
{
	class HTTPResponse : public Response
	{
		private:		
			std::string version;
			unsigned int statusCode;
			std::string statusText;
			std::map<std::string, std::string> headers;
			std::string body;

		public:
			HTTPResponse(Response& response);
		
			virtual void send() override;
	};
}

#endif
