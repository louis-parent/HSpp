#ifndef __TIMESTAMP_PLUGIN_H__
#define __TIMESTAMP_PLUGIN_H__

#include "../../plugin/Plugin.h"
#include <ctime>

namespace hspp
{
	class TimestampPlugin : public Plugin
	{
		private:
			std::string	getGMT(const struct tm* GMT) const;
			std::string pad(long n, size_t length = 2) const;
		
			std::string getDayName(int day) const;
			std::string getMonthName(int month) const;
		
		public:
			bool afterRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response) override;
	};
}

#endif
