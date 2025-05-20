#include "Jeep.h"

Jeep::Jeep()
{
}

Jeep::~Jeep()
{
	VehicleBase::~VehicleBase();
}

void Jeep::Init(TiXmlElement* unitElement)
{
	VehicleBase::Init(unitElement);
	SetType(M_JEEP);
	vector<ModelFunction> mfuns = { F_SUPPLY };
	SetModelFunction(mfuns);
}

void Jeep::ReadScenario()
{
	VehicleBase::ReadScenario();
}

void Jeep::PostEvent()
{
	VehicleBase::PostEvent();
}

void Jeep::ReceiveEvent(shared_ptr<EventBase> event)
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

void Jeep::Run(double t)
{
	VehicleBase::Run(t);
}

void Jeep::Destory()
{
	VehicleBase::Destory();
}

extern "C" _declspec(dllexport) Jeep* CreateModel()
{
	return new Jeep();
}