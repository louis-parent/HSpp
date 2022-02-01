#include "ConnectedServer.h"

using namespace hspp;

ConnectedServer::ConnectedServer(Port port) : Server(port) {}
ConnectedServer::ConnectedServer(Descriptor descriptor, const SocketAddress& address) : Server(descriptor, address) {}

void ConnectedServer::listen(int maxQueueLength)
{
	int result = ::listen(this->c_fd(), maxQueueLength);
	
	if(result == -1)
	{
		throw SocketFailure("Cannot listen on socket");
	}	
}

ConnectedClient ConnectedServer::acceptClient()
{
	struct sockaddr_in address;
	socklen_t addrLength = sizeof(address);
	
	int socket = ::accept(this->c_fd(), (struct sockaddr*) &address, &addrLength);
	
	if(socket != -1)
	{
		return ConnectedClient(socket, SocketAddress(address));
	}
	else
	{
		throw SocketFailure("Cannot accept client with socket");
	}
}

Descriptor ConnectedServer::c_fd() const
{
	return Server::c_fd();
}

const SocketProtocol ConnectedServer::getProtocol() const
{
	return ConnectedSocket::getProtocol();
}
