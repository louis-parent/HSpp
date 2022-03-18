#ifndef __KEEP_ALIVE_PLUGIN_H__
#define __KEEP_ALIVE_PLUGIN_H__

#include <string>
#include "../plugin/Plugin.h"
#include "../HTTPServlet.h"

namespace hspp
{
	class KeepAlivePlugin : public Plugin
	{
		private:
			static const std::string CONNECTION_HEADER_NAME;
			static const std::string CONNECTION_HEADER_KEEP_ALIVE;
			static const std::string CONNECTION_HEADER_CLOSE;
			static const std::string KEEP_ALIVE_HEADER_NAME;
			static const std::string KEEP_ALIVE_TIMEOUT_VALUE;
			static const std::string KEEP_ALIVE_MAX_VALUE;
		
			int timeout;
			int maxTransaction;
		
		public:
			KeepAlivePlugin(int timeout = 5, int maxTransaction = 1000);

			bool afterRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response) override;
		
		private:
			bool processHTTP10(HTTPRequest& request, HTTPResponse& response);
			bool processHTTP11(HTTPRequest& request, HTTPResponse& response);
			void setConnectionResponseHeader(HTTPResponse& response) const;
			std::string getKeepAliveResponseHeaderValue() const;
	};
}

#endif
