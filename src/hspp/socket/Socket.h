#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <string>
#include <sys/types.h>
#include <sys/socket.h>

#include "exceptions/SocketFailure.h"
#include "protocol/SocketProtocol.h"
#include "address/SocketAddress.h"

namespace hspp
{
	typedef int Descriptor;
	
	class Socket
	{
		private:
			Descriptor descriptor;
			SocketAddress address;
		
		public:
			
			void open();
			void bind();
			void close();
			virtual bool isAlive() const;

			virtual const SocketProtocol getProtocol() const = 0;
			Port getPort() const;
			std::string getAddress() const;

			Descriptor c_fd() const;
			struct sockaddr_in c_addr() const;
				
		protected:
			Socket();
			Socket(Descriptor descriptor, const SocketAddress& address);
			Socket(SocketAddress address);
	};
}

#endif
