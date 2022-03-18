#ifndef __MIME_TYPE_H__
#define __MIME_TYPE_H__

#include <string>
#include <map>

namespace hspp
{
	class MimeType
	{
		private:
			static const std::map<std::string, MimeType> TYPES;	
			static const MimeType ALL;
		
			std::string extension;
			std::string type;
			std::string description;
		
		public:
			MimeType(const std::string& extension, const std::string& type, const std::string& description);
			
			const std::string& getExtension() const;
			const std::string& getType() const;
			const std::string& getDescription() const;
		
			static const MimeType& forExtension(const std::string& extension);
	};
}

#endif
