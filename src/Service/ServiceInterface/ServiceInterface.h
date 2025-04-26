#ifndef _SERVICE_INTERFACE
#define _SERVICE_INTERFACE

#ifdef _WIN32
	#ifdef SINGLETON_EXPORTS 
		#define SINGLETON_API
__declspec(dllexport)
	#else
		#define SINGLETON_API
__declspec(dllimport)
	#endif
#else
	#define SINGLETON_API
__attribute__((visibility("default")))
#endif // 


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

class ServiceInterface
{
public:
	~ServiceInterface();
	static ServiceInterface* GetInstance();
	static void deleteInstance();
private:
	ServiceInterface();
	ServiceInterface(const ServiceInterface& manager);
	const ServiceInterface& operator=(const ServiceInterface& manager);

private:
	static ServiceInterface* m_ServiceInterface;
	static std::mutex m_Mutex;
	bool m_IsInterfaceLoad;
	std::map<std::string,ServiceBase*> m_Services;
	std::map<std::string, std::string>  m_ServiceMap;

public:
	void LoadInterface();
};

#endif // !_MODEL_MANAGER
