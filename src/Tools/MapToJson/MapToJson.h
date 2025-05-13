#ifndef _MAPTOJSON_
#define _MAPTOJSON_

#include <map>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

std::string unescapeJsonString(const std::string& input);
std::map<std::string, std::string> jsonToMap(const std::string& jsonStr);
std::string escapeJsonString(const std::string& input);
std::string mapToJson(const std::map<std::string, std::string>& data);

#endif // !_MAPTOJSON_


