#ifndef _COMMONATTACKCOM_
#define _COMMONATTACKCOM_

#include "Components/ComponentBase/ComponentBase.h"
#include "Service/ServiceInterface/ServiceInterface.h"
#include "Service/BattleAdjustService/BattleAdjustService.h"

class CommonAttackComponent :public ComponentBase
{
public:
	CommonAttackComponent();
	virtual ~CommonAttackComponent();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();

private:
	AttackMode _attackMode;
	double _attackDis;
	vector<int> _targetList;
	vector<Model_BasicInfo> entityListDetect;//本组件已知的情报信息
	ServiceBase* battleAdjustService = nullptr;
};

#endif // !_CommonUavMoveComponent_
