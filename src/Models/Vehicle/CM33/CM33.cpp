#include "CM33.h"

CM33::CM33()
{
}

CM33::~CM33()
{
	CM33::~CM33();
}

void CM33::Init(TiXmlElement* unitElement)
{
	VehicleBase::Init(unitElement);
	SetType(M_CM33);
	vector<ModelFunction> mfuns = { F_SUPPLY };
	SetModelFunction(mfuns);
}

void CM33::ReadScenario()
{
	VehicleBase::ReadScenario();
}

void CM33::PostEvent()
{
	VehicleBase::PostEvent();
}

void CM33::ReceiveEvent(shared_ptr<EventBase> event)
{
	VehicleBase::ReceiveEvent(event);
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

void CM33::Run(double t)
{
	VehicleBase::Run(t);
}

void CM33::Destory()
{
	VehicleBase::Destory();
}

extern "C" _declspec(dllexport) CM33* CreateModel()
{
	return new CM33();
}