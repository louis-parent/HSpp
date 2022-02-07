#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>
#include <map>
#include "../../servlet/request/Request.h"
#include "../HTTPMethod.h"

namespace hspp
{
	class HTTPRequest : public Request
	{
		private:
			HTTPMethod method;
			std::string target;
			std::string version;
			std::map<std::string, std::string> headers;
			std::string body;

		public:
			HTTPRequest(const Request& request);

			HTTPMethod getMethod() const;
			const std::string& getTarget() const;
			const std::string& getVersion() const;
			const std::map<std::string, std::string>& getHeaders() const;
			const std::string& getBody() const;

		private:
			void parseRequest();
	};
}

#endif
