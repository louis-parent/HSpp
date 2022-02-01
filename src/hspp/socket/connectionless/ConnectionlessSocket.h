#ifndef __CONNECTIONLESS_SOCKET_H__
#define __CONNECTIONLESS_SOCKET_H__

#include "../Socket.h"
#include "../protocol/SocketProtocol.h"

namespace hspp
{
	class ConnectionlessSocket
	{
		public:
			virtual Descriptor c_fd() const = 0;
			virtual const SocketProtocol getProtocol() const;
			
			virtual bool sendTo(const void* data, size_t length, const SocketAddress& address, bool sync = true) const;
			virtual bool receiveFrom(void* data, size_t* length, SocketAddress& address, bool sync = true) const;
	};
}

#endif
