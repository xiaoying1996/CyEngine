#include "CommonUavMoveComponent.h"

CommonUavMoveComponent::CommonUavMoveComponent()
{
	ComponentBase::ComponentBase();
	_type = COM_MOVE;
	_speed = 25;
}

CommonUavMoveComponent::~CommonUavMoveComponent()
{
	ComponentBase::~ComponentBase();
}

void CommonUavMoveComponent::Init(TiXmlElement* unitElement)
{
	ComponentBase::Init(unitElement);
	_moveState = MOVE_STOP;
}

void CommonUavMoveComponent::ReadScenario()
{
	ComponentBase::ReadScenario();
}

void CommonUavMoveComponent::PostEvent()
{
	ComponentBase::PostEvent();
}

void CommonUavMoveComponent::ReceiveEvent(EventBase *event)
{
	ComponentBase::ReceiveEvent(event);
	switch (event->category)
	{
	case EventCategory::EVENT_MISSION_MOVE:
	{
		Mission_Move* missionMove = dynamic_cast<Mission_Move*>(event);
		_wayList_LLA.clear();
		_wayList_LLA = missionMove->moveList;
		if (_wayList_LLA.size())
		{
			_moveState = MOVE_READY;
		}
	}
	default:
		break;
	}
}

void CommonUavMoveComponent::Run(double t)
{
	ComponentBase::Run(t);
	if (_moveState == MOVE_READY)
	{
		Model_Position p_LLA = _wayList_LLA.front();
		if (_wayList_LLA.size())
		{
			_wayList_LLA.erase(_wayList_LLA.begin());
		}
		_moveState = MOVE_MOVING;
		//将当前点转化为ECEF保存
		LLA lla_curr;
		lla_curr.lon = _pos._lon; lla_curr.lat = _pos._lat; lla_curr.alt = _pos._alt;
		_currentPiont_ECEF = llaToECEF(lla_curr);
		//将下一个点转化为ECEF保存
		LLA lla_next;
		lla_next.lon = p_LLA._lon; lla_next.lat = p_LLA._lat; lla_next.alt = p_LLA._alt;
		_nextPiont_ECEF = llaToECEF(lla_next);
	}
	else if (_moveState == MOVE_MOVING)
	{
		if (distance(_currentPiont_ECEF, _nextPiont_ECEF) <= _speed / 10.0)
		{
			_currentPiont_ECEF = _nextPiont_ECEF;
			_moveState = MOVE_ATTACHPOINT;
		}
		else {
			ECEF new_point = moveTowards(_currentPiont_ECEF, _nextPiont_ECEF, _speed / 10.0);
			_currentPiont_ECEF = new_point;
			LLA llaret = ecefToLLA(_currentPiont_ECEF);
			_pos._lon = llaret.lon; _pos._lat = llaret.lat; _pos._alt = llaret.alt;
		}
	}
	else if (_moveState == MOVE_ATTACHPOINT)
	{
		if (_wayList_LLA.size())
		{
			Model_Position p_LLA = _wayList_LLA.front();
			LLA lla_next;
			lla_next.lon = p_LLA._lon; lla_next.lat = p_LLA._lat; lla_next.alt = p_LLA._alt;
			_nextPiont_ECEF = llaToECEF(lla_next);

			if (_wayList_LLA.size())
			{
				_wayList_LLA.erase(_wayList_LLA.begin());
			}
			_moveState = MOVE_MOVING;
		}
		else 
		{
			_moveState = MOVE_STOP;
		}
	}
}

void CommonUavMoveComponent::Destory()
{
	ComponentBase::Destory();
}

extern "C" _declspec(dllexport) CommonUavMoveComponent* CreateComponent()
{
	return new CommonUavMoveComponent();
}