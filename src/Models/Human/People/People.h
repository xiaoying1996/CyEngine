#ifndef _PEOPLE_
#define _PEOPLE_

#include "../../ModelBase/HumanBase.h"

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
};

#endif // !_PEOPLE_
