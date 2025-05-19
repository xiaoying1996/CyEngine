#ifndef _BATTLEADJUSTSERVICE_
#define _BATTLEADJUSTSERVICE_
#include "Service/BattleAdjustBaseService/BattleAdjustBaseService.h"
#include "Service/EventForwardBaseService/EventForwardBaseService.h"

class BattleAdjustService :public BattleAdjustBaseService{
public:
	BattleAdjustService();
	virtual ~BattleAdjustService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void AddAttackEvent(AttackBase* attack);
private:
	EventForwardBaseService* _EventForwardService = nullptr;

public:
	
};

#endif // !_BATTLEADJUSTSERVICE_
