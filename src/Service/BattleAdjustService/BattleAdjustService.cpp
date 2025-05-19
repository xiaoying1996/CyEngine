#include "BattleAdjustService.h"

BattleAdjustService::BattleAdjustService()
{
	BattleAdjustBaseService::BattleAdjustBaseService();
}

BattleAdjustService::~BattleAdjustService()
{
	BattleAdjustBaseService::~BattleAdjustBaseService();
}

void BattleAdjustService::Init(TiXmlElement* unitElement)
{
	BattleAdjustBaseService::Init(unitElement);
}

void BattleAdjustService::ReadScenario()
{
	BattleAdjustBaseService::ReadScenario();
}

void BattleAdjustService::ReceiveEvent(EventBase* event)
{
	BattleAdjustBaseService::ReadScenario();
}

void BattleAdjustService::Run(double t)
{
	BattleAdjustBaseService::Run(t);
}

void BattleAdjustService::Destory()
{
	BattleAdjustBaseService::Destory();
}

void BattleAdjustService::AddAttackEvent(AttackBase* attack)
{
	if(_EventForwardService == nullptr)
		_EventForwardService = dynamic_cast<EventForwardBaseService*>(ServiceInterface::GetInstance()->GetServiceByName("EventForwardService"));
	BattleAdjustBaseService::AddAttackEvent(attack);
	switch (attack->category)
	{
	case ATTACK_PHYSICAL:
	{
		Attack_Physical* a = dynamic_cast<Attack_Physical*>(attack);
		auto message = std::make_shared<Message_Attacked>();
		message->receicerID = a->effectID;
		message->attackRes._agentID = a->agentID;
		message->attackRes._effectID = a->effectID;
		message->attackRes._category = ATTACK_PHYSICAL;
		message->attackRes._hurt = a->hurt;
		if (_EventForwardService)
		{
			_EventForwardService->HandleEventByService(message);
		}
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
