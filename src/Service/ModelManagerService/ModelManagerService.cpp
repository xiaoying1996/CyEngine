#include "ModelManagerService.h"

ModelManagerService::ModelManagerService()
{
}

ModelManagerService::~ModelManagerService()
{
}

void ModelManagerService::Init()
{

}

void ModelManagerService::ReadScenario()
{
}

void ModelManagerService::PostEvent()
{
}

void ModelManagerService::HandleEvent()
{

}

void ModelManagerService::ReceiveEvent(EventBase* event)
{
}

void ModelManagerService::Run(double t)
{

}

void ModelManagerService::Destory()
{
}

void ModelManagerService::PublishEvent()
{

}
void ModelManagerService::RegisterEvent()
{

}
void ModelManagerService::PublishModel()
{

}
void ModelManagerService::RegisterModel()
{

}

extern "C" _declspec(dllexport) ModelManagerService* CreateService()
{
	return new ModelManagerService();
}