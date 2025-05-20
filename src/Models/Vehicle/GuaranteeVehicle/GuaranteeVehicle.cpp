#include "GuaranteeVehicle.h"

GuaranteeVehicle::GuaranteeVehicle()
{
}

GuaranteeVehicle::~GuaranteeVehicle()
{
	VehicleBase::~VehicleBase();
}

void GuaranteeVehicle::Init(TiXmlElement* unitElement)
{
	VehicleBase::Init(unitElement);
	SetType(M_GUARANTEEVEHICLE);
	vector<ModelFunction> mfuns = {F_SUPPLY };
	SetModelFunction(mfuns);
}

void GuaranteeVehicle::ReadScenario()
{
	VehicleBase::ReadScenario();
}

void GuaranteeVehicle::PostEvent()
{
	VehicleBase::PostEvent();
}

void GuaranteeVehicle::ReceiveEvent(shared_ptr<EventBase> event)
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

void GuaranteeVehicle::Run(double t)
{
	VehicleBase::Run(t);
}

void GuaranteeVehicle::Destory()
{
	VehicleBase::Destory();
}

extern "C" _declspec(dllexport) GuaranteeVehicle* CreateModel()
{
	return new GuaranteeVehicle();
}