#ifndef _COMMONDETECTCOM_
#define _COMMONDETECTCOM_

#include "Components/ComponentBase/ComponentBase.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "Service/ServiceInterface/ServiceInterface.h"
#include "Service/ModelManagerService/ModelManagerService.h"

class CommonDetectComponent :public ComponentBase
{
public:
	CommonDetectComponent();
	virtual ~CommonDetectComponent();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();

private:
	double _detectDis;
	ModelManagerService* _modelManagerService = nullptr;
};

#endif // !_CommonUavMoveComponent_
