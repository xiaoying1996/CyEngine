#ifndef _MISSILEDRONE_
#define _MISSILEDRONE_

#include "../../ModelBase/UAVBase.h"

class MissileDrone :public UAVBase {
public:
	MissileDrone();
	virtual ~MissileDrone();
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

#endif // !_MISSILEDRONE_
