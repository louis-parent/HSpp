#include <iostream>
#include <thread>
#include "router/Router.h"

using namespace hspp;

class RequestPrinterAction : public RouteAction
{
	public:	
		bool process(const HTTPRequest& request, HTTPResponse& response) override
		{
			std::cout << "[LOG] " << request.getSource().getAddress() << " : " << request.getMethod() << " " << request.getTarget() << std::endl;
			return false;
		}
};

int main(int argc, char* argv[])
{
	std::cout << "Server Construction..." << std::endl;
	Router router(1999);
	
	std::cout << "Creation of routes..." << std::endl;
	router.get("/", new RequestPrinterAction());
	router.mount("/", "./static");
	
	std::cout << "Server Starting..." << std::endl;
	std::thread t = router.start();
	
	std::cout << "RUNNING : " << std::endl;
	
	std::string cmd;
	while(cmd != "stop")
	{
		std::cin >> cmd;
	}
	
	router.stop();
	t.join();
	
	return 0;
}
