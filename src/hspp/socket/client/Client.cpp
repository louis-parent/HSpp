#include "Client.h"

using namespace hspp;

Client::Client(const std::string& address, Port port) : Socket(SocketAddress(address, port)) {}
Client::Client(Descriptor descriptor, const SocketAddress& address) : Socket(descriptor, address) {}

void Client::connect()
{
	struct sockaddr_in addr = this->c_addr();
	int result = ::connect(this->c_fd(), (struct sockaddr*) &addr, sizeof(addr));

	if(result == -1)
	{
		throw SocketFailure("Cannot connect socket");	
	}
}
