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
	ServiceBase::AddAttackEvent(attack);
	switch (attack->category)
	{
	case AttackCategory::ATTACK_PHYSICAL://��ʵ�˺�����
	{
		Attack_Physical* attack_p = dynamic_cast<Attack_Physical*>(attack);
		AttackResult result;
		result._agentID = attack_p->agentID;
		result._effectID = attack_p->effectID;
		result._category = attack_p->category;
		result._hurt = attack_p->hurt;
		//�����������¼�����Ӧ��ʵ��
		Message_Attack *msg = new Message_Attack();
		msg->receicerID = attack_p->effectID;
		msg->attackRes = result;
		PostEvent(msg);
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
