#include "Utils.h"

using namespace hspp;

std::string Utils::slashPrefixed(const std::string& str)
{
	if(str[0] == '/')
	{
		return str;
	}
	else
	{
		
		return Utils::slashPrefixed((std::string&) str);
	}
}

std::string& Utils::slashPrefixed(std::string& str)
{
	if(str[0] != '/')
	{
		str = "/" + str;
	}
	
	return str;
}
