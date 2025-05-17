#include "EventForwardService.h"

EventForwardService::EventForwardService()
{
	EventForwardBaseService::EventForwardBaseService();
}

EventForwardService::~EventForwardService()
{
	EventForwardBaseService::~EventForwardBaseService();
}

void EventForwardService::Init(TiXmlElement* unitElement)
{
	EventForwardBaseService::Init(unitElement);
}

void EventForwardService::ReadScenario()
{
	EventForwardBaseService::ReadScenario();
}

void EventForwardService::PostEvent(EventBase* event)
{
	EventForwardBaseService::PostEvent(event);
}

void EventForwardService::ReceiveEvent(EventBase* event)
{
	EventForwardBaseService::ReadScenario();
}

void EventForwardService::Run(double t)
{
	EventForwardBaseService::Run(t);
}

void EventForwardService::Destory()
{
	EventForwardBaseService::Destory();
}

void EventForwardService::AddPublishRegisterByComponent(int id,ComponentBase* com, std::vector<EventCategory> eventsRegister, std::vector<EventCategory> eventsPublish)
{
	EventForwardBaseService::AddPublishRegisterByComponent(id,com, eventsRegister, eventsPublish);
	ComCategoryStruct comCategoryRegister;
	comCategoryRegister.com = com;
	comCategoryRegister.category = eventsRegister;
	_ComEventRegister[id].push_back(comCategoryRegister);
	ComCategoryStruct comCategoryPublish;
	comCategoryPublish.com = com;
	comCategoryPublish.category = eventsPublish;
	_ComEventPublish[id].push_back(comCategoryPublish);
}

void EventForwardService::HandleEventByComponent(int id, ComponentBase* com, shared_ptr<EventBase> event)
{
	if (_ComEventRegister.find(id) != _ComEventRegister.end())
	{
		std::vector<ComCategoryStruct> comCate = _ComEventPublish[id];
		for (int i = 0; i < comCate.size(); i++)
		{
			if (com == comCate[i].com)
			{
				for (int j = 0; j < comCate[i].category.size(); j++)
				{
					if (comCate[i].category[j] == event->category)
					{
						//查看该实体是否自己或所属组件订阅了该事件，进行发送
						std::vector<ComCategoryStruct> comCateRegister = _ComEventRegister[id];
						for (int x = 0; x < comCateRegister.size(); x++)
						{
							ComponentBase* comReceive = comCateRegister[x].com;
							if (comReceive == comCateRegister[x].com)
							{
								std::vector<EventCategory> c = comCateRegister[x].category;
								for (int y = 0; y < comCateRegister[x].category.size(); y++)
								{
									if (comCateRegister[x].category[y] == event->category)
									{
										comReceive->ReceiveEvent(event);
									}
								}
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
}

extern "C" _declspec(dllexport) EventForwardService* CreateServices()
{
	return new EventForwardService();
}