#ifndef __CONNECTIONLESS_SERVER_SOCKET_H__
#define __CONNECTIONLESS_SERVER_SOCKET_H__

#include "Server.h"
#include "../connectionless/ConnectionlessSocket.h"

namespace hspp
{
	class ConnectionlessServer : public Server, public ConnectionlessSocket
	{
		public:
			ConnectionlessServer(Port port) : Server(port) {}
			ConnectionlessServer(Descriptor descriptor, const SocketAddress& address) : Server(descriptor, address) {}
		
			Descriptor c_fd() const override
			{
				return Server::c_fd();
			}
		
			const SocketProtocol getProtocol() const override
			{
				return ConnectionlessSocket::getProtocol();
			}
	};
}

#endif
