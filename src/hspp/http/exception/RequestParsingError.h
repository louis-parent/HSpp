#ifndef __REQUEST_PARSING_ERROR_H__
#define __REQUEST_PARSING_ERROR_H__

#include <stdexcept>

namespace hspp
{
	class RequestParsingError : public std::runtime_error
	{
		public:
			RequestParsingError(const std::string& reason) : runtime_error("Request cannot be parsed because " + reason)
			{}
	};
}

#endif
