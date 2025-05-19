#ifndef _VEHICLE_BASE_
#define _VEHICLE_BASE_
#include "ModelBase.h"

class VehicleBase:public ModelBase {
public:
	VehicleBase();
	virtual ~VehicleBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();
private:
	double _moveSpeed = 0;
};

#endif // !_MODEL_BASE_
