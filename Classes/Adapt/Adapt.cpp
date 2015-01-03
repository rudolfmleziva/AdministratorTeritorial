#include "Adapt.hpp"
#include "pugixml.hpp"

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
