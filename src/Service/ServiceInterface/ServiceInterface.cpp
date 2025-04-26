#include "ServiceInterface.h"
#include <tinyxml/tinyxml.h>


std::mutex ServiceInterface::m_Mutex;

ServiceInterface::ServiceInterface()
{
    m_IsInterfaceLoad = false;
}

ServiceInterface* ServiceInterface::GetInstance()
{
    if (m_ServiceInterface == nullptr)
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (m_ServiceInterface == nullptr)
        {
            m_ServiceInterface = new (std::nothrow) ServiceInterface();
        }
    }
    return m_ServiceInterface;
}

void ServiceInterface::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex);
    if (m_ServiceInterface)
    {
        delete m_ServiceInterface;
        m_ServiceInterface = nullptr;
    }
}

ServiceInterface::~ServiceInterface()
{
}

void ServiceInterface::LoadInterface()
{
    if (!m_IsInterfaceLoad)
    {
		TiXmlDocument* xmlDocument = new TiXmlDocument();
		if (!xmlDocument->LoadFile("data\\config\\Service.config"))
		{
			std::string err = xmlDocument->ErrorDesc();
		}
		TiXmlElement* rootElement = xmlDocument->FirstChildElement("Services");
		if (rootElement == nullptr) //节点不存在
		{
			delete xmlDocument;
			return;
		}
		if (rootElement)
		{
			for (TiXmlElement* enumElement = rootElement->FirstChildElement("Service");
				enumElement != nullptr; enumElement = enumElement->NextSiblingElement("Service"))
			{
				std::string t_Name = "";
				std::string t_Library = "";
				for (TiXmlElement* valElement = enumElement->FirstChildElement();
					valElement != nullptr; valElement = valElement->NextSiblingElement())
				{
					std::string key = valElement->Value();
					if (key == "Name")
					{
						t_Name = UTF8ToString( valElement->FirstChild()->Value());
					}
					else if (key == "Library")
					{
						t_Library = valElement->FirstChild()->Value();
					}
				}
				if (t_Name.size() && t_Library.size())
				{
					m_ServiceMap[t_Name] = t_Library;
				}
			}
		}
		delete xmlDocument;
		m_IsInterfaceLoad = true;
    }

	for (auto iter = m_ServiceMap.begin(); iter != m_ServiceMap.end(); iter++)
	{
		HINSTANCE hDll;
		#if _DEBUG
		std::string dllPath = "dll\\Debug\\" + iter->second + "d.dll";
		hDll = LoadLibrary(stringToLPCWSTR(dllPath));
		#endif
		#if NDEBUG
		std::string dllPath = "dll\\Release\\" + iter->second + ".dll";
		hDll = LoadLibrary(stringToLPCWSTR(dllPath));
		#endif
		if (hDll == NULL)
		{
			std::cout << "Load dll failed!";
			return;
		}
		using functionPtr = ServiceBase * (*)();
		functionPtr addFunction = (functionPtr)GetProcAddress(hDll, "CreateServices");
		if (addFunction == NULL)
		{
			std::cout << "cannot find target function!";
			return;
		}
		ServiceBase* service = addFunction();
		service->PublishRegister();
		m_Services[iter->second] = service;
	}
}

std::vector<ServiceBase*> ServiceInterface::GetAllService()
{
	std::vector<ServiceBase*> ret;
	m_Mutex.lock();
	for (auto iter = m_Services.begin(); iter != m_Services.end(); iter++)
	{
		ret.push_back(iter->second);
	}
	m_Mutex.unlock();
	return ret;
}

ServiceBase* ServiceInterface::GetServiceByName(std::string serviceName)
{
	ServiceBase* ret = m_Services[serviceName];
	return ret;
}

//ServiceInterface* GetServiceInterfaceSingle() {
//	static ServiceInterface* instance = ServiceInterface::GetInstance();
//	return instance;
//}
