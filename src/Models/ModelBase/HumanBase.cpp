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
}

void HumanBase::ReadScenario()
{
	ModelBase::ReadScenario();
}

void HumanBase::PostEvent()
{
	ModelBase::PostEvent();
}

void HumanBase::ReceiveEvent(EventBase *event)
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