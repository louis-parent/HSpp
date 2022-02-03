#ifndef __SERVLET_H__
#define __SERVLET_H__

#include <thread>

#include "../socket/server/ConnectedServer.h"
#include "request/Request.h"
#include "response/Response.h"

namespace hspp
{	
	class Servlet
	{
		private:
			ConnectedServer socket;
			bool isRunning;
			int queueLength;
		
			void loop();
		
		public:
			Servlet(Port port, int queueLength);
		
			std::thread start();
			void stop();
		
		protected:
			virtual void onCreate() {}
			virtual void request(const Request& request, Response& response) {}
			virtual void onDestroy() {}		
	};
}

#endif
