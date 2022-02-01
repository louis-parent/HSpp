#ifndef __CONNECTED_SERVER_SOCKET_H__
#define __CONNECTED_SERVER_SOCKET_H__

#include "Server.h"
#include "../connected/ConnectedSocket.h"
#include "../client/ConnectedClient.h"

namespace hspp
{
	class ConnectedServer : public Server, public ConnectedSocket
	{
		public:
			ConnectedServer(Port port);
			ConnectedServer(Descriptor descriptor, const SocketAddress& address);

			void listen(int maxQueueLength);
			ConnectedClient acceptClient();
		
			Descriptor c_fd() const override;
			const SocketProtocol getProtocol() const override;
	};
}

#endif
