#include "CommonAttackComponent.h"
#include "Public/AttackStruct.h"
#include <Tools/WriteReadShareMemory/WriteReadShareMemory.h>

CommonAttackComponent::CommonAttackComponent()
{
	ComponentBase::ComponentBase();
	_type = COM_ATTACK;
	_attackMode = ATTACKNO;
	_attackDis = 200;
	_targetLock = 0;
	_lla_targetTemp = { 0,0,0 };
	_isMoving = false;
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
	//模型和组件的事件接收还没有做公布订购，这样很消耗性能
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
		else if (mission->attackMode == 3)
		{
			_attackMode = ATTACKFOLLOW;
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
	ComponentBase::Run(t);
	Model_Position pos = GetPos();
	if (_attackMode == ATTACKALL)//全局攻击攻击离自己最近的一个
	{
		int targetID = 0;
		double targetDis = 0;
		for (int i = 0; i < entityListDetect.size(); i++)
		{
			//求距离，若距离大于可攻击距离，则抛弃
			LLA lla_self; ECEF ecef_self;
			lla_self.lon = pos._lon; lla_self.lat = pos._lat; lla_self.alt = pos._alt;
			ecef_self = llaToECEF(lla_self);
			LLA lla_target; ECEF ecef_target;
			lla_target.lon = entityListDetect[i]._pos._lon; lla_target.lat = entityListDetect[i]._pos._lat; lla_target.alt = entityListDetect[i]._pos._alt;
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
					targetID = entityListDetect[i]._id;
					targetDis = dis;
				}
				else
				{
					if (dis < targetDis)
					{
						targetID = entityListDetect[i]._id;
						targetDis = dis;
					}
				}
			}
		}
		//对目标进行打击，调用战场裁决服务
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
	else if (_attackMode == ATTACKSELECT)//选定攻击，攻击列表中离自己最近的一个,如果在已得知的情报中没有该目标就无法进行攻击
	{
		int targetID = 0;
		double targetDis = 0;
		for (int i = 0; i < _targetList.size(); i++)//遍历需要打击的目标列表进行匹配
		{
			for (int j = 0; j < entityListDetect.size(); j++)
			{
				if (_targetList[i] == entityListDetect[j]._id)
				{
					//求距离，若距离大于可攻击距离，则抛弃
					LLA lla_self; ECEF ecef_self;
					lla_self.lon = pos._lon; lla_self.lat = pos._lat; lla_self.alt = pos._alt;
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
		//对目标进行打击，调用战场裁决服务
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
	else if (_attackMode == ATTACKFOLLOW)//追踪攻击，攻击列表中离自己最近的一个,如果不在攻击范围就进入攻击范围在进行攻击
	{
		if (_targetLock == 0)//现在只做存在锁定目标的判断，后面再加如果死亡切换至下一个目标的判断
		{
			int targetID = 0;
			double targetDis = 0;
			for (int i = 0; i < _targetList.size(); i++)//遍历需要打击的目标列表进行匹配
			{
				for (int j = 0; j < entityListDetect.size(); j++)
				{
					if (_targetList[i] == entityListDetect[j]._id)
					{
						//求距离，若距离大于可攻击距离，则抛弃
						LLA lla_self; ECEF ecef_self;
						lla_self.lon = pos._lon; lla_self.lat = pos._lat; lla_self.alt = pos._alt;
						ecef_self = llaToECEF(lla_self);
						LLA lla_target; ECEF ecef_target;
						lla_target.lon = entityListDetect[j]._pos._lon; lla_target.lat = entityListDetect[j]._pos._lat; lla_target.alt = entityListDetect[j]._pos._alt;
						ecef_target = llaToECEF(lla_target);
						double dis = distance(ecef_self, ecef_target);
						if (targetID == 0)
						{
							targetID = _targetList[i];
							targetDis = dis;
							_lla_targetTemp = lla_target;
						}
						else
						{
							if (dis < targetDis)
							{
								targetID = _targetList[i];
								targetDis = dis;
								_lla_targetTemp = lla_target;
							}
						}
					}

				}
			}
			_targetLock = targetID;
			if (_targetLock != 0)
			{
				if (targetDis > _attackDis)
				{
					//推送机动事件   其实在组件里面下发机动指令逻辑是不对的，应该由模型自己决定要不要机动，所以这里选择目标并机动的指令后面要改到模型中去而不是在组件中
					Mission_Move* mission = new Mission_Move();
					mission->receicerID = _id;;
					Model_Position targetPos;
					targetPos._lon= _lla_targetTemp.lon;
					targetPos._lat = _lla_targetTemp.lat;
					targetPos._alt = _lla_targetTemp.alt;
					mission->moveList.push_back(targetPos);
					PostEvent(mission);
					_isMoving = true;
				}
			}
		}
		else
		{
			//判断是否进入距离
			LLA lla_self; ECEF ecef_self;
			lla_self.lon = pos._lon; lla_self.lat = pos._lat; lla_self.alt = pos._alt;
			ecef_self = llaToECEF(lla_self);
			LLA lla_target; ECEF ecef_target;
			lla_target.lon = _lla_targetTemp.lon; lla_target.lat = _lla_targetTemp.lat; lla_target.alt = _lla_targetTemp.alt;
			ecef_target = llaToECEF(lla_target);
			double dis = distance(ecef_self, ecef_target);
			if (dis <= _attackDis)
			{
				if (battleAdjustService)
				{
					Attack_Physical* attack = new Attack_Physical();
					attack->agentID = _id;
					attack->effectID = _targetLock;
					attack->category = AttackCategory::ATTACK_PHYSICAL;
					attack->hurt = 30;
					battleAdjustService->AddAttackEvent(attack);
					delete attack;
				}
			}
		}
	}
}

void CommonAttackComponent::Destory()
{
	ComponentBase::Destory();
}

Model_Position CommonAttackComponent::GetPos()
{
	return GetSMData(hMapFile, pData).basicInfo._pos;
}

extern "C" _declspec(dllexport) CommonAttackComponent* CreateComponent()
{
	return new CommonAttackComponent();
}