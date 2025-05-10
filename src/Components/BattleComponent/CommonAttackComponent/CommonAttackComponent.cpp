#include "CommonAttackComponent.h"
#include "Tools/ECEF_LLA/ECEF_LLA.h"
#include "Public/AttackStruct.h"

CommonAttackComponent::CommonAttackComponent()
{
	ComponentBase::ComponentBase();
	_type = COM_ATTACK;
	_attackMode = ATTACKNO;
	_attackDis = 200;
}

CommonAttackComponent::~CommonAttackComponent()
{
	ComponentBase::~ComponentBase();
}

void CommonAttackComponent::Init(TiXmlElement* unitElement)
{
	ComponentBase::Init(unitElement);
	if (_serviceInterface)
	{
		battleAdjustService  =_serviceInterface->GetServiceByName("BattleAdjustService");
	}
}

void CommonAttackComponent::ReadScenario()
{
	ComponentBase::ReadScenario();
}

void CommonAttackComponent::PostEvent(EventBase* event)
{
	ComponentBase::PostEvent(event);
}

void CommonAttackComponent::ReceiveEvent(EventBase *event)
{
	//ģ�ͺ�������¼����ջ�û����������������������������
	ComponentBase::ReceiveEvent(event);
	if (event->category == EVENT_MISSION_ATTACK)
	{
		Mission_Attack* mission = dynamic_cast<Mission_Attack*>(event);
		if (mission->attackMode == 0)
		{
			_attackMode = ATTACKNO;
		}
		else if (mission->attackMode == 1)
		{
			_attackMode = ATTACKALL;
		}
		else if (mission->attackMode == 2)
		{
			_attackMode = ATTACKSELECT;
			_targetList.clear();
			_targetList = mission->targets;
		}
	}
	else if (event->category == EVENT_MESSAGE_MODELSDETECT)
	{
		Message_ModelsDetect* message = dynamic_cast<Message_ModelsDetect*>(event);
		entityListDetect.clear();
		entityListDetect = message->modelsInfoList;
	}
}

void CommonAttackComponent::Run(double t)
{

	
	//battleAdjustService = dynamic_cast<BattleAdjustService*> (GetService(""));
	ComponentBase::Run(t);
	if (_attackMode == ATTACKALL)//ȫ�ֹ����������Լ������һ��
	{

	}
	else if ((_attackMode == ATTACKSELECT))//ѡ�������������б������Լ������һ��,������ѵ�֪���鱨��û�и�Ŀ����޷����й���
	{
		int targetID = 0;
		double targetDis = 0;
		for (int i = 0; i < _targetList.size(); i++)//������Ҫ�����Ŀ���б����ƥ��
		{
			for (int j = 0; j < entityListDetect.size(); j++)
			{
				if (_targetList[i] == entityListDetect[j]._id)
				{
					//����룬��������ڿɹ������룬������
					LLA lla_self; ECEF ecef_self;
					lla_self.lon = _pos._lon; lla_self.lat = _pos._lat; lla_self.alt = _pos._alt;
					ecef_self = llaToECEF(lla_self);
					LLA lla_target; ECEF ecef_target;
					lla_target.lon = entityListDetect[j]._pos._lon; lla_target.lat = entityListDetect[j]._pos._lat; lla_target.alt = entityListDetect[j]._pos._alt;
					ecef_target = llaToECEF(lla_target);
					double dis = distance(ecef_self, ecef_target);
					if (dis > _attackDis)
					{
						break;
					}
					else
					{
						if (targetID == 0)
						{
							targetID = _targetList[i];
							targetDis = dis;
						}
						else
						{
							if(dis < targetDis)
							{
								targetID = _targetList[i];
								targetDis = dis;
							}
						}
					}
				}
				
			}
		}
		//��Ŀ����д��������ս���þ�����
		if (battleAdjustService)
		{
			Attack_Physical* attack = new Attack_Physical();
			attack->agentID = _id;
			attack->effectID = targetID;
			attack->category = AttackCategory::ATTACK_PHYSICAL;
			attack->hurt = 30;
			battleAdjustService->AddAttackEvent(attack);
			delete attack;
		}
	}
}

void CommonAttackComponent::Destory()
{
	ComponentBase::Destory();
}

extern "C" _declspec(dllexport) CommonAttackComponent* CreateComponent()
{
	return new CommonAttackComponent();
}