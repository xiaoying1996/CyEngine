#ifndef _SERVICE_BASE_
#define _SERVICE_BASE_
#include "../../Public/PublicEnum.h"
#include "Public/EventStruct.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "ServiceEnum.h"

class ServiceBase {
public:
	ServiceBase();
	virtual ~ServiceBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishEvent();
	virtual void RegisterEvent();
	virtual void PublishModel();
	virtual void RegisterModel();
	void HandleEvent();
private:
	
public:
	ServiceType _type;
};

#endif // !_MODEL_BASE_
