#include "UAVBase.h"

UAVBase::UAVBase()
{
	
}

UAVBase::~UAVBase()
{
	ModelBase::~ModelBase();
}

void UAVBase::Init(TiXmlElement* unitElement)
{
	ModelBase::Init(unitElement);
}

void UAVBase::ReadScenario()
{
	ModelBase::ReadScenario();
}

void UAVBase::PostEvent()
{
	ModelBase::PostEvent();
}

void UAVBase::ReceiveEvent(shared_ptr<EventBase> event)
{
	ModelBase::ReceiveEvent(event);
}

void UAVBase::Run(double t)
{
	ModelBase::Run(t);
}

void UAVBase::Destory()
{
	ModelBase::Destory();
}