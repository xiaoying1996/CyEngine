#include "CompositeWingDrone.h"

CompositeWingDrone::CompositeWingDrone()
{
}

CompositeWingDrone::~CompositeWingDrone()
{
	UAVBase::~UAVBase();
}

void CompositeWingDrone::Init(TiXmlElement* unitElement)
{
	UAVBase::Init(unitElement);
	SetType(M_COMPOSITEWINGDRONE);
	vector<ModelFunction> mfuns = { F_DTTECT };
	SetModelFunction(mfuns);
}

void CompositeWingDrone::ReadScenario()
{
	UAVBase::ReadScenario();
}

void CompositeWingDrone::PostEvent()
{
	UAVBase::PostEvent();
}

void CompositeWingDrone::ReceiveEvent(shared_ptr<EventBase> event)
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

void CompositeWingDrone::Run(double t)
{
	UAVBase::Run(t);
}

void CompositeWingDrone::Destory()
{
	UAVBase::Destory();
}

extern "C" _declspec(dllexport) CompositeWingDrone* CreateModel()
{
	return new CompositeWingDrone();
}