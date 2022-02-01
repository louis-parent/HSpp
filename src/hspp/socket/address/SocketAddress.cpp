#include "SocketAddress.h"

#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace hspp;


SocketAddress::SocketAddress(const std::string& ip, Port port) : SocketAddress(port)
{
	struct hostent* host = ::gethostbyname(ip.c_str());
	::bcopy(host->h_addr_list[0], &this->address.sin_addr.s_addr, host->h_length);
}

SocketAddress::SocketAddress(Port port) : SocketAddress()
{
	this->address.sin_family = AF_INET;
	this->address.sin_port = ::htons(port);
	this->address.sin_addr.s_addr = INADDR_ANY;
}

SocketAddress::SocketAddress()
{
	::bzero(&this->address, sizeof(this->address));
}

SocketAddress::SocketAddress(struct sockaddr_in address) : address(address)
{
}

SocketAddress::SocketAddress(const SocketAddress& copy) : address(copy.address)
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

struct sockaddr_in& SocketAddress::c_addr()
{
	return this->address;
}
