#ifndef _COMMONUAVMOVECOM_
#define _COMMONUAVMOVECOM_

#include "Components/ComponentBase/ComponentBase.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "Tools/ECEF_LLA/ECEF_LLA.h"

class CommonUavMoveComponent :public ComponentBase
{
public:
	CommonUavMoveComponent();
	virtual ~CommonUavMoveComponent();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();

private:
	MoveState _moveState;
	vector<Model_Position> _wayList_LLA;
	ECEF _nextPiont_ECEF;
	ECEF _currentPiont_ECEF;
	double _speed;
};

#endif // !_CommonUavMoveComponent_
