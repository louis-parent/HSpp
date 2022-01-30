#include "SocketAddress.h"
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace hspp;

SocketAddress::SocketAddress()
{
	::bzero(&this->address, sizeof(this->address));
}

SocketAddress::SocketAddress(const SocketAddress& copy) : address(copy.address) {}

SocketAddress::SocketAddress(const std::string& ip, Port port)
{
}

SocketAddress::SocketAddress(Port port)
{
}

SocketAddress::SocketAddress(struct sockaddr_in address) : address(address)
{	
}

Port SocketAddress::getPort() const
{
	return ::htons(this->address.sin_port);
}

std::string SocketAddress::getAddress() const
{
	return std::string(::inet_ntoa(this->address.sin_addr));
}

struct sockaddr_in SocketAddress::c_addr() const
{
	return this->address;
}
