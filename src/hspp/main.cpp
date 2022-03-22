#include <iostream>
#include <thread>
#include "router/Router.h"

using namespace hspp;

class GreeterAction : public RouteAction
{
	public:	
		bool process(const HTTPRequest& request, HTTPResponse& response) override
		{
			response.setBody("Hello World !");
			return false;
		}
};

class EchoAction : public RouteAction
{
	public:	
		bool process(const HTTPRequest& request, HTTPResponse& response) override
		{
			response.setBody(request.getBody());
			return false;
		}
};

int main(int argc, char* argv[])
{
	std::cout << "Server Construction..." << std::endl;
	Router router(1999);
	
	std::cout << "Creation of routes..." << std::endl;
	router.mount("/", "./static");
	
	std::map<std::pair<const HTTPMethod, const std::string>, RouteAction*> routes = {
		{{HTTPMethod::GET, "greet"}, new GreeterAction()},
		{{HTTPMethod::GET, "echo"}, new EchoAction()}
	};
	router.prefixed("api", routes);
	
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
