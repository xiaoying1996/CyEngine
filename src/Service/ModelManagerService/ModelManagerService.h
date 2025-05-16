#ifndef _MODELMANAGERSERVICE_
#define _MODELMANAGERSERVICE_
#include "Service/ModelManagerBaseService/ModelManagerBaseService.h"

class ModelManagerService :public ModelManagerBaseService{
public:
	ModelManagerService();
	virtual ~ModelManagerService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishRegister();
	virtual void GetAllEntity(std::vector<Model_BasicInfo>& entitys);
	virtual void UpdateEntity(Model_BasicInfo baseInfo);
	virtual void GetEntityByID(Model_BasicInfo &baseInfo);
private:
	
public:
	
};

#endif // !_MODELMANAGERSERVICE_
