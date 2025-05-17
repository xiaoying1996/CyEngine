#ifndef _COMPONENT_BASE_
#define _COMPONENT_BASE_
#include "Public/PublicEnum.h"
#include "Public/EventStruct.h"
#include "Public/PublicStruct.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "Service/ServiceInterface/ServiceInterface.h"
#include "ComponentEnum.h"
#include "Windows.h";
#include "Tools/WriteReadShareMemory/WriteReadShareMemory.h"
#include <iostream>

class ComponentBase {
public:
	ComponentBase();
	virtual ~ComponentBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(shared_ptr<EventBase> event);
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();

	std::vector<shared_ptr<EventBase>> HandleEvent();
	void SetBasicInfo(Model_BasicInfo info, SMStruct* pData, HANDLE hMapFile);
	void SetServiceInterface(ServiceInterface *inter);
private:
	bool _isInit;
	bool _isReadScenario;
	std::vector<shared_ptr<EventBase>> _EventListToSend;
	
public:
	ComType _type;
	int _camp;
	int _id;
	string _shareMemoryID;
	SMStruct* pData;
	HANDLE hMapFile;
	ServiceInterface* _serviceInterface = nullptr;
};

#endif // !_COMPONENT_BASE_
