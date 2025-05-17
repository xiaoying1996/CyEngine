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

void ModelManagerService::GetEntityByID(Model_BasicInfo& baseInfo)
{

}

extern "C" _declspec(dllexport) ModelManagerService* CreateServices()
{
	return new ModelManagerService();
}