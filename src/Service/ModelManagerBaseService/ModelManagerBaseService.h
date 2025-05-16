#ifndef _MODELMANAGERBASESERVICE_
#define _MODELMANAGERBASESERVICE_
#include "Service/ServiceBase/ServiceBase.h"

class ModelManagerBaseService :public ServiceBase{
public:
	ModelManagerBaseService();
	virtual ~ModelManagerBaseService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishRegister();
	virtual void GetAllEntity(std::vector<Model_BasicInfo>& entitys);
	virtual void UpdateEntity(Model_BasicInfo baseInfo);
	virtual void GetEntityByID(Model_BasicInfo& baseInfo);
private:
	std::vector<Model_BasicInfo> _emyityList;
public:
	
};

#endif // !_MODELMANAGERBASESERVICE_
