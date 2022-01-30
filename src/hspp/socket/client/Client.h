#ifndef __CLIENT_SOCKET_H__
#define __CLIENT_SOCKET_H__

#include "../Socket.h"
#include <string>

namespace hspp
{
	class Client : public Socket
	{
		public:
			bool connect();

		protected:
			Client(const std::string& address, Port port);	
			Client(Descriptor descriptor, const SocketAddress& address);
	};
}

#endif
