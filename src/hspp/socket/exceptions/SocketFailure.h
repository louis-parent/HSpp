#ifndef __SOCKET_FAILURE_H__
#define __SOCKET_FAILURE_H__

#include <ios>
#include <cerrno>
#include <cstring>

namespace hspp
{
	class SocketFailure : public std::ios_base::failure
	{
		public:
			SocketFailure(const std::string& message) : std::ios_base::failure(message + " : " + std::strerror(errno)) {}
	};
}

#endif
