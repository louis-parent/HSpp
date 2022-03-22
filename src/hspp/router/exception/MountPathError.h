#ifndef __MOUNT_PATH_ERROR_H__
#define __MOUNT_PATH_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class MountPathError : public std::runtime_error
	{
		public:
			MountPathError(const std::string& path, const std::string& reason) : runtime_error("The path '" + path + "' is not a valid mount path because " + reason)
			{}
	};
}

#endif
