#ifndef __HTTP_METHOD_H__
#define __HTTP_METHOD_H__

#include <iostream>
#include "./exception/UnknownMethodError.h"

namespace hspp
{	
	class HTTPMethod
	{
		public:
			static const HTTPMethod GET;
			static const HTTPMethod HEAD;
			static const HTTPMethod POST;
			static const HTTPMethod PUT;
			static const HTTPMethod DELETE;
			static const HTTPMethod CONNECT;
			static const HTTPMethod OPTIONS;
			static const HTTPMethod TRACE;
			static const HTTPMethod PATCH;
		
			static const HTTPMethod& forName(const std::string& name);
			
			HTTPMethod();
			HTTPMethod(const HTTPMethod& other);
		
			HTTPMethod& operator=(const HTTPMethod& other);			
		
			friend std::ostream& operator<<(std::ostream& os, const HTTPMethod& method)
			{
				return os << method.name;
			}
		
		private:
			std::string name;
		
			HTTPMethod(const std::string& name);
	};
}

#endif
