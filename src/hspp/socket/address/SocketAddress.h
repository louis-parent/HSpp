#ifndef __SOCKET_ADDRESS_H__
#define __SOCKET_ADDRESS_H__

#include <netinet/in.h>
#include <string>

typedef unsigned short Port;

namespace hspp
{	
	class SocketAddress
	{
		private:
			struct sockaddr_in address;

		public:
			SocketAddress();
			SocketAddress(const SocketAddress& copy);
			SocketAddress(const std::string& ip, Port port);
			SocketAddress(Port port);
			SocketAddress(struct sockaddr_in address);
		
			Port getPort() const;
			std::string getAddress() const;
			struct sockaddr_in c_addr() const;
	};
}

#endif
