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
* ServiceInterface对象为单例，对服务对象进行管理
* 1 创建并保存服务对象
* 2 负责对服务的调用
* 3 对服务数据进出进行管理
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
