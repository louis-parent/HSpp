# HSpp

**HTTP Server++** (*HSpp*)  is a simple and extensible *HTTP* server in *C++*.
It's composed of multiple layer from socket to modern routing system.

## Layers

This part is dedicated to an overview of the different layers of *HSpp* from bottom to top.

### Socket

The *Socket* layer is the nearest layer of the system. It consists in an object binding of the *C* *socket* caracterized by address and port.
The *Socket* can either be client or server, and connected or connectionless. Connected and connectionless are tradionnality implemented with *TCP* and *UDP*.

### Servlet

The *Servlet* layer (inspired by *Java*) represents a server that can handle connected request of any kind.
The *Servlet* run itself the client handling and client processing in a seperated *Thread*.
The client processing treat the *Request* as a string and fill a *Response* as a string.
The lifecycle of a server is very simple : 
`constructor()` -> `onCreate()` (at startup) -> `request()` (lifetime) -> `onDestroy()` (at shutdow) -> `~destructor()`.

### HTTP Servlet

The *HTTP Servlet* is a specification of the *Servlet* in the case of *HTTP* request. It specifies the *Request* and *Response* with the standard *HTTP* structure.
The *HTTP Servlet* add util methods for each *HTTP Method* aside the generic request method.

### Router

The *Router* layer is the hightest level layer. It abstracts the system of client-server and only work with route.
The behavior for each route is represented by a *RouteAction*. Actions can be added by different way inspired by *Express.js*.

## Usage

The *Main* class is a simple example of the router usage and can be compiled using `make` wich produce an executable file `hspp`.
The project is made to be a framework and the source can be used in any project. All the class are in the *hspp* namespace to be used in various projects.
