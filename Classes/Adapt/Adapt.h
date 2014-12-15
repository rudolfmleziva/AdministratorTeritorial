#ifndef __ADAPT_H__
#define __ADAPT_H__

#include "cocos2d.h"

USING_NS_CC;

class Adapt
{
public:    
	/* Init func */
	Adapt();

	/* Destroy dunc */
	virtual ~Adapt();

	/* Create XML file */
	bool boCreateXMLFile(const std::string path);

};

#endif // __ADAPT_H__
