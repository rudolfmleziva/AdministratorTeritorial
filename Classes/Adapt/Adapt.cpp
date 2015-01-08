#include "Adapt.hpp"
#include "pugixml.hpp"
#include <codecvt>

using namespace std;

Adapt::Adapt()
{
	/* create the object */
}

Adapt::~Adapt()
{
}

/** Create Default XML file */
bool Adapt::boCreateDefaultXMLFile(const char * path)
{
	pugi::xml_document doc;
	return doc.save_file(path);
}

void Adapt::vReadAvailableLanguages(const char * path)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(path);
	unsigned int langNumber = 0;
	for (pugi::xml_node node = doc.child(L"Configuration").child(L"Languages").first_child(); node; node = node.next_sibling())
	{
		InternalSettings::Instance()->IS_vSetLanguageConfiguration(stoi(node.attribute(L"ID").value()), 
			node.attribute(L"Val").value(), UTF8TOGBK(node.attribute(L"Path").value()));
		langNumber++;
	}
	InternalSettings::Instance()->IS_vSetNumberOfAvailableLanguages(langNumber);
}

std::string Adapt::UTF8TOGBK(const wstring & text)
{

	int asciisize = WideCharToMultiByte(CP_UTF8, 0, text.c_str(), text.size(), NULL, 0, NULL, NULL);
	if (asciisize == ERROR_NO_UNICODE_TRANSLATION ||
		asciisize == 0)
	{
		return string();
	}
	char * resultstring = new char[asciisize];
	int convresult = WideCharToMultiByte(CP_UTF8, 0, text.c_str(), text.size(), resultstring, asciisize, NULL, NULL);
	if (convresult!= asciisize)
	{
		return string();
	}
	std::string buffer(resultstring, convresult);
	delete resultstring;
	return buffer;
}

// convert UTF-8 string to wstring
std::wstring Adapt::utf8_to_wstring(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(str);
}

// convert wstring to UTF-8 string
std::string Adapt::wstring_to_utf8(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}