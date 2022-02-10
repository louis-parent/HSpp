#include "Servlet.h"

using namespace hspp;

Servlet::Servlet(Port port, int queueLength) : socket(port), isRunning(false), queueLength(queueLength)
{
}
		
std::thread Servlet::start()
{
	this->socket.open();
	this->socket.bind();
	this->socket.listen(this->queueLength);
	
	this->onCreate();
	
	this->isRunning = true;	
    return std::thread(&Servlet::loop, this);
}

void Servlet::loop()
{
	while(this->isRunning)
	{
		ConnectedClient socket = this->socket.acceptClient();
		std::thread t = std::thread(&Servlet::transaction, this, socket);
		t.detach();
	}
}

void Servlet::transaction(ConnectedClient client)
{
	bool keepAlive = true;
	
	while(keepAlive)
	{
		Request request(client);

		if(request.hasReceived())
		{
			Response response(client);
			keepAlive = this->request(request, response);
			response.send();
		}
		else
		{
			keepAlive = false;
		}
	}

	client.close();
	
}

void Servlet::stop()
{
	this->isRunning = false;
	this->onDestroy();
	
	this->socket.shutdown();
	this->socket.close();
}
