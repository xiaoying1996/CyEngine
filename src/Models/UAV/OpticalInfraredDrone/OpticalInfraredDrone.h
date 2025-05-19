#ifndef _OPTICALINFRAREDDRONE_
#define _OPTICALINFRAREDDRONE_

#include "../../ModelBase/UAVBase.h"

class OpticalInfraredDrone :public UAVBase {
public:
	OpticalInfraredDrone();
	virtual ~OpticalInfraredDrone();
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

#endif // !_OPTICALINFRAREDDRONE_
