#ifndef __CONNECTED_CLIENT_SOCKET_H__
#define __CONNECTED_CLIENT_SOCKET_H__

#include "Client.h"
#include "../connected/ConnectedSocket.h"

namespace hspp
{
	class ConnectedClient : public Client, public ConnectedSocket
	{
		public:
			ConnectedClient(const std::string& address, Port port) : Client(address, port) {}
			ConnectedClient(Descriptor descriptor, const SocketAddress& address) : Client(descriptor, address) {}
		
			Descriptor c_fd() const override
			{
				return Client::c_fd();
			}
		
			const SocketProtocol getProtocol() const override
			{
				return ConnectedSocket::getProtocol();
			}
	};
}

#endif
