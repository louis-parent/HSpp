#include <iostream>
#include <thread>
#include "http/HTTPServlet.h"
#include "http/plugins/KeepAlivePlugin.h"

using namespace hspp;

class RequestPrinterServlet : public HTTPServlet
{
	public:
		RequestPrinterServlet() : HTTPServlet(1999)
		{
		}
		
		bool request(const HTTPRequest& request, HTTPResponse& response)
		{
			std::cout << "[LOG] " << request.getSource().getAddress() << " : " << request.getMethod() << " " << request.getTarget() << std::endl;
			return false;
		}
};

int main(int argc, char* argv[])
{
	RequestPrinterServlet serv;
	std::thread t = serv.start();

	int stop;
	std::cin >> stop;
	serv.stop();
	
	t.join();
	
	return 0;
}
