#include "TimestampPlugin.h"

using namespace hspp;

std::string	TimestampPlugin::getGMT(const struct tm* GMT) const
{
	std::string str;
	
	str += this->getDayName(GMT->tm_wday);
	str += ", ";
	str += this->pad(GMT->tm_mday);
	str += " ";
	str += this->getMonthName(GMT->tm_mon);
	str += " ";
	str += std::to_string(1900 + GMT->tm_year);
	str += " ";
	str += this->pad(GMT->tm_hour);
	str += ":";
	str += this->pad(GMT->tm_min);
	str += ":";
	str += this->pad(GMT->tm_sec);
	str += " GMT";
					
	return str;
}

std::string TimestampPlugin::pad(long n, size_t length) const
{
	std::string num = std::to_string(n);
	
	if(num.length() < length)
	{
		for(size_t i = 0; i < (length - num.length()); i++)
		{
			num = "0" + num;
		}
	}
	
	return num;
}

std::string TimestampPlugin::getDayName(int day) const
{
	switch(day)
	{
		case 0:
			return "Mon";
		
		case 1:
			return "Tue";
		
		case 2:
			return "Wed";
		
		case 3:
			return "Thu";
		
		case 4:
			return "Fri";
		
		case 5:
			return "Sat";
		
		case 6:
			return "Sun";
		
		default:
			return "";
	}
}

std::string TimestampPlugin::getMonthName(int month) const
{
	switch(month)
	{
		case 0:
			return "Jan";
		
		case 1:
			return "Feb";
		
		case 2:
			return "Mar";
		
		case 3:
			return "Apr";
		
		case 4:
			return "May";
		
		case 5:
			return "Jun";
		
		case 6:
			return "Jul";
			
		case 7:
			return "Aug";
			
		case 8:
			return "Sep";
			
		case 9:
			return "Oct";
			
		case 10:
			return "Nov";
			
		case 11:
			return "Dec";
		
		default:
			return "";
	}
}

bool TimestampPlugin::afterRequest(const HTTPServlet& servlet, HTTPRequest& request, HTTPResponse& response)
{
	time_t rawtime;
	time(&rawtime);

	struct tm* GMT;
	GMT = gmtime(&rawtime);
	
	response.addHeader("Date", this->getGMT(GMT));
	return false;
}
