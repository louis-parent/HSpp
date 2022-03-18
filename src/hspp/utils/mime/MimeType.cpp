#include "MimeType.h"

using namespace hspp;

const std::map<std::string, MimeType> MimeType::TYPES = {
	{"aac", MimeType("aac", "audio/aac", "AAC audio")},
	{"abw", MimeType("abw", "application/x-abiword", "AbiWord document")},
	{"arc", MimeType("arc", "application/x-freearc", "Archive document (multiple files embedded)")},
	{"avif", MimeType("avif", "image/avif", "AVIF image")},
	{"avi", MimeType("avi", "video/x-msvideo", "AVI: Audio Video Interleave")},
	{"azw", MimeType("azw",	"application/vnd.amazon.ebook", "Amazon Kindle eBook format")},
	{"bin", MimeType("bin",	"application/octet-stream", "Any kind of binary data")},
	{"bmp", MimeType("bmp",	"image/bmp", "Windows OS/2 Bitmap Graphics")},
	{"bz", MimeType("bz", "application/x-bzip", "BZip archive")},
	{"bz2", MimeType("bz2",	"application/x-bzip2", "BZip2 archive")},
	{"cda", MimeType("cda", "application/x-cdf", "CD audio")},
	{"csh", MimeType("csh",	"application/x-csh", "C-Shell script")},
	{"css", MimeType("css",	"text/css", "Cascading Style Sheets (CSS)")},
	{"csv", MimeType("csv",	"text/csv", "Comma-separated values (CSV)")},
	{"doc", MimeType("doc",	"application/msword", "Microsoft Word")},
	{"docx", MimeType("docx", "application/vnd.openxmlformats-officedocument.wordprocessingml.document", "Microsoft Word (OpenXML)")},
	{"eot", MimeType("eot",	"application/vnd.ms-fontobject", "MS Embedded OpenType fonts")},
	{"epub", MimeType("epub", "application/epub+zip", "Electronic publication (EPUB)")},
	{"gz", MimeType("gz", "application/gzip", "GZip Compressed Archive")},
	{"gif", MimeType("gif", "image/gif", "Graphics Interchange Format (GIF)")},
	{"htm", MimeType("htm", "text/html", "HyperText Markup Language (HTML)")},
	{"html", MimeType("html", "text/html", "HyperText Markup Language (HTML)")},
	{"ico", MimeType("ico", "image/vnd.microsoft.icon", "Icon format")},
	{"ics", MimeType("ics", "text/calendar", "iCalendar format")},
	{"jar", MimeType("jar", "application/java-archive", "Java Archive (JAR)")},
	{"jpeg", MimeType("jpeg", "image/jpeg", "JPEG images")},
	{"jpg", MimeType("jpg", "image/jpeg", "JPEG images")},
	{"js", MimeType("js", "text/javascript", "JavaScript")},
	{"json", MimeType("json", "application/json", "JSON format")},
	{"jsonld", MimeType("jsonld", "application/ld+json", "JSON-LD format")},
	{"mid", MimeType("mid", "audio/midi audio/x-midi", "Musical Instrument Digital Interface (MIDI)")},
	{"midi", MimeType("midi", "audio/midi audio/x-midi", "Musical Instrument Digital Interface (MIDI)")},
	{"mjs", MimeType("mjs", "text/javascript", "JavaScript module")},
	{"mp3", MimeType("mp3", "audio/mpeg", "MP3 audio")},
	{"mp4", MimeType("mp4", "video/mp4", "MP4 video")},
	{"mpeg", MimeType("mpeg", "video/mpeg", "MPEG Video")},
	{"mpkg", MimeType("mpkg", "application/vnd.apple.installer+xml", "Apple Installer Package")},
	{"odp", MimeType("odp", "application/vnd.oasis.opendocument.presentation", "OpenDocument presentation document")},
	{"ods", MimeType("ods", "application/vnd.oasis.opendocument.spreadsheet", "OpenDocument spreadsheet document")},
	{"odt", MimeType("odt",	"application/vnd.oasis.opendocument.text", "OpenDocument text document")},
	{"oga", MimeType("oga", "audio/ogg", "OGG audio")},
	{"ogv", MimeType("ogv", "video/ogg", "OGG video")},
	{"ogx", MimeType("ogx", "application/ogg", "OGG")},
	{"opus", MimeType("opus", "audio/opus", "Opus audio")},
	{"otf", MimeType("otf", "font/otf", "OpenType font")},
	{"png", MimeType("png", "image/png", "Portable Network Graphics")},
	{"pdf", MimeType("pdf", "application/pdf", "Adobe Portable Document Format (PDF)")},
	{"php", MimeType("php", "application/x-httpd-php", "Hypertext Preprocessor (Personal Home Page)")},
	{"ppt", MimeType("ppt", "application/vnd.ms-powerpoint", "Microsoft PowerPoint")},
	{"pptx", MimeType("pptx", "application/vnd.openxmlformats-officedocument.presentationml.presentation", "Microsoft PowerPoint (OpenXML)")},
	{"rar", MimeType("rar", "application/vnd.rar", "RAR archive")},
	{"rtf", MimeType("rtf", "application/rtf", "Rich Text Format (RTF)")},
	{"sh", MimeType("sh", "application/x-sh", "Bourne shell script")},
	{"svg", MimeType("svg", "image/svg+xml", "Scalable Vector Graphics (SVG)")},
	{"swf", MimeType("swf", "application/x-shockwave-flash", "Small web format (SWF) or Adobe Flash document")},
	{"tar", MimeType("tar", "application/x-tar", "Tape Archive (TAR)")},
	{"tif", MimeType("tif", "image/tiff", "Tagged Image File Format (TIFF)")},
	{"tiff", MimeType("tiff", "image/tiff", "Tagged Image File Format (TIFF)")},
	{"ts", MimeType("ts", "video/mp2t", "MPEG transport stream")},
	{"ttf", MimeType("ttf", "font/ttf", "TrueType Font")},
	{"txt", MimeType("txt", "text/plain", "Text, (generally ASCII or ISO 8859-n)")},
	{"vsd", MimeType("vsd", "application/vnd.visio", "Microsoft Visio")},
	{"wav", MimeType("wav", "audio/wav", "Waveform Audio Format")},
	{"weba", MimeType("weba", "audio/webm", "WEBM audio")},
	{"webm", MimeType("webm", "video/webm", "WEBM video")},
	{"webp", MimeType("webp", "image/webp", "WEBP image")},
	{"woff", MimeType("woff", "font/woff", "Web Open Font Format (WOFF)")},
	{"woff2", MimeType("woff2", "font/woff2", "Web Open Font Format (WOFF)")},
	{"xhtml", MimeType("xhtml", "application/xhtml+xml", "XHTML")},
	{"xls", MimeType("xls", "application/vnd.ms-excel", "Microsoft Excel")},
	{"xlsx", MimeType("xlsx", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", "Microsoft Excel (OpenXML)")},
	{"xml", MimeType("xml", "application/xml", "XML")},
	{"xul", MimeType("xul", "application/vnd.mozilla.xul+xml", "XUL")},
	{"zip", MimeType("zip", "application/zip", "ZIP archive")},
	{"3gp", MimeType("3gp", "video/3gpp", "3GPP audio/video container")},
	{"3g2", MimeType("3g2", "video/3gpp2", "3GPP2 audio/video container")},
	{"7z", MimeType("7z", "application/x-7z-compressed", "7-zip archive")}
};
	
const MimeType MimeType::ALL = MimeType("", "*/*", "All files");

MimeType::MimeType(const std::string& extension, const std::string& type, const std::string& description) : extension(extension), type(type), description(description)
{
}
			
const std::string& MimeType::getExtension() const
{
	return this->extension;
}
const std::string& MimeType::getType() const
{
	return this->type;
}

const MimeType& MimeType::forExtension(const std::string& extension)
{
	if(MimeType::TYPES.count(extension) > 0)
	{
		return MimeType::TYPES.at(extension);
	}
	else
	{
		return MimeType::ALL;
	}
}
