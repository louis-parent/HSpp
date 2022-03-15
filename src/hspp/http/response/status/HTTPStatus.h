#ifndef __HTTP_STATUS_H__
#define __HTTP_STATUS_H__

#include <iostream>

typedef unsigned int StatusCode;

namespace hspp
{
	class HTTPStatus
	{
		private:
			StatusCode code;
			std::string text;
		
		public:
			static const HTTPStatus Continue;
			static const HTTPStatus SwitchingProtocols;
			static const HTTPStatus Processing;
			static const HTTPStatus EarlyHints;
			static const HTTPStatus OK;
			static const HTTPStatus Created;
			static const HTTPStatus Accepted;
			static const HTTPStatus NonAuthoritativeInformation;
			static const HTTPStatus NoContent;
			static const HTTPStatus ResetContent;
			static const HTTPStatus PartialContent;
			static const HTTPStatus MultiStatus;
			static const HTTPStatus AlreadyReported;
			static const HTTPStatus IMUsed;
			static const HTTPStatus MultipleChoice;
			static const HTTPStatus MovedPermanently;
			static const HTTPStatus Found;
			static const HTTPStatus SeeOther;
			static const HTTPStatus NotModified;
			static const HTTPStatus UseProxy;
			static const HTTPStatus Unused;
			static const HTTPStatus TemporaryRedirect;
			static const HTTPStatus PermanentRedirect;
			static const HTTPStatus BadRequest;
			static const HTTPStatus Unauthorized;
			static const HTTPStatus PaymentRequired;
			static const HTTPStatus Forbidden;
			static const HTTPStatus NotFound;
			static const HTTPStatus MethodNotAllowed;
			static const HTTPStatus NotAcceptable;
			static const HTTPStatus ProxyAuthenticationRequired;
			static const HTTPStatus RequestTimeout;
			static const HTTPStatus Conflict;
			static const HTTPStatus Gone;
			static const HTTPStatus LengthRequired;
			static const HTTPStatus PreconditionFailed;
			static const HTTPStatus PayloadTooLarge;
			static const HTTPStatus URITooLong;
			static const HTTPStatus UnsupportedMediaType;
			static const HTTPStatus RangeNotSatisfiable;
			static const HTTPStatus ExpectationFailed;
			static const HTTPStatus Imateapot;
			static const HTTPStatus MisdirectedRequest;
			static const HTTPStatus UnprocessableEntity;
			static const HTTPStatus Locked;
			static const HTTPStatus FailedDependency;
			static const HTTPStatus TooEarly;
			static const HTTPStatus UpgradeRequired;
			static const HTTPStatus PreconditionRequired;
			static const HTTPStatus TooManyRequests;
			static const HTTPStatus RequestHeaderFieldsTooLarge;
			static const HTTPStatus UnavailableForLegalReasons;
			static const HTTPStatus InternalServerError;
			static const HTTPStatus NotImplemented;
			static const HTTPStatus BadGateway;
			static const HTTPStatus ServiceUnavailable;
			static const HTTPStatus GatewayTimeout;
			static const HTTPStatus HTTPVersionNotSupported;
			static const HTTPStatus VariantAlsoNegotiates;
			static const HTTPStatus InsufficientStorage;
			static const HTTPStatus LoopDetected;
			static const HTTPStatus NotExtended;
			static const HTTPStatus NetworkAuthenticationRequired;
		
			HTTPStatus();
			HTTPStatus(StatusCode code, const std::string& text = "");
			HTTPStatus(const HTTPStatus& other);
		
			HTTPStatus& operator=(const HTTPStatus& other);
			HTTPStatus& operator=(StatusCode code);
			HTTPStatus& operator=(const std::string& text);
		
			StatusCode getCode() const;
			void setCode(StatusCode code);
		
			const std::string& getText() const;
			void setText(const std::string& text);
		
			bool operator==(const HTTPStatus& other) const;
			bool operator<(const HTTPStatus& other) const;
			bool operator<=(const HTTPStatus& other) const;
			bool operator>(const HTTPStatus& other) const;
			bool operator>=(const HTTPStatus& other) const;
		
			friend std::ostream& operator<<(std::ostream& os, const HTTPStatus& status)
			{
				return os << status.code << " " << status.text;
			}
	};
}
#endif
