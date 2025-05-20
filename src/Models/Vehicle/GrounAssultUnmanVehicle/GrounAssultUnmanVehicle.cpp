#include "GrounAssultUnmanVehicle.h"

GrounAssultUnmanVehicle::GrounAssultUnmanVehicle()
{
}

GrounAssultUnmanVehicle::~GrounAssultUnmanVehicle()
{
	VehicleBase::~VehicleBase();
}

void GrounAssultUnmanVehicle::Init(TiXmlElement* unitElement)
{
	VehicleBase::Init(unitElement);
	SetType(M_GROUNDASSULTUNMANVEHICLE);
	vector<ModelFunction> mfuns = { F_ATTACK ,F_COVER};
	SetModelFunction(mfuns);
}

void GrounAssultUnmanVehicle::ReadScenario()
{
	VehicleBase::ReadScenario();
}

void GrounAssultUnmanVehicle::PostEvent()
{
	VehicleBase::PostEvent();
}

void GrounAssultUnmanVehicle::ReceiveEvent(shared_ptr<EventBase> event)
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

void GrounAssultUnmanVehicle::Run(double t)
{
	VehicleBase::Run(t);
}

void GrounAssultUnmanVehicle::Destory()
{
	VehicleBase::Destory();
}

extern "C" _declspec(dllexport) GrounAssultUnmanVehicle* CreateModel()
{
	return new GrounAssultUnmanVehicle();
}