#include "AssultMan.h"

AssultMan::AssultMan()
{
}

AssultMan::~AssultMan()
{
	HumanBase::~HumanBase();
}

void AssultMan::Init(TiXmlElement* unitElement)
{
	HumanBase::Init(unitElement);
	SetType(M_ASSULTMAN);
	vector<ModelFunction> mfuns = { F_ATTACK ,F_COVER ,F_DTTECT };
	SetModelFunction(mfuns);
	_EventForwardService = dynamic_cast<EventForwardBaseService*>(ServiceInterface::GetInstance()->GetServiceByName("EventForwardService"));
	RegisterPublishEvent();
}

void AssultMan::ReadScenario()
{
	HumanBase::ReadScenario();
}

void AssultMan::PostEvent()
{
	HumanBase::PostEvent();
}

void AssultMan::ReceiveEvent(shared_ptr<EventBase> event)
{
	HumanBase::ReceiveEvent(event);
	if (event->category == EventCategory::EVENT_MESSAGE_ATTACKED)
	{
		shared_ptr<Message_Attacked> msg = std::dynamic_pointer_cast<Message_Attacked>(event);
		SetHurt(msg->attackRes._hurt);
	}
}

void AssultMan::Run(double t)
{
	HumanBase::Run(t);
}

void AssultMan::Destory()
{
	HumanBase::Destory();
}

void AssultMan::RegisterPublishEvent()
{
	if (_EventForwardService)
	{
		std::vector<EventCategory> RegisterEventsVec = { EVENT_MESSAGE_ATTACKED };
		std::vector<EventCategory> PublishEventsVec = { EVENT_MESSAGE_MODELSDETECT };
		_EventForwardService->AddPublishRegisterByModel(GetID(), this, RegisterEventsVec, PublishEventsVec);
	}
}

extern "C" _declspec(dllexport) AssultMan* CreateModel()
{
	return new AssultMan();
}