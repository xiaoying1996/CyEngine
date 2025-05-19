#include "BattleAdjustBaseService.h"

BattleAdjustBaseService::BattleAdjustBaseService()
{
	ServiceBase::ServiceBase();
}

BattleAdjustBaseService::~BattleAdjustBaseService()
{
	ServiceBase::~ServiceBase();
}

void BattleAdjustBaseService::Init(TiXmlElement* unitElement)
{
	ServiceBase::Init(unitElement);
}

void BattleAdjustBaseService::ReadScenario()
{
	ServiceBase::ReadScenario();
}

void BattleAdjustBaseService::ReceiveEvent(EventBase* event)
{
	ServiceBase::ReadScenario();
}

void BattleAdjustBaseService::Run(double t)
{
	ServiceBase::Run(t);
}

void BattleAdjustBaseService::Destory()
{
	ServiceBase::Destory();
}

void BattleAdjustBaseService::AddAttackEvent(AttackBase* attack)
{
}
