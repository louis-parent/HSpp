#ifndef __ROUTING_ERROR_H__
#define __ROUTING_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class RoutingError : public std::runtime_error
	{
		public:
			RoutingError(const HTTPMethod& method, const std::string& target) : runtime_error("Undefined route " + method.getName() + " " + target)
			{}
	};
}

#endif
