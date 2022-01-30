#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__

#include "../Socket.h"

namespace hspp
{
	class Server : public Socket
	{
		protected:
			Server(Port port) : Socket(SocketAddress(port)) {}
			Server(Descriptor descriptor, const SocketAddress& address) : Socket(descriptor, address) {}
	};
}

#endif
