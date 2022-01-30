#ifndef __CONNECTIONLESS_CLIENT_SOCKET_H__
#define __CONNECTIONLESS_CLIENT_SOCKET_H__

#include "Client.h"
#include "../connectionless/ConnectionlessSocket.h"

namespace hspp
{
	class ConnectionlessClient : public Client, public ConnectionlessSocket
	{
		public:
			ConnectionlessClient(const std::string& address, Port port) : Client(address, port) {}
			ConnectionlessClient(Descriptor descriptor, const SocketAddress& address) : Client(descriptor, address) {}
	
			Descriptor c_fd() const override
			{
				return Client::c_fd();
			}
		
			const SocketProtocol getProtocol() const override
			{
				return ConnectionlessSocket::getProtocol();
			}
	};
}

#endif
