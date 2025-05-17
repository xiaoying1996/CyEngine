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
	UAVBase::Init(unitElement);
	SetType(M_OPTICALATTACKUAV);
}

void OpticalAttackUav::ReadScenario()
{
	UAVBase::ReadScenario();
}

void OpticalAttackUav::PostEvent()
{
	UAVBase::PostEvent();
}

void OpticalAttackUav::ReceiveEvent(shared_ptr<EventBase> event)
{
	UAVBase::ReceiveEvent(event);
	switch (event->category)
	{
	case EventCategory::EVENT_MISSION_MOVE:
	{
		shared_ptr<Mission_Move> missionMove = std::dynamic_pointer_cast<Mission_Move>(event);
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