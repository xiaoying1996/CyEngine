#include "OpticalInfraredDrone.h"

OpticalInfraredDrone::OpticalInfraredDrone()
{
}

OpticalInfraredDrone::~OpticalInfraredDrone()
{
	UAVBase::~UAVBase();
}

void OpticalInfraredDrone::Init(TiXmlElement* unitElement)
{
	UAVBase::Init(unitElement);
	SetType(M_OPTICALINFRAREDDRONE);
}

void OpticalInfraredDrone::ReadScenario()
{
	UAVBase::ReadScenario();
}

void OpticalInfraredDrone::PostEvent()
{
	UAVBase::PostEvent();
}

void OpticalInfraredDrone::ReceiveEvent(shared_ptr<EventBase> event)
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

void OpticalInfraredDrone::Run(double t)
{
	UAVBase::Run(t);
}

void OpticalInfraredDrone::Destory()
{
	UAVBase::Destory();
}

extern "C" _declspec(dllexport) OpticalInfraredDrone* CreateModel()
{
	return new OpticalInfraredDrone();
}