#ifndef XML_UTILS
#define XML_UTILS

#include <iostream>
#include <vector>
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"

void GetTypeFromTiXmlElement(std::string& type, TiXmlElement* unitElement);
void GetIDFromTiXmlElement(int &id, TiXmlElement* unitElement);
void GetPositionFromTiXmlElement(std::vector<int>& pos, TiXmlElement* unitElement);

#endif // !XML_UTILS
