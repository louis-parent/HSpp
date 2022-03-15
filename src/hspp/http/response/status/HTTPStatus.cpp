#include "HTTPStatus.h"

using namespace hspp;

const HTTPStatus HTTPStatus::Continue = HTTPStatus(100, "Continue");
const HTTPStatus HTTPStatus::SwitchingProtocols = HTTPStatus(101, "Switching Protocols");
const HTTPStatus HTTPStatus::Processing = HTTPStatus(102, "Processing");
const HTTPStatus HTTPStatus::EarlyHints = HTTPStatus(103, "Early Hints");
const HTTPStatus HTTPStatus::OK = HTTPStatus(200, "OK");
const HTTPStatus HTTPStatus::Created = HTTPStatus(201, "Created");
const HTTPStatus HTTPStatus::Accepted = HTTPStatus(202, "Accepted");
const HTTPStatus HTTPStatus::NonAuthoritativeInformation = HTTPStatus(203, "Non-Authoritative Information");
const HTTPStatus HTTPStatus::NoContent = HTTPStatus(204, "No Content");
const HTTPStatus HTTPStatus::ResetContent = HTTPStatus(205, "Reset Content");
const HTTPStatus HTTPStatus::PartialContent = HTTPStatus(206, "Partial Content");
const HTTPStatus HTTPStatus::MultiStatus = HTTPStatus(207, "Multi-Status");
const HTTPStatus HTTPStatus::AlreadyReported = HTTPStatus(208, "Already Reported");
const HTTPStatus HTTPStatus::IMUsed = HTTPStatus(226, "IM Used ");
const HTTPStatus HTTPStatus::MultipleChoice = HTTPStatus(300, "Multiple Choice");
const HTTPStatus HTTPStatus::MovedPermanently = HTTPStatus(301, "Moved Permanently");
const HTTPStatus HTTPStatus::Found = HTTPStatus(302, "Found");
const HTTPStatus HTTPStatus::SeeOther = HTTPStatus(303, "See Other");
const HTTPStatus HTTPStatus::NotModified = HTTPStatus(304, "Not Modified");
const HTTPStatus HTTPStatus::UseProxy = HTTPStatus(305, "Use Proxy");
const HTTPStatus HTTPStatus::Unused = HTTPStatus(306, "Unused");
const HTTPStatus HTTPStatus::TemporaryRedirect = HTTPStatus(307, "Temporary Redirect");
const HTTPStatus HTTPStatus::PermanentRedirect = HTTPStatus(308, "Permanent Redirect");
const HTTPStatus HTTPStatus::BadRequest = HTTPStatus(400, "Bad Request");
const HTTPStatus HTTPStatus::Unauthorized = HTTPStatus(401, "Unauthorized");
const HTTPStatus HTTPStatus::PaymentRequired = HTTPStatus(402, "PaymentRequired");
const HTTPStatus HTTPStatus::Forbidden = HTTPStatus(403, "Forbidden");
const HTTPStatus HTTPStatus::NotFound = HTTPStatus(404, "Not Found");
const HTTPStatus HTTPStatus::MethodNotAllowed = HTTPStatus(405, "Method Not Allowed");
const HTTPStatus HTTPStatus::NotAcceptable = HTTPStatus(406, "Not Acceptable");
const HTTPStatus HTTPStatus::ProxyAuthenticationRequired = HTTPStatus(407, "Proxy Authentication Required");
const HTTPStatus HTTPStatus::RequestTimeout = HTTPStatus(408, "Request Timeout");
const HTTPStatus HTTPStatus::Conflict = HTTPStatus(409, "Conflict");
const HTTPStatus HTTPStatus::Gone = HTTPStatus(410, "Gone");
const HTTPStatus HTTPStatus::LengthRequired = HTTPStatus(411, "Length Required");
const HTTPStatus HTTPStatus::PreconditionFailed = HTTPStatus(412, "Precondition Failed");
const HTTPStatus HTTPStatus::PayloadTooLarge = HTTPStatus(413, "Payload Too Large");
const HTTPStatus HTTPStatus::URITooLong = HTTPStatus(414, "URI Too Long");
const HTTPStatus HTTPStatus::UnsupportedMediaType = HTTPStatus(415, "Unsupported Media Type");
const HTTPStatus HTTPStatus::RangeNotSatisfiable = HTTPStatus(416, "Range Not Satisfiable");
const HTTPStatus HTTPStatus::ExpectationFailed = HTTPStatus(417, "Expectation Failed");
const HTTPStatus HTTPStatus::Imateapot = HTTPStatus(418, "I'm a teapot");
const HTTPStatus HTTPStatus::MisdirectedRequest = HTTPStatus(421, "Misdirected Request");
const HTTPStatus HTTPStatus::UnprocessableEntity = HTTPStatus(422, "Unprocessable Entity");
const HTTPStatus HTTPStatus::Locked = HTTPStatus(423, "Locked");
const HTTPStatus HTTPStatus::FailedDependency = HTTPStatus(424, "Failed Dependency");
const HTTPStatus HTTPStatus::TooEarly = HTTPStatus(425, "Too Early");
const HTTPStatus HTTPStatus::UpgradeRequired = HTTPStatus(426, "Upgrade Required");
const HTTPStatus HTTPStatus::PreconditionRequired = HTTPStatus(428, "Precondition Required");
const HTTPStatus HTTPStatus::TooManyRequests = HTTPStatus(429, "Too Many Requests");
const HTTPStatus HTTPStatus::RequestHeaderFieldsTooLarge = HTTPStatus(431, "Request Header Fields Too Large");
const HTTPStatus HTTPStatus::UnavailableForLegalReasons = HTTPStatus(451, "Unavailable For Legal Reasons");
const HTTPStatus HTTPStatus::InternalServerError = HTTPStatus(500, "Internal Server Error");
const HTTPStatus HTTPStatus::NotImplemented = HTTPStatus(501, "Not Implemented");
const HTTPStatus HTTPStatus::BadGateway = HTTPStatus(502, "Bad Gateway");
const HTTPStatus HTTPStatus::ServiceUnavailable = HTTPStatus(503, "Service Unavailable");
const HTTPStatus HTTPStatus::GatewayTimeout = HTTPStatus(504, "Gateway Timeout");
const HTTPStatus HTTPStatus::HTTPVersionNotSupported = HTTPStatus(505, "HTTP Version Not Supported");
const HTTPStatus HTTPStatus::VariantAlsoNegotiates = HTTPStatus(506, "Variant Also Negotiates");
const HTTPStatus HTTPStatus::InsufficientStorage = HTTPStatus(507, "Insufficient Storage");
const HTTPStatus HTTPStatus::LoopDetected = HTTPStatus(508, "Loop Detected");
const HTTPStatus HTTPStatus::NotExtended = HTTPStatus(510, "Not Extended");
const HTTPStatus HTTPStatus::NetworkAuthenticationRequired = HTTPStatus(511, "Network Authentication Required");


HTTPStatus::HTTPStatus() : HTTPStatus(HTTPStatus::NotFound)
{
}

HTTPStatus::HTTPStatus(StatusCode code, const std::string& text) : code(code), text(text)
{
}

HTTPStatus::HTTPStatus(const HTTPStatus& other) : code(other.code), text(other.text)
{
}

HTTPStatus& HTTPStatus::operator=(const HTTPStatus& other)
{
	this->setCode(other.code);
	this->setText(other.text);
	return *this;
}

HTTPStatus& HTTPStatus::operator=(StatusCode code)
{
	this->setCode(code);
	return *this;
}

HTTPStatus& HTTPStatus::operator=(const std::string& text)
{
	this->setText(text);
	return *this;
}

StatusCode HTTPStatus::getCode() const
{
	return this->code;
}

void HTTPStatus::setCode(StatusCode code)
{
	this->code = code;
}

const std::string& HTTPStatus::getText() const
{
	return this->text;
}

void HTTPStatus::setText(const std::string& text)
{
	this->text = text;
}

bool HTTPStatus::operator==(const HTTPStatus& other) const
{
	return this->code == other.code;
}

bool HTTPStatus::operator<(const HTTPStatus& other) const
{
	return this->code < other.code;
}

bool HTTPStatus::operator<=(const HTTPStatus& other) const
{
	return this->code <= other.code;
}

bool HTTPStatus::operator>(const HTTPStatus& other) const
{
	return this->code > other.code;
}

bool HTTPStatus::operator>=(const HTTPStatus& other) const
{
	return this->code >= other.code;
}

bool HTTPStatus::operator==(StatusCode code) const
{
	return this->code == code;
}

bool HTTPStatus::operator<(StatusCode code) const
{
	return this->code < code;
}

bool HTTPStatus::operator<=(StatusCode code) const
{
	return this->code <= code;
}

bool HTTPStatus::operator>(StatusCode code) const
{
	return this->code > code;
}

bool HTTPStatus::operator>=(StatusCode code) const
{
	return this->code >= code;
}

bool HTTPStatus::operator==(const std::string& text) const
{
	return this->text == text;
}
