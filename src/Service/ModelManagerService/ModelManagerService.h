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
	virtual void GetEntityByID(int id,Model_BasicInfo &baseInfo);
	virtual void UpdateJob(int id, JobType type);
	virtual void GetJobByID(int id, JobType& type);
	virtual void UpdateModelFunction(int id, vector<ModelFunction> f);
	virtual void GetModelFunctionByID(int id, vector<ModelFunction> &f);
private:
	std::map<int, Model_BasicInfo> _emyityMap;
	std::map<int, JobType> _jobMap;
	std::map<int, vector<ModelFunction>> _jobModelFuns;

public:
	
};

#endif // !_MODELMANAGERSERVICE_
