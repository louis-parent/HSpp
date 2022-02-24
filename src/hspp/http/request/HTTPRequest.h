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
			static const std::string EMPTY_HEADER_VALUE;
			static const char REQUEST_LINE_SEPARATOR;
			static const char HEADER_KEY_VALUE_SEPARATOR;
			static const char REQUEST_LINE_ITEM_SEPARATOR;
		
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
			const std::string& getHeader(const std::string& key) const;
			const std::string& getBody() const;

		private:
			void parseRequest();
			void parseRequestLine(const std::string& line);
			void parseHeader(const std::string& line);
	};
}

#endif
