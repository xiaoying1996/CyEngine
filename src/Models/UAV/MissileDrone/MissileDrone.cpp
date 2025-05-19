#include "MissileDrone.h"

MissileDrone::MissileDrone()
{
}

MissileDrone::~MissileDrone()
{
	UAVBase::~UAVBase();
}

void MissileDrone::Init(TiXmlElement* unitElement)
{
	UAVBase::Init(unitElement);
	SetType(M_MISSILEDRONE);
}

void MissileDrone::ReadScenario()
{
	UAVBase::ReadScenario();
}

void MissileDrone::PostEvent()
{
	UAVBase::PostEvent();
}

void MissileDrone::ReceiveEvent(shared_ptr<EventBase> event)
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

void MissileDrone::Run(double t)
{
	UAVBase::Run(t);
}

void MissileDrone::Destory()
{
	UAVBase::Destory();
}

extern "C" _declspec(dllexport) MissileDrone* CreateModel()
{
	return new MissileDrone();
}