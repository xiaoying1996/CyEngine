#include "ModelManagerService.h"

ModelManagerService::ModelManagerService()
{
	ServiceBase::ServiceBase();
}

ModelManagerService::~ModelManagerService()
{
	ServiceBase::~ServiceBase();
}

void ModelManagerService::Init(TiXmlElement* unitElement)
{
	ServiceBase::Init(unitElement);
}

void ModelManagerService::ReadScenario()
{
	ServiceBase::ReadScenario();
}

void ModelManagerService::PostEvent()
{
	ServiceBase::PostEvent();
}

void ModelManagerService::HandleEvent()
{
	ServiceBase::HandleEvent();
}

void ModelManagerService::ReceiveEvent(EventBase* event)
{
	ServiceBase::ReadScenario();
}

void ModelManagerService::Run(double t)
{
	ServiceBase::Run(t);
}

void ModelManagerService::Destory()
{
	ServiceBase::Destory();
}

void ModelManagerService::PublishRegister()
{
	ServiceBase::PublishRegister();
	std::vector<ModelType> modelsForRegister = { ModelType ::M_PEOPLE,ModelType ::M_OPTICALATTACKUAV};
	AddModelRegister(modelsForRegister);
}

extern "C" _declspec(dllexport) ModelManagerService* CreateServices()
{
	return new ModelManagerService();
}