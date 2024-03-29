#ifndef __HTTP_RESPONSE_H__
#define __HTTP_RESPONSE_H__

#include <string>
#include <map>
#include "../../servlet/response/Response.h"
#include "status/HTTPStatus.h"

namespace hspp
{
	class HTTPResponse : public Response
	{
		private:		
			std::string version;
			HTTPStatus status;
			std::map<std::string, std::string> headers;
			std::string body;

		public:
			HTTPResponse(const Response& response);

			const std::string& getVersion() const;
			void setVersion(const std::string& version);
		
			const HTTPStatus& getStatus() const;
			void setStatus(const HTTPStatus& status);
		
			StatusCode getStatusCode() const;
			void setStatusCode(StatusCode code);
		
			const std::string& getStatusText() const;
			void setStatusText(const std::string& text);
		
			std::map<std::string, std::string> getHeaders() const;
			const std::string& getHeader(const std::string& key) const;
			bool setHeader(const std::string& key, const std::string& value);
			bool addHeader(const std::string& key, const std::string& value);
			bool removeHeader(const std::string& key);
		
			const std::string& getBody() const;
			void setBody(const std::string& body);
		
		private:
			void updateRawContent();
	};
}

#endif
