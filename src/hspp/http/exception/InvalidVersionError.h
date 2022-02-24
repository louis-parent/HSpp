#ifndef __INVALID_VERSION_ERROR_H__
#define __INVALID_VERSION_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class InvalidVersionError : public std::range_error
	{
		public:
			InvalidVersionError(const std::string& invalidVersion) : range_error(invalidVersion + " is not a known HTTP version")
			{}
	};
}

#endif
