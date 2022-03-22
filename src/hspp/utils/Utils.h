#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

namespace hspp
{
	class Utils
	{
		public:
			static std::string slashPrefixed(const std::string& str);
			static std::string& slashPrefixed(std::string& str);
	};
}

#endif 
