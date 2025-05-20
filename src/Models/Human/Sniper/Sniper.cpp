#include "Sniper.h"

Sniper::Sniper()
{
}

Sniper::~Sniper()
{
	HumanBase::~HumanBase();
}

void Sniper::Init(TiXmlElement* unitElement)
{
	HumanBase::Init(unitElement);
	SetType(M_SNIPER);
	vector<ModelFunction> mfuns = { F_ATTACK ,F_COVER ,F_DTTECT };
	SetModelFunction(mfuns);
	_EventForwardService = dynamic_cast<EventForwardBaseService*>(ServiceInterface::GetInstance()->GetServiceByName("EventForwardService"));
	RegisterPublishEvent();
}

void Sniper::ReadScenario()
{
	HumanBase::ReadScenario();
}

void Sniper::PostEvent()
{
	HumanBase::PostEvent();
}

void Sniper::ReceiveEvent(shared_ptr<EventBase> event)
{
	HumanBase::ReceiveEvent(event);
	if (event->category == EventCategory::EVENT_MESSAGE_ATTACKED)
	{
		shared_ptr<Message_Attacked> msg = std::dynamic_pointer_cast<Message_Attacked>(event);
		SetHurt(msg->attackRes._hurt);
	}
}

void Sniper::Run(double t)
{
	HumanBase::Run(t);
}

void Sniper::Destory()
{
	HumanBase::Destory();
}

void Sniper::RegisterPublishEvent()
{
	if (_EventForwardService)
	{
		std::vector<EventCategory> RegisterEventsVec = { EVENT_MESSAGE_ATTACKED };
		std::vector<EventCategory> PublishEventsVec = { EVENT_MESSAGE_MODELSDETECT };
		_EventForwardService->AddPublishRegisterByModel(GetID(), this, RegisterEventsVec, PublishEventsVec);
	}
}

extern "C" _declspec(dllexport) Sniper* CreateModel()
{
	return new Sniper();
}