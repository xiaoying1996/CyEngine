#ifndef _BATTLEADJUSTSERVICE_
#define _BATTLEADJUSTSERVICE_
#include "Service/ServiceBase/ServiceBase.h"

class BattleAdjustService :public ServiceBase{
public:
	BattleAdjustService();
	virtual ~BattleAdjustService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishRegister();
	void HandleEvent();
	virtual void AddAttackEvent(AttackBase* attack);
private:
public:
	
};

#endif // !_BATTLEADJUSTSERVICE_
