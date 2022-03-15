#ifndef __ROUTING_ERROR_H__
#define __ROUTING_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class RoutingError : public std::runtime_error
	{
		public:
			RoutingError(const std::string& reason) : runtime_error(reason)
			{}
	};
}

#endif
