#include "OpticalAttackUav.h"

OpticalAttackUav::OpticalAttackUav()
{
}

OpticalAttackUav::~OpticalAttackUav()
{
	UAVBase::~UAVBase();
}

void OpticalAttackUav::Init(TiXmlElement* unitElement)
{
	_type = M_OPTICALATTACKUAV;
	UAVBase::Init(unitElement);
}

void OpticalAttackUav::ReadScenario()
{
	UAVBase::ReadScenario();
}

void OpticalAttackUav::PostEvent()
{
	UAVBase::PostEvent();
}

void OpticalAttackUav::ReceiveEvent(EventBase *event)
{
	UAVBase::ReceiveEvent(event);
	switch (event->category)
	{
	case EventCategory::EVENT_MISSION_MOVE:
	{
		Mission_Move* missionMove = dynamic_cast<Mission_Move*>(event);
		m_missions.push_back(missionMove);
	}
	default:
		break;
	}
}

void OpticalAttackUav::Run(double t)
{
	UAVBase::Run(t);
}

void OpticalAttackUav::Destory()
{
	UAVBase::Destory();
}

extern "C" _declspec(dllexport) OpticalAttackUav* CreateModel()
{
	return new OpticalAttackUav();
}