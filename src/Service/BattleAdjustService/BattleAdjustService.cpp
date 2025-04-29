#include "BattleAdjustService.h"

BattleAdjustService::BattleAdjustService()
{
	ServiceBase::ServiceBase();
}

BattleAdjustService::~BattleAdjustService()
{
	ServiceBase::~ServiceBase();
}

void BattleAdjustService::Init(TiXmlElement* unitElement)
{
	ServiceBase::Init(unitElement);
}

void BattleAdjustService::ReadScenario()
{
	ServiceBase::ReadScenario();
}

void BattleAdjustService::PostEvent()
{
	ServiceBase::PostEvent();
}

void BattleAdjustService::HandleEvent()
{
	ServiceBase::HandleEvent();
}

void BattleAdjustService::ReceiveEvent(EventBase* event)
{
	ServiceBase::ReadScenario();
}

void BattleAdjustService::Run(double t)
{
	ServiceBase::Run(t);
}

void BattleAdjustService::Destory()
{
	ServiceBase::Destory();
}

void BattleAdjustService::PublishRegister()
{
	ServiceBase::PublishRegister();
	std::vector<ModelType> modelsForRegister = { ModelType ::M_PEOPLE,ModelType ::M_OPTICALATTACKUAV};
	AddModelRegister(modelsForRegister);
	std::vector<EventCategory> events;
	AddEventRegister(events);
}

void BattleAdjustService::GetAllEntity(std::vector<Model_BasicInfo>& entitys)
{
	ServiceBase::GetAllEntity(entitys);
}

extern "C" _declspec(dllexport) BattleAdjustService* CreateServices()
{
	return new BattleAdjustService();
}
