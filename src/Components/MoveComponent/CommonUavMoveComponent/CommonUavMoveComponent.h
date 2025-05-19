#ifndef _COMMONUAVMOVECOM_
#define _COMMONUAVMOVECOM_

#include "Components/ComponentBase/ComponentBase.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "Tools/ECEF_LLA/ECEF_LLA.h"
#include <Service/EventForwardBaseService/EventForwardBaseService.h>

class CommonUavMoveComponent :public ComponentBase
{
public:
	CommonUavMoveComponent();
	virtual ~CommonUavMoveComponent();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(shared_ptr<EventBase> event);
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();

	void SetPos(Model_Position pos);
	Model_Position GetPos();

private:
	MoveState _moveState;
	vector<Model_Position> _wayList_LLA;
	ECEF _nextPiont_ECEF;
	ECEF _currentPiont_ECEF;
	double _speed;
	EventForwardBaseService* _EventForwardService = nullptr;
};

#endif // !_CommonUavMoveComponent_
