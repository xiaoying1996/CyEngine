#ifndef _CM33_
#define _CM33_

#include "../../ModelBase/VehicleBase.h"

class CM33 :public VehicleBase {
public:
	CM33();
	virtual ~CM33();
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
