#include <iostream>
#include "socket/server/ConnectionlessServer.h"
#include "socket/client/ConnectionlessClient.h"

using namespace hspp;

int usage(char* name)
{
	std::cout << "Usage : " << name << " [client/server] [message]" << std::endl;
	return 1;
}

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		return usage(argv[0]);
	}
	
	if(std::string("server") == argv[1])
	{
		ConnectionlessServer server(8080);
		server.open();
		server.bind();
		
		std::cout << "=== Server started === " << std::endl;
		
		while(true)
		{
			std::cout << "Waiting client..." << std::endl;
			
			SocketAddress address;
			size_t bufferLen = 256;
			char buffer[bufferLen];
			server.receiveFrom(buffer, &bufferLen, &address);
			std::cout << address.getAddress() << " says : " << buffer << std::endl;
		}
	}
	else if(std::string("client") == argv[1])
	{
		if(argc != 3)
		{
			return usage(argv[0]);
		}
		
		std::string message(argv[2]);
		
		ConnectionlessClient client("localhost", 8080);
		client.open();
		client.sendTo(message.c_str(), message.size(), SocketAddress("localhost", 8080));
		client.close();
		
		std::cout << "Message sended" << std::endl;
	}

	return 0;
}
