#ifndef _ASSULTMAN_
#define _ASSULTMAN_

#include "../../ModelBase/HumanBase.h"
#include "Service/EventForwardService/EventForwardService.h"

class AssultMan :public HumanBase {
public:
	AssultMan();
	virtual ~AssultMan();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();
	EventForwardBaseService* _EventForwardService = nullptr;
};

#endif // !_ASSULTMAN_
