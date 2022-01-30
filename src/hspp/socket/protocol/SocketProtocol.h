#ifndef __SOCKET_PROTOCOL_H__
#define __SOCKET_PROTOCOL_H__

#include <string>

#include <sys/types.h>
#include <sys/socket.h>

namespace hspp
{
	typedef int SocketType;
	
	class SocketProtocol
	{
		private:
			SocketType type;
			std::string name;
			
			SocketProtocol(SocketType type, const std::string& name);
		
		public:
			SocketType getType() const;
			std::string getName() const;
		
			static const SocketProtocol TCP;
			static const SocketProtocol UDP;
	};
}

#endif
