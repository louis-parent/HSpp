#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <string>
#include "../../socket/client/ConnectedClient.h"

namespace hspp
{
	class Response
	{
		private:
			ConnectedClient socket;
			std::string content;

		public:
			Response(const ConnectedClient& destination);

			const ConnectedClient& getDestination() const;
			const std::string& getContent() const;
		
			void setContent(const std::string& content);
			std::string& getContent();
		
			virtual void send();
	};
}

#endif
