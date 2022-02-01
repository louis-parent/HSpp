#ifndef __CLIENT_SOCKET_H__
#define __CLIENT_SOCKET_H__

#include "../Socket.h"
#include <string>

namespace hspp
{
	class Client : public Socket
	{
		public:
			void connect();

		protected:
			Client(const std::string& address, Port port);	
			Client(Descriptor descriptor, const SocketAddress& address);
	};
}

#endif
