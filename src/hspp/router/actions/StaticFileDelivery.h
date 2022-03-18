#ifndef __STATIC_FILE_DELIVERY_H__
#define __STATIC_FILE_DELIVERY_H__

#include "../RouteAction.h"

#include <string>
#include <fstream>

#include "../../utils/mime/MimeType.h"

namespace hspp
{
	class StaticFileDelivery : public RouteAction
	{
		private:
			std::string path;
		
		public:
			StaticFileDelivery(const std::string& path) : path(path) {}
		
			bool process(const HTTPRequest& request, HTTPResponse& response)
			{
				std::ifstream stream(this->path);
  				std::string content((std::istreambuf_iterator<char>(stream)), (std::istreambuf_iterator<char>()));
				
				std::string extension = this->path.substr(this->path.find_last_of(".") + 1); 
				
				response.setStatus(HTTPStatus::OK);
				response.addHeader("Content-Type", MimeType::forExtension(extension).getType());
				response.addHeader("Content-Length", std::to_string(content.size()));
				response.setBody(content);
				
				return false;
			}
	};
}

#endif
