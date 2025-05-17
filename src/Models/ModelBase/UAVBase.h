#ifndef _UAV_BASE_
#define _UAV_BASE_
#include "ModelBase.h"

class UAVBase:public ModelBase {
public:
	UAVBase();
	virtual ~UAVBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
private:
	double _flySpeed = 0;
};

#endif // !_MODEL_BASE_
