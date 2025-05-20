#ifndef _COMPOSITEWINGDDRONE_
#define _COMPOSITEWINGDDRONE_

#include "../../ModelBase/UAVBase.h"

class CompositeWingDrone :public UAVBase {
public:
	CompositeWingDrone();
	virtual ~CompositeWingDrone();
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

#endif // !_COMPOSITEWINGDDRONE_
