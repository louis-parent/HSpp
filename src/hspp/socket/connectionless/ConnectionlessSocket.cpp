#include "ConnectionlessSocket.h"

using namespace hspp;

const SocketProtocol ConnectionlessSocket::getProtocol() const
{
	return SocketProtocol::UDP;	
}

bool ConnectionlessSocket::sendTo(void* data, size_t length, const SocketAddress& address, bool sync) const
{
	struct sockaddr_in addr = address.c_addr();
	
	ssize_t sended = ::sendto(this->c_fd(), data, length, sync ? 0 : MSG_DONTWAIT, (struct sockaddr*) &addr, sizeof(addr));

	if(sended >= 0)
	{
		return (size_t) sended == length;
	}
	else
	{
		throw SocketFailure("Cannot send data through connectionless socket");
	}
}

bool ConnectionlessSocket::receiveFrom(void* data, size_t* length, SocketAddress* address, bool sync) const
{
	struct sockaddr_in socketAddress;
	socklen_t addressLength;
	
	ssize_t received = ::recvfrom(this->c_fd(), data, *length, sync ? 0 : MSG_DONTWAIT, (struct sockaddr*) &socketAddress, &addressLength);
	
	if(received >= 0)
	{
		*length = received;
		address = new SocketAddress(socketAddress);
		
		return received > 0 && (size_t) received <= *length;
	}
	else
	{
		throw SocketFailure("Cannot received data through connectionless socket");
	}
}
