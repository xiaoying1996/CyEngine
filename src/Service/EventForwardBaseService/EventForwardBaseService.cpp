#include "EventForwardBaseService.h"

EventForwardBaseService::EventForwardBaseService()
{
	ServiceBase::ServiceBase();
}

EventForwardBaseService::~EventForwardBaseService()
{
	ServiceBase::~ServiceBase();
}

void EventForwardBaseService::Init(TiXmlElement* unitElement)
{
	ServiceBase::Init(unitElement);
}

void EventForwardBaseService::ReadScenario()
{
	ServiceBase::ReadScenario();
}

void EventForwardBaseService::PostEvent(EventBase* event)
{
	ServiceBase::PostEvent(event);
}

void EventForwardBaseService::ReceiveEvent(EventBase* event)
{
	ServiceBase::ReadScenario();
}

void EventForwardBaseService::Run(double t)
{
	ServiceBase::Run(t);
}

void EventForwardBaseService::Destory()
{
	ServiceBase::Destory();
}

void EventForwardBaseService::AddPublishRegisterByComponent(int id,ComponentBase* com, std::vector<EventCategory> eventsRegister, std::vector<EventCategory> eventsPublish)
{
	
}

void EventForwardBaseService::AddPublishRegisterByModel(int id, ModelBase* model, std::vector<EventCategory> eventsRegister, std::vector<EventCategory> eventsPublish)
{

}

void EventForwardBaseService::HandleEventByComponent(int id, ComponentBase* com, shared_ptr<EventBase> event)
{

}

void EventForwardBaseService::HandleEventByService(shared_ptr<EventBase> event)
{

}