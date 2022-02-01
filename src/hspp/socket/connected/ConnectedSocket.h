#ifndef __CONNECTED_SOCKET_H__
#define __CONNECTED_SOCKET_H__

#include "../Socket.h"
#include "../protocol/SocketProtocol.h"

namespace hspp
{
	class ConnectedSocket
	{
		public:
			virtual Descriptor c_fd() const = 0;
			virtual const SocketProtocol getProtocol() const;
		
			void shutdown();
		
			virtual bool send(const void* data, size_t length, bool sync = true) const;
			virtual bool receive(void* data, size_t* length, bool sync = true) const;
	};
}

#endif
