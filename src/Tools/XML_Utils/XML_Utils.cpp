#include "XML_Utils.h"

void GetTypeFromTiXmlElement(std::string& type, TiXmlElement* unitElement)
{
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
                              valElement != nullptr; valElement = valElement->NextSiblingElement())
        {
            std::string key = valElement->Value();
            if (key == "type")
            {
                type = valElement->FirstChild()->Value();
            }
        }
}

void GetIDFromTiXmlElement(int &id, TiXmlElement* unitElement)
{
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
        valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "id")
        {
            id = atoi(valElement->FirstChild()->Value());
        }
    }
}

void GetPositionFromTiXmlElement(std::vector<int>& pos, TiXmlElement* unitElement)
{
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
        valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "position")
        {
            for (TiXmlElement* posElement = valElement->FirstChildElement();
                posElement != nullptr; posElement = posElement->NextSiblingElement())
            {
                key = posElement->Value();
                if (key == "lon")
                {
                    pos.push_back(atoi(posElement->FirstChild()->Value()));
                }
                if (key == "lat")
                {
                    pos.push_back(atoi(posElement->FirstChild()->Value()));
                }
                if (key == "alt")
                {
                    pos.push_back(atoi(posElement->FirstChild()->Value()));
                }
            }
        }
    }
}

void GetNameFromTiXmlElement(std::string& name, TiXmlElement* unitElement)
{
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
        valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "name")
        {
            name = valElement->FirstChild()->Value();
            //name = name.
        }
    }
}

std::string UTF8ToString(const std::string& utf8Data)
{
    //先将UTF-8转换成Unicode
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::wstring wString = conv.from_bytes(utf8Data);
    //在转换成string
    return UnicodeToAscii(wString);
}
