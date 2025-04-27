#ifndef _COMPONENT_BASE_
#define _COMPONENT_BASE_
#include "Public/PublicEnum.h"
#include "Public/EventStruct.h"
#include "Public/PublicStruct.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "Service/ServiceInterface/ServiceInterface.h"
#include "ComponentEnum.h"
#include <iostream>

class ComponentBase {
public:
	ComponentBase();
	virtual ~ComponentBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase *event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();

	void HandleEvent();
	void HandleComponentState();
	void SetBasicInfo(Model_BasicInfo info);
	Model_Position GetPos();
	ServiceBase* GetService(std::string serviceName);
	void SetServiceInterface(ServiceInterface *inter);
private:
	bool _isInit;
	bool _isReadScenario;
	std::vector<EventBase*> _EventListToSend;
	
public:
	ComType _type;
	Model_Position _pos;
	int _camp;
	int _id;
	ServiceInterface* _serviceInterface = nullptr;
};

#endif // !_COMPONENT_BASE_
