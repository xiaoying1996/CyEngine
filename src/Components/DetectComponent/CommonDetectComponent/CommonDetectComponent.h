#ifndef _COMMONDETECTCOM_
#define _COMMONDETECTCOM_

#include "Components/ComponentBase/ComponentBase.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "Service/ServiceInterface/ServiceInterface.h"
#include "Service/ModelManagerBaseService/ModelManagerBaseService.h"
#include "Service/EventForwardBaseService/EventForwardBaseService.h"

class CommonDetectComponent :public ComponentBase
{
public:
	CommonDetectComponent();
	virtual ~CommonDetectComponent();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(shared_ptr<EventBase> event);
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();

	Model_Position GetPos();
private:
	double _detectDis;
	ModelManagerBaseService* _modelManagerService = nullptr;
	EventForwardBaseService* _EventForwardService = nullptr;
	std::vector<Model_BasicInfo> _TargetList;
};

#endif // !_CommonUavMoveComponent_
