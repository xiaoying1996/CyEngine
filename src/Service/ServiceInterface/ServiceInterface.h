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
* ServiceInterface����Ϊ�������Է��������й���
* 1 ����������������
* 2 ����Է���ĵ���
* 3 �Է������ݽ������й���
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
