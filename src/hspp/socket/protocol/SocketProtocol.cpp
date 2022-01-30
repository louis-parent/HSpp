#include "SocketProtocol.h"

using namespace hspp;

const SocketProtocol SocketProtocol::TCP = SocketProtocol(SOCK_STREAM, "TCP");
const SocketProtocol SocketProtocol::UDP = SocketProtocol(SOCK_DGRAM, "UDP");

SocketProtocol::SocketProtocol(SocketType type, const std::string& name) : type(type), name(name) {}

SocketType SocketProtocol::getType() const
{
	return this->type;
}

std::string SocketProtocol::getName() const
{
	return this->name;
}
