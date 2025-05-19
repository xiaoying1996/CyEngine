#ifndef _PEOPLE_
#define _PEOPLE_

#include "../../ModelBase/HumanBase.h"
#include "Service/EventForwardService/EventForwardService.h"

class People :public HumanBase {
public:
	People();
	virtual ~People();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();
	EventForwardBaseService* _EventForwardService = nullptr;
};

#endif // !_PEOPLE_
