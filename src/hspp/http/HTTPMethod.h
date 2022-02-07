#ifndef __HTTP_METHOD_H__
#define __HTTP_METHOD_H__

namespace hspp
{
	enum class HTTPMethod
	{
		GET,
		HEAD,
		POST,
		PUT,
		DELETE,
		CONNECT,
		OPTIONS,
		TRACE,
		PATCH
	};
}

#endif
