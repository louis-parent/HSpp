#include <iostream>
#include <thread>
#include "socket/client/ConnectedClient.h"
#include "servlet/Servlet.h"

using namespace hspp;

class PrinterServlet : public Servlet
{
	public:
		PrinterServlet(Port port, int queue) : Servlet(port, queue) {}
		
		void onCreate() override {
			std::cout << "===== SERVER STARTED =====" << std::endl;
		}
		
		void request(const Request& request, Response& response) override {
			std::cout << request.getSource().getAddress() << " says : " << request.getContent() << std::endl;
			response.getContent() += "DONE";
		}
};

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
	else if(std::string("server") == argv[1])
	{
		PrinterServlet serv(3000, 100);
		std::thread t = serv.start();
		
		int stop;
		std::cin >> stop;
		serv.stop();
		
		return 0;
	}
	else if(std::string("client") == argv[1])
	{
		if(argc != 3)
		{
			return usage(argv[0]);
		}
		
		std::string message(argv[2]);
		
		ConnectedClient client("localhost", 3000);
		client.open();
		client.connect();
		
		client.send(message.c_str(), message.size());
		
		size_t size = 5;
		char buff[size];
		client.receive(buff, &size);
		std::cout << buff << std::endl;
		
		client.close();
		
		std::cout << "Message sended" << std::endl;
		return 0;
	}
	else
	{
		return usage(argv[0]);
	}
}
