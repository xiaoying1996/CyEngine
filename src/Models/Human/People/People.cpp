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
	HumanBase::Init(unitElement);
	SetType(M_PEOPLE);
}

void People::ReadScenario()
{
	HumanBase::ReadScenario();
}

void People::PostEvent()
{
	HumanBase::PostEvent();
}

void People::ReceiveEvent(shared_ptr<EventBase> event)
{
	HumanBase::ReceiveEvent(event);
	if (event->category == EventCategory::EVENT_MESSAGE_ATTACK)
	{
		shared_ptr<Message_Attack> msg = std::dynamic_pointer_cast<Message_Attack>(event);
		//SetHurt(msg->attackRes._hurt);
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