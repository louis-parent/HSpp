#ifndef __UNKNOWN_METHOD_ERROR_H__
#define __UNKNOWN_METHOD_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class UnknownMethodError : public std::range_error
	{
		public:
			UnknownMethodError(const std::string& invalidMethod) : range_error(invalidMethod + " is not a valid HTTP method")
			{}
	};
}

#endif
