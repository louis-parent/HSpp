#ifndef __SERVER_NAME_PLUGIN_H__
#define __SERVER_NAME_PLUGIN_H__

#include "../../plugin/Plugin.h"
#include <ctime>

namespace hspp
{
	class ServerNamePlugin : public Plugin
	{
		private:
			std::string name;
		
		public:
			static const std::string CURRENT_VERSION;
		
			ServerNamePlugin();
			ServerNamePlugin(const std::string& name);

			bool afterRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response) override;
	};
}

#endif
