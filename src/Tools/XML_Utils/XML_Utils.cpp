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