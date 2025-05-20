#ifndef _SNIPER_
#define _SNIPER_

#include "../../ModelBase/HumanBase.h"
#include "Service/EventForwardService/EventForwardService.h"

class Sniper :public HumanBase {
public:
	Sniper();
	virtual ~Sniper();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();
	EventForwardBaseService* _EventForwardService = nullptr;
};

#endif // !_SNIPER_
