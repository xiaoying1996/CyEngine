#ifndef _ATTACK_STRUCT_
#define _ATTACK_STRUCT_

#include <iostream>
#include <vector>

enum AttackCategory {
	ATTACK_UNKNOW = 0,
	ATTACK_PHYSICAL = 1,
};

enum AttackMode
{
	ATTACKNO = 0,//不攻击
	ATTACKALL,//全局攻击，攻击能攻击的所有目标,不移动
	ATTACKSELECT,//指定攻击，攻击指定的目标，不移动
};

struct AttackBase {
	int agentID;
	int effectID;
	AttackCategory category;
	virtual void GetData() = 0;
	AttackBase()
	{
		agentID = 0;
		effectID = 0;
		category = ATTACK_UNKNOW;
	}
};

struct Attack_Physical : public AttackBase
{
	double hurt;
	virtual void GetData() 
	{

	}
	Attack_Physical()
	{
		category = AttackCategory::ATTACK_PHYSICAL;
	}
};

struct AttackResult 
{
	int _agentID;
	int _effectID;
	AttackCategory _category;
	double _hurt;
};
#endif // !_ATTACK_STRUCT_

