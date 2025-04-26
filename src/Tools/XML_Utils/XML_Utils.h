#ifndef XML_UTILS
#define XML_UTILS

#include <iostream>
#include <vector>
#include <locale>
#include <codecvt>
#include <windows.h>
#include <wchar.h>
#include <chrono>
#include <time.h>
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"

using namespace std;

typedef std::basic_string<char> byte_string;

void GetTypeFromTiXmlElement(std::string& type, TiXmlElement* unitElement);
void GetIDFromTiXmlElement(int &id, TiXmlElement* unitElement);
void GetPositionFromTiXmlElement(std::vector<int>& pos, TiXmlElement* unitElement);
void GetNameFromTiXmlElement(std::string &name, TiXmlElement* unitElement);
std::string UTF8ToString(const std::string& utf8Data);
LPCWSTR stringToLPCWSTR(string orig);
time_t GetCurrentTimeMsec();

#endif // !XML_UTILS
