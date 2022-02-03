#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <string>
#include "../../socket/client/ConnectedClient.h"

namespace hspp
{
	class Request
	{
		private:
			ConnectedClient source;
			std::string content;

		public:
			Request(const ConnectedClient& source);
		
			const ConnectedClient& getSource() const;
			const std::string& getContent() const;
		
		private:
			void readAllFromSource();
	};
}

#endif
