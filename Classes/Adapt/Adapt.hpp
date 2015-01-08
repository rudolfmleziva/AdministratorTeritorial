#ifndef __ADAPT_H__
#define __ADAPT_H__

#include "cocos2d.h"
#include "InternalSettings.hpp"
#include <string>


USING_NS_CC;

class Adapt
{
public:    
	/* Init func */
	Adapt();

	/* Destroy dunc */
	virtual ~Adapt();

	/** Create Default XML file */
	bool boCreateDefaultXMLFile(const char * path);

	/* Get available languages */
	void vReadAvailableLanguages(const char * path);

	/* convert from wstring to string */
	std::string UTF8TOGBK(const wstring & text);

	/* convert utf8 to wstring */
	std::wstring utf8_to_wstring(const std::string& str);

	/* convert wstring to utf8 */
	std::string wstring_to_utf8(const std::wstring& str);
private:

};

#endif // __ADAPT_H__
