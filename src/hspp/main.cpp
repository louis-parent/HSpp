#include <iostream>
#include <thread>
#include "http/HTTPServlet.h"

using namespace hspp;

class NotWorkingServlet : public HTTPServlet
{
	public:
		NotWorkingServlet() : HTTPServlet(HTTPServlet::HTTP_PORT_DEV) {}
		
		
};

int main(int argc, char* argv[])
{
	NotWorkingServlet serv;
	std::thread t = serv.start();

	int stop;
	std::cin >> stop;
	serv.stop();
	
	t.join();
	
	return 0;
}
