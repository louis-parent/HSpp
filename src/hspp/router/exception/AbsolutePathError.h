#ifndef __ABSOLUTE_PATH_ERROR_H__
#define __ABSOLUTE_PATH_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class AbsolutePathError : public std::runtime_error
	{
		public:
			AbsolutePathError(const std::string& path) : runtime_error("The path '" + path + "' should not be an absolute path")
			{}
	};
}

#endif
