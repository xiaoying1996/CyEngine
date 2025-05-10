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
	ATTACKNO = 0,//������
	ATTACKALL,//ȫ�ֹ����������ܹ���������Ŀ��,���ƶ�
	ATTACKSELECT,//ָ������������ָ����Ŀ�꣬���ƶ�
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

