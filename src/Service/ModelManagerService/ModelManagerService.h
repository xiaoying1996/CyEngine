#ifndef _MODELMANAGERSERVICE_
#define _MODELMANAGERSERVICE_
#include "Service/ServiceBase/ServiceBase.h"

class ModelManagerService :public ServiceBase{
public:
	ModelManagerService();
	virtual ~ModelManagerService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishRegister();
	void HandleEvent();
	void GetAllEntity(std::vector<Model_BasicInfo>& entitys);
private:
	
public:
	
};

#endif // !_MODELMANAGERSERVICE_
