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

	/** Create Default XML file */
	bool boCreateDefaultXMLFile(const char * path);
private:

};

#endif // __ADAPT_H__
