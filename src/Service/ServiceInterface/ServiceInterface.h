#ifndef _SERVICE_INTERFACE
#define _SERVICE_INTERFACE

#ifdef CORE_DLL_EXPORTS
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif // CORE_DLL_EXPORTS


#include <iostream>
#include <mutex>
#include <vector>
#include <map>
#include "Service/ServiceBase/ServiceBase.h"

/*
* ServiceInterface����Ϊ�������Է��������й���
* 1 ����������������
* 2 ����Է���ĵ���
* 3 �Է������ݽ������й���
*/

class CORE_API ServiceInterface
{
public:
	
	static ServiceInterface* GetInstance();
	ServiceInterface(const ServiceInterface&) = delete;
	ServiceInterface& operator=(const ServiceInterface& manager) = delete;
	void LoadInterface();
	std::vector<ServiceBase*> GetAllService();
	ServiceBase* GetServiceByName(std::string serviceName);

private:
	ServiceInterface();
	~ServiceInterface();
	static ServiceInterface* m_ServiceInterface;
	static std::mutex m_Mutex;
	bool m_IsInterfaceLoad;
	std::map<std::string,ServiceBase*> m_Services;
	std::map<std::string, std::string>  m_ServiceMap;

	
};

//SINGLETON_API ServiceInterface* GetServiceInterfaceSingle();

#endif // !_MODEL_MANAGER
