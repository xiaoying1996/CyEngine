#ifndef _EVENT_STRUCT_
#define _EVENT_STRUCT_

#include <iostream>
#include <vector>
#include "PublicStruct.h"
#include "AttackStruct.h"

enum EventCategory {
	EVENT_UNKNOW = 0,
	EVENT_MISSION_MOVE = 1,
	EVENT_MISSION_ATTACK,
	EVENT_MESSAGE_MODELSINFOALL=500,
	EVENT_MESSAGE_MODELSDETECT,
	EVENT_MESSAGE_ATTACK,
};

struct EventBase {
	int receicerID;
	EventCategory category;
	virtual void GetData() = 0;
	EventBase()
	{
		receicerID = 0;
		category = EVENT_UNKNOW;
	}
};

struct Mission_Move : public EventBase
{
	vector<Model_Position> moveList;
	virtual void GetData() 
	{

	}
	Mission_Move()
	{
		category = EventCategory::EVENT_MISSION_MOVE;
	}
};

struct Mission_Attack : public EventBase
{
	int attackMode;//0停止攻击1全局攻击2选取目标攻击
	vector<int> targets;
	virtual void GetData()
	{

	}
	Mission_Attack()
	{
		category = EventCategory::EVENT_MISSION_ATTACK;
		attackMode = 0;
	}
};

struct Message_ModelsInfoAll : public EventBase
{
	vector<Model_BasicInfo> modelsInfoList;
	virtual void GetData()
	{

	}
	Message_ModelsInfoAll()
	{
		category = EventCategory::EVENT_MESSAGE_MODELSINFOALL;
	}
};

struct Message_ModelsDetect : public EventBase
{
	vector<Model_BasicInfo> modelsInfoList;
	virtual void GetData()
	{

	}
	Message_ModelsDetect()
	{
		category = EventCategory::EVENT_MESSAGE_MODELSDETECT;
	}
};

struct Message_Attack : public EventBase
{
	AttackResult attackRes;
	virtual void GetData()
	{

	}
	Message_Attack()
	{
		category = EventCategory::EVENT_MESSAGE_ATTACK;
	}
};
#endif // !_PUBLIC_STRUCT_

