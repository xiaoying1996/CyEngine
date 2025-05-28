#include "XML_Utils.h"

std::string UnicodeToAscii(const std::wstring str)
{
    int	iTextLen = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
    std::vector<char> vecText(iTextLen, '\0');
    ::WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, &(vecText[0]), iTextLen, NULL, NULL);

    std::string strText = &(vecText[0]);

    return strText;
}

std::string UTF8ToString(const std::string& utf8Data)
{
    //先将UTF-8转换成Unicode
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::wstring wString = conv.from_bytes(utf8Data);
    //在转换成string
    return UnicodeToAscii(wString);
}

void GetTypeFromTiXmlElement(int& type, TiXmlElement* unitElement)
{
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
                              valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "typeEnum")
        {
            type = atoi(valElement->FirstChild()->Value());
        }
    }
}

void GetTypeNameFromTiXmlElement(std::string& type, TiXmlElement* unitElement)
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

void GetPositionFromTiXmlElement(std::vector<double>& pos, TiXmlElement* unitElement)
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
                    pos.push_back(atof(posElement->FirstChild()->Value()));
                }
                if (key == "lat")
                {
                    pos.push_back(atof(posElement->FirstChild()->Value()));
                }
                if (key == "alt")
                {
                    pos.push_back(atof(posElement->FirstChild()->Value()));
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
            name = UTF8ToString(name);
        }
    }
}

void GetCampFromTiXmlElement(int& camp, TiXmlElement* unitElement)
{
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
        valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "camp")
        {
            camp = atoi(valElement->FirstChild()->Value());
        }
    }
}

void GetAuthorizedFromXmlElement(int& jobType, string& authname, std::vector<int>& subordinates, TiXmlElement* unitElement)
{
    jobType = 0;
    authname = "";
    subordinates.clear();
    for (TiXmlElement* valElement = unitElement->FirstChildElement();
        valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "authorize")
        {
            for (TiXmlElement* authElement = valElement->FirstChildElement();
                authElement != nullptr; authElement = authElement->NextSiblingElement())
            {
                key = authElement->Value();
                if (key == "job")
                {
                    jobType = atoi(authElement->FirstChild()->Value());
                }
                if (key == "authname")
                {
                    authname = authElement->FirstChild()->Value();
                    authname = UTF8ToString(authname);
                }
                if (key == "subordinate")
                {
                    for (TiXmlElement* memberElement = authElement->FirstChildElement();
                        memberElement != nullptr; memberElement = memberElement->NextSiblingElement())
                    {
                        key = memberElement->Value();
                        {
                            if (key == "member")
                            {
                                subordinates.push_back(atoi(memberElement->FirstChild()->Value()));
                            }
                        }
                    }
                }
            }
        }
    }
}

int ReadSquadFormationFile(SquadStatu SqStu, int& FormationType, double& FormationOrientation, int& GroupLevel, StatusStruct StaStu, IntervalStruct& IntStu, vector<PlaceStruct>& PlaceStu)
{
    int i = 0;
    string filename = "data\\rules\\formation\\squad\\idle.xml";
    TiXmlDocument* xmlDocument = new TiXmlDocument();
    if (!xmlDocument->LoadFile(filename.c_str())) //没有test.xml文件
    {
        delete xmlDocument;
        return 1;
    }
    TiXmlElement* rootElement = xmlDocument->FirstChildElement("Rule");
    if (rootElement == nullptr) //节点不存在
    {
        delete xmlDocument;
        return 2;
    }
    for (TiXmlElement* valElement = rootElement->FirstChildElement();
        valElement != nullptr; valElement = valElement->NextSiblingElement())
    {
        std::string key = valElement->Value();
        if (key == "formation")
        {
            for (TiXmlElement* Element = valElement->FirstChildElement();
                Element != nullptr; Element = Element->NextSiblingElement())
            {
                string key1 = Element->Value();
                if ("type" == key1)
                {
                    FormationType = atoi(Element->FirstChild()->Value());
                }
            }
        }
        else if (key == "orientation")
        {
            for (TiXmlElement* Element = valElement->FirstChildElement();
                Element != nullptr; Element = Element->NextSiblingElement())
            {
                string key1 = Element->Value();
                if ("angle" == key1)
                {
                    FormationOrientation = atoi(Element->FirstChild()->Value());
                }
            }
        }
        else if (key == "place")
        {
            for (TiXmlElement* Element = valElement->FirstChildElement();
                Element != nullptr; Element = Element->NextSiblingElement())
            {
                string key1 = Element->Value();
                if ("Group" == key1)
                {
                    for (TiXmlElement* levelElement = Element->FirstChildElement();
                        levelElement != nullptr; levelElement = levelElement->NextSiblingElement())
                    {
                        string key2 = levelElement->Value();
                        if ("level" == key2)
                        {
                            GroupLevel = atoi(levelElement->FirstChild()->Value());
                        }
                    }
                }
                else if ("Soldier" == key1)
                {
                    for (TiXmlElement* levelElement = Element->FirstChildElement();
                        levelElement != nullptr; levelElement = levelElement->NextSiblingElement())
                    {
                        string key2 = levelElement->Value();
                        if ("F_ATTACK" == key2)
                        {
                            PlaceStruct ps;
                            ps.level = atoi(levelElement->FirstChild()->Value());
                            ps._type = M_HUMAN;
                            ps._fun = F_ATTACK;
                            PlaceStu.push_back(ps);
                        }
                        else if ("F_COVER" == key2)
                        {
                            PlaceStruct ps;
                            ps.level = atoi(levelElement->FirstChild()->Value());
                            ps._type = M_HUMAN;
                            ps._fun = F_COVER;
                            PlaceStu.push_back(ps);
                        }
                    }
                }
                else if ("UAV" == key1)
                {
                    for (TiXmlElement* levelElement = Element->FirstChildElement();
                        levelElement != nullptr; levelElement = levelElement->NextSiblingElement())
                    {
                        string key2 = levelElement->Value();
                        if ("F_ATTACK" == key2)
                        {
                            PlaceStruct ps;
                            ps.level = atoi(levelElement->FirstChild()->Value());
                            ps._type = M_UAV;
                            ps._fun = F_ATTACK;
                            PlaceStu.push_back(ps);
                        }
                        else if ("F_COVER" == key2)
                        {
                            PlaceStruct ps;
                            ps.level = atoi(levelElement->FirstChild()->Value());
                            ps._type = M_UAV;
                            ps._fun = F_COVER;
                            PlaceStu.push_back(ps);
                        }
                    }
                }
                else if ("Vehicle" == key1)
                {
                    for (TiXmlElement* levelElement = Element->FirstChildElement();
                        levelElement != nullptr; levelElement = levelElement->NextSiblingElement())
                    {
                        string key2 = levelElement->Value();
                        if ("F_ATTACK" == key2)
                        {
                            PlaceStruct ps;
                            ps.level = atoi(levelElement->FirstChild()->Value());
                            ps._type = M_VEHICLE;
                            ps._fun = F_ATTACK;
                            PlaceStu.push_back(ps);
                        }
                        else if ("F_COVER" == key2)
                        {
                            PlaceStruct ps;
                            ps.level = atoi(levelElement->FirstChild()->Value());
                            ps._type = M_VEHICLE;
                            ps._fun = F_COVER;
                            PlaceStu.push_back(ps);
                        }
                    }
                }
            }
        }
        else if (key == "statu")
        {
            for (TiXmlElement* Element = valElement->FirstChildElement();
                Element != nullptr; Element = Element->NextSiblingElement())
            {
                string key1 = Element->Value();
                if ("Soldier" == key1)
                {
                    StaStu._SoldierStu = atoi(Element->FirstChild()->Value());
                }
                else if ("UAV" == key1)
                {
                    StaStu._UAVStu = atoi(Element->FirstChild()->Value());
                }
                else if ("Vehicle" == key1)
                {
                    StaStu._VehicleStu = atoi(Element->FirstChild()->Value());
                }
            }
        }
    }
    return 0;
}

time_t GetCurrentTimeMsec() 
{
    auto time = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
    time_t timestamp = time.time_since_epoch().count();
    return timestamp;
}

LPCWSTR stringToLPCWSTR(string orig)
{
    size_t origsize = orig.length() + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t* wcstring = new wchar_t[sizeof(wchar_t) * (orig.length() - 1)];
    mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
    return wcstring;
}
