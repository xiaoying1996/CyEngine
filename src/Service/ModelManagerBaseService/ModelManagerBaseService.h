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
	virtual void GetEntityByID(int id,Model_BasicInfo& baseInfo);
	virtual void UpdateJob(int id, JobType type);
	virtual void GetJobByID(int id,JobType & type);
	virtual void UpdateModelFunction(int id, vector<ModelFunction> f);
	virtual void GetModelFunctionByID(int id, vector<ModelFunction> &f);

protected:

public:
	
};

#endif // !_MODELMANAGERBASESERVICE_
