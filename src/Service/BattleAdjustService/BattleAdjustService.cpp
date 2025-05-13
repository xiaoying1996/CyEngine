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
	std::vector<ModelType> modelsForRegister;
	AddModelRegister(modelsForRegister);
	std::vector<EventCategory> events = { EVENT_MESSAGE_ATTACK };
	AddEventPublic(events);
}

void BattleAdjustService::AddAttackEvent(AttackBase* attack)
{
	switch (attack->category)
	{
	case ATTACK_PHYSICAL:
	{
		Attack_Physical* a = dynamic_cast<Attack_Physical*>(attack);
		Message_Attack msg;
		msg.receicerID = attack->effectID;
		msg.attackRes._agentID = attack->agentID;
		msg.attackRes._effectID = attack->effectID;
		msg.attackRes._hurt = a->hurt;
		_EventListToSend.push_back(msg);
		break;
	}
	default:
		break;
	}
}

extern "C" _declspec(dllexport) BattleAdjustService* CreateServices()
{
	return new BattleAdjustService();
}
