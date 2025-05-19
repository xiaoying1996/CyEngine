#ifndef _JEEP_
#define _JEEP_

#include "../../ModelBase/VehicleBase.h"

class Jeep :public VehicleBase {
public:
	Jeep();
	virtual ~Jeep();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();

private:
	//当前存在的任务
	vector<shared_ptr<EventBase>> m_missions;
};

#endif // !_JEEP_
