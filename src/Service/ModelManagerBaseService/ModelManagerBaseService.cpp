#include "ModelManagerBaseService.h"

ModelManagerBaseService::ModelManagerBaseService()
{
	ServiceBase::ServiceBase();
}

ModelManagerBaseService::~ModelManagerBaseService()
{
	ServiceBase::~ServiceBase();
}

void ModelManagerBaseService::Init(TiXmlElement* unitElement)
{
	ServiceBase::Init(unitElement);
}

void ModelManagerBaseService::ReadScenario()
{
	ServiceBase::ReadScenario();
}

void ModelManagerBaseService::PostEvent(EventBase* event)
{
	ServiceBase::PostEvent(event);
}

void ModelManagerBaseService::ReceiveEvent(EventBase* event)
{
	ServiceBase::ReadScenario();
}

void ModelManagerBaseService::Run(double t)
{
	ServiceBase::Run(t);
}

void ModelManagerBaseService::Destory()
{
	ServiceBase::Destory();
}

void ModelManagerBaseService::PublishRegister()
{
	ServiceBase::PublishRegister();
}

void ModelManagerBaseService::GetAllEntity(std::vector<Model_BasicInfo>& entitys)
{
	
}

void ModelManagerBaseService::UpdateEntity(Model_BasicInfo baseInfo)
{

}

void ModelManagerBaseService::GetEntityByID(Model_BasicInfo& baseInfo)
{

}