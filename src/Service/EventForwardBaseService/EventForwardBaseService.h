#ifndef _EVENTFORWARDBASESERVICE_
#define _EVENTFORWARDBASESERVICE_
#include "Service/ServiceBase/ServiceBase.h"
#include "Components/ComponentBase/ComponentBase.h"

class EventForwardBaseService :public ServiceBase{
public:
	EventForwardBaseService();
	virtual ~EventForwardBaseService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void AddPublishRegisterByComponent(int id, ComponentBase* com, std::vector<EventCategory> eventsRegister, std::vector<EventCategory> eventsPublish);
	virtual void HandleEventByComponent(int id, ComponentBase* com,shared_ptr<EventBase> event);
protected:

public:
	
};

#endif // !_EVENTFORWARDBASESERVICE_
