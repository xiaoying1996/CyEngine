#include "ModelManagerService.h"

ModelManagerService::ModelManagerService()
{
	ModelManagerBaseService::ModelManagerBaseService();
}

ModelManagerService::~ModelManagerService()
{
	ModelManagerBaseService::~ModelManagerBaseService();
}

void ModelManagerService::Init(TiXmlElement* unitElement)
{
	ModelManagerBaseService::Init(unitElement);
}

void ModelManagerService::ReadScenario()
{
	ModelManagerBaseService::ReadScenario();
}

void ModelManagerService::PostEvent(EventBase* event)
{
	ModelManagerBaseService::PostEvent(event);
}

void ModelManagerService::ReceiveEvent(EventBase* event)
{
	ModelManagerBaseService::ReadScenario();
}

void ModelManagerService::Run(double t)
{
	ModelManagerBaseService::Run(t);
}

void ModelManagerService::Destory()
{
	ModelManagerBaseService::Destory();
}

void ModelManagerService::PublishRegister()
{
	ModelManagerBaseService::PublishRegister();
}

void ModelManagerService::GetAllEntity(std::vector<Model_BasicInfo>& entitys)
{
	ModelManagerBaseService::GetAllEntity(entitys);
	for (auto iter = _emyityMap.begin(); iter != _emyityMap.end(); iter++)
	{
		entitys.push_back(iter->second);
	}
}
void ModelManagerService::UpdateEntity(Model_BasicInfo baseInfo)
{
	ModelManagerBaseService::UpdateEntity(baseInfo);
	_emyityMap[baseInfo._id] = baseInfo;
}

void ModelManagerService::GetEntityByID(int id,Model_BasicInfo& baseInfo)
{
	ModelManagerBaseService::GetEntityByID(id,baseInfo);
	if (_emyityMap.find(id) != _emyityMap.end())
	{
		baseInfo = _emyityMap[id];
	}
	else
	{
		baseInfo._id = 0;
	}
}

void ModelManagerService::UpdateJob(int id, JobType type)
{
	ModelManagerBaseService::UpdateJob(id,type);
	_jobMap[id] = type;
}

void ModelManagerService::GetJobByID(int id, JobType& type)
{
	ModelManagerBaseService::GetJobByID(id,type);
	if (_jobMap.find(id) != _jobMap.end())
	{
		type = _jobMap[id];
	}
	else
	{
		type = JobType::JOB_UNKNOW;
	}
}

void ModelManagerService::UpdateModelFunction(int id, vector<ModelFunction> f)
{
	ModelManagerBaseService::UpdateModelFunction(id, f);
	_jobModelFuns[id] = f;
}
void ModelManagerService::GetModelFunctionByID(int id, vector<ModelFunction> &f)
{
	ModelManagerBaseService::GetModelFunctionByID(id,f);
	if (_jobModelFuns.find(id) != _jobModelFuns.end())
	{
		f = _jobModelFuns[id];
	}
}

extern "C" _declspec(dllexport) ModelManagerService* CreateServices()
{
	return new ModelManagerService();
}