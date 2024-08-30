#ifndef XML_UTILS
#define XML_UTILS

#include <iostream>
#include <vector>
#include <locale>
#include <codecvt>
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"

typedef std::basic_string<char> byte_string;

void GetTypeFromTiXmlElement(std::string& type, TiXmlElement* unitElement);
void GetIDFromTiXmlElement(int &id, TiXmlElement* unitElement);
void GetPositionFromTiXmlElement(std::vector<int>& pos, TiXmlElement* unitElement);
void GetNameFromTiXmlElement(std::string &name, TiXmlElement* unitElement);

#endif // !XML_UTILS
