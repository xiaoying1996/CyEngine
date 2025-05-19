#ifndef _BATTLEADJUSTBASESERVICE_
#define _BATTLEADJUSTBASESERVICE_
#include "Service/ServiceBase/ServiceBase.h"

class BattleAdjustBaseService :public ServiceBase{
public:
	BattleAdjustBaseService();
	virtual ~BattleAdjustBaseService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void AddAttackEvent(AttackBase* attack);
private:
public:
	
};

#endif // !_BATTLEADJUSTBASESERVICE_
