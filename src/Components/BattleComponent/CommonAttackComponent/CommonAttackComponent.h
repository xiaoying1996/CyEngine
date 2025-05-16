#ifndef _COMMONATTACKCOM_
#define _COMMONATTACKCOM_

#include "Components/ComponentBase/ComponentBase.h"
#include "Service/ServiceInterface/ServiceInterface.h"
#include "Service/BattleAdjustService/BattleAdjustService.h"
#include "Tools/ECEF_LLA/ECEF_LLA.h"

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

	Model_Position GetPos();

private:
	AttackMode _attackMode;
	double _attackDis;
	bool _isMoving;
	vector<int> _targetList;
	int _targetLock;
	LLA _lla_targetTemp;
	vector<Model_BasicInfo> entityListDetect;//本组件已知的情报信息
	ServiceBase* battleAdjustService = nullptr;
};

#endif // !_CommonUavMoveComponent_
