#ifndef _EVENTFOEWARDSERVICE_
#define _EVENTFOEWARDSERVICE_
#include "Service/EventForwardBaseService/EventForwardBaseService.h"

struct ComCategoryStruct
{
	ComponentBase* com;
	std::vector<EventCategory> category;
};

class EventForwardService :public EventForwardBaseService {
public:
	EventForwardService();
	virtual ~EventForwardService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void AddPublishRegisterByComponent(int id,ComponentBase* com, std::vector<EventCategory> eventsRegister, std::vector<EventCategory> eventsPublish);
	virtual void HandleEventByComponent(int id, ComponentBase* com, shared_ptr<EventBase> event);
private:
	std::map<int, std::vector<ComCategoryStruct>> _ComEventRegister;
	std::map<int, std::vector<ComCategoryStruct>> _ComEventPublish;
public:
	
};

#endif // !_EVENTFOEWARDSERVICE_
