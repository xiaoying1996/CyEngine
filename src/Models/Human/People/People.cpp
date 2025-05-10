#include "People.h"

People::People()
{
}

People::~People()
{
	HumanBase::~HumanBase();
}

void People::Init(TiXmlElement* unitElement)
{
	_type = M_PEOPLE;
	HumanBase::Init(unitElement);
}

void People::ReadScenario()
{
	HumanBase::ReadScenario();
}

void People::PostEvent()
{
	HumanBase::PostEvent();
}

void People::ReceiveEvent(EventBase *event)
{
	HumanBase::ReceiveEvent(event);
	if (event->category == EventCategory::EVENT_MESSAGE_ATTACK)
	{
		Message_Attack* msg = dynamic_cast<Message_Attack*>(event);
		SetHurt(msg->attackRes._hurt);
	}
}

void People::Run(double t)
{
	HumanBase::Run(t);
}

void People::Destory()
{
	HumanBase::Destory();
}

extern "C" _declspec(dllexport) People* CreateModel()
{
	return new People();
}