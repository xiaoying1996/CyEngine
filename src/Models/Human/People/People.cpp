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
	_EventForwardService = dynamic_cast<EventForwardBaseService*>(ServiceInterface::GetInstance()->GetServiceByName("EventForwardService"));
	RegisterPublishEvent();
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
	if (event->category == EventCategory::EVENT_MESSAGE_ATTACKED)
	{
		shared_ptr<Message_Attacked> msg = std::dynamic_pointer_cast<Message_Attacked>(event);
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

void People::RegisterPublishEvent()
{
	if (_EventForwardService)
	{
		std::vector<EventCategory> RegisterEventsVec = { EVENT_MESSAGE_ATTACKED };
		std::vector<EventCategory> PublishEventsVec = { EVENT_MESSAGE_MODELSDETECT };
		_EventForwardService->AddPublishRegisterByModel(GetID(), this, RegisterEventsVec, PublishEventsVec);
	}
}

extern "C" _declspec(dllexport) People* CreateModel()
{
	return new People();
}