#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>
#include <map>
#include "../../servlet/request/Request.h"
#include "../method/HTTPMethod.h"

namespace hspp
{
	class HTTPRequest : public Request
	{
		private:
			static const std::string EMPTY_HEADER_VALUE;
			static const std::string REQUEST_LINE_SEPARATOR;
			static const char HEADER_KEY_VALUE_SEPARATOR;
			static const char REQUEST_LINE_ITEM_SEPARATOR;
		
			HTTPMethod method;
			std::string target;
			std::string version;
			std::map<std::string, std::string> headers;
			std::string body;
		
			std::map<const std::string, void*> customs;

		public:
			HTTPRequest(const Request& request);

			const HTTPMethod& getMethod() const;
			void setMethod(const HTTPMethod& method);
		
			const std::string& getTarget() const;
			void setTarget(const std::string& target);
		
			const std::string& getVersion() const;
			void setVersion(const std::string& version);
		
			const std::map<std::string, std::string>& getHeaders() const;
			const std::string& getHeader(const std::string& key) const;
			void setHeader(const std::string& key, const std::string& value);
		
			const std::string& getBody() const;
			void setBody(const std::string& body);
			
			void* getCustom(const std::string& key) const;
			void setCustom(const std::string& key, void* data);

		private:
			void parseRequest();
			void parseRequestLine(const std::string& line);
			void parseHeader(const std::string& line);
	};
}

#endif
