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
}
void ModelManagerService::UpdateEntity(Model_BasicInfo baseInfo)
{
	ModelManagerBaseService::UpdateEntity(baseInfo);
}

void ModelManagerService::GetEntityByID(Model_BasicInfo& baseInfo)
{

}

extern "C" _declspec(dllexport) ModelManagerService* CreateServices()
{
	return new ModelManagerService();
}