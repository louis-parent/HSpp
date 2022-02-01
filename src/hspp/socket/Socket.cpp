#include "Socket.h"

#include <unistd.h>

using namespace hspp;

void Socket::open()
{
	this->descriptor = socket(AF_INET, this->getProtocol().getType(), 0);

	if(this->descriptor == -1)
	{
		throw SocketFailure("Cannot open socket");
	}
}

void Socket::bind()
{
	struct sockaddr_in addr = this->address.c_addr();
	int result = ::bind(this->descriptor, (struct sockaddr*) &addr, sizeof(addr));
	
	if(result == -1)
	{
		throw SocketFailure("Cannot bind socket to address");
	}
}

void Socket::close()
{
	int result = ::close(this->descriptor);
		
	if(result == -1)
	{
		throw SocketFailure("Cannot close socket");
	}
}

bool Socket::isAlive() const
{
	return this->descriptor >= 0;
}

Port Socket::getPort() const
{
	return this->address.getPort();
}

std::string Socket::getAddress() const
{
	return this->address.getAddress();
}

Descriptor Socket::c_fd() const
{
	return this->descriptor;
}

struct sockaddr_in Socket::c_addr() const
{
	return this->address.c_addr();
}

Socket::Socket() : descriptor(-1) {}

Socket::Socket(Descriptor descriptor, const SocketAddress& address) : descriptor(descriptor), address(address) {}

Socket::Socket(SocketAddress address) : address(address) {}
