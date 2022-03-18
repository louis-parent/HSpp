#ifndef __MOUNTING_ERROR_H__
#define __MOUNTING_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class MountingError : public std::runtime_error
	{
		public:
			MountingError(const std::string& path) : runtime_error("Try to mount " + path + " as static available file which is neither a regular file or a directory")
			{}
	};
}

#endif
