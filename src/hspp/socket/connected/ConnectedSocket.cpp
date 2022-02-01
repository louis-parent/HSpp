#include "ConnectedSocket.h"

using namespace hspp;

const SocketProtocol ConnectedSocket::getProtocol() const
{
	return SocketProtocol::TCP;
}

void ConnectedSocket::shutdown()
{
	int result = ::shutdown(this->c_fd(), SHUT_RDWR);
	
	if(result == -1)
	{
		throw SocketFailure("Cannot shutdown socket");
	}
}

bool ConnectedSocket::send(const void* data, size_t length, bool sync) const
{
	ssize_t sended = ::send(this->c_fd(), data, length, sync ? 0 : MSG_DONTWAIT);
	
	if(sended >= 0)
	{
		return (size_t) sended == length;
	}
	else
	{
		throw SocketFailure("Cannot send data through connected socket");
	}
}

bool ConnectedSocket::receive(void* data, size_t* length, bool sync) const
{
	ssize_t received = ::recv(this->c_fd(), data, *length, sync ? 0 : MSG_DONTWAIT);
	
	if(received >= 0)
	{
		*length = received;
		return received > 0 && (size_t) received <= *length;
	}
	else
	{
		throw SocketFailure("Cannot receive data through connected socket");
	}
}
