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
			void transaction(ConnectedClient client);
		
		public:
			Servlet(Port port, int queueLength = 256);
		
			std::thread start();
			void stop();
		
		protected:
			virtual void onCreate() {}
			virtual bool request(const Request& request, Response& response) { return false; }
			virtual void onDestroy() {}		
	};
}

#endif
