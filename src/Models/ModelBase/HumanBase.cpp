#include "HumanBase.h"

HumanBase::HumanBase()
{
	
}

HumanBase::~HumanBase()
{
	ModelBase::~ModelBase();
}

void HumanBase::Init(TiXmlElement* unitElement)
{
	ModelBase::Init(unitElement);
	SetHealth(100);
}

void HumanBase::ReadScenario()
{
	ModelBase::ReadScenario();
}

void HumanBase::PostEvent()
{
	ModelBase::PostEvent();
}

void HumanBase::ReceiveEvent(shared_ptr<EventBase> event)
{
	ModelBase::ReceiveEvent(event);
}

void HumanBase::Run(double t)
{
	ModelBase::Run(t);
}

void HumanBase::Destory()
{
	ModelBase::Destory();
}

void HumanBase::RegisterPublishEvent()
{
	ModelBase::RegisterPublishEvent();
}