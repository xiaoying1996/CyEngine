#include "VehicleBase.h"

VehicleBase::VehicleBase()
{
	
}

VehicleBase::~VehicleBase()
{
	ModelBase::~ModelBase();
}

void VehicleBase::Init(TiXmlElement* unitElement)
{
	ModelBase::Init(unitElement);
}

void VehicleBase::ReadScenario()
{
	ModelBase::ReadScenario();
}

void VehicleBase::PostEvent()
{
	ModelBase::PostEvent();
}

void VehicleBase::ReceiveEvent(shared_ptr<EventBase> event)
{
	ModelBase::ReceiveEvent(event);
}

void VehicleBase::Run(double t)
{
	ModelBase::Run(t);
}

void VehicleBase::Destory()
{
	ModelBase::Destory();
}

void VehicleBase::RegisterPublishEvent()
{
	ModelBase::RegisterPublishEvent();
}