#include "GrenadeDrone.h"

GrenadeDrone::GrenadeDrone()
{
}

GrenadeDrone::~GrenadeDrone()
{
	UAVBase::~UAVBase();
}

void GrenadeDrone::Init(TiXmlElement* unitElement)
{
	UAVBase::Init(unitElement);
	SetType(M_GRENADEDRONE);
}

void GrenadeDrone::ReadScenario()
{
	UAVBase::ReadScenario();
}

void GrenadeDrone::PostEvent()
{
	UAVBase::PostEvent();
}

void GrenadeDrone::ReceiveEvent(shared_ptr<EventBase> event)
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

void GrenadeDrone::Run(double t)
{
	UAVBase::Run(t);
}

void GrenadeDrone::Destory()
{
	UAVBase::Destory();
}

extern "C" _declspec(dllexport) GrenadeDrone* CreateModel()
{
	return new GrenadeDrone();
}