#ifndef _HUMAN_BASE_
#define _HUMAN_BASE_
#include "ModelBase.h"

class HumanBase:public ModelBase {
public:
	HumanBase();
	virtual ~HumanBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
private:
	double _runSpeed = 0;
};

#endif // !_MODEL_BASE_
