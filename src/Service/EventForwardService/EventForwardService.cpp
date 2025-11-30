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

void EventForwardService::AddPublishRegisterByModel(int id, ModelBase* model, std::vector<EventCategory> eventsRegister, std::vector<EventCategory> eventsPublish)
{
	EventForwardBaseService::AddPublishRegisterByModel(id, model, eventsRegister, eventsPublish);
	ModelCategoryStruct modelCategoryRegister;
	modelCategoryRegister.model = model;
	modelCategoryRegister.category = eventsRegister;
	_ModelEventRegister[id].push_back(modelCategoryRegister);
	ModelCategoryStruct modelCategoryPublish;
	modelCategoryPublish.model = model;
	modelCategoryPublish.category = eventsPublish;
	_ModelEventPublish[id].push_back(modelCategoryPublish);
}

void EventForwardService::HandleEventByComponent(int id, ComponentBase* com, shared_ptr<EventBase> event)
{
	EventForwardBaseService::HandleEventByComponent(id,com,event);
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
						std::vector<ComCategoryStruct> comCateRegister = _ComEventRegister[event->receicerID];
						for (int x = 0; x < comCateRegister.size(); x++)
						{
							ComponentBase* comReceive = comCateRegister[x].com;
							std::vector<EventCategory> c = comCateRegister[x].category;
							for (int y = 0; y < comCateRegister[x].category.size(); y++)
							{
								if (comCateRegister[x].category[y] == event->category)
								{
									comReceive->ReceiveEvent(event);
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
	std::weak_ptr<EventBase> wp = event;
	event.reset();
	wp.reset();
}

void EventForwardService::HandleEventByService(shared_ptr<EventBase> event)
{
	EventForwardBaseService::HandleEventByService(event);
	if (_ModelEventRegister.find(event->receicerID) != _ModelEventRegister.end())
	{
		std::vector<ModelCategoryStruct> modelCateRegister = _ModelEventRegister[event->receicerID];
		for (int x = 0; x < modelCateRegister.size(); x++)
		{
			ModelBase* modelReceive = modelCateRegister[x].model;
			if (modelReceive == modelCateRegister[x].model)
			{
				std::vector<EventCategory> c = modelCateRegister[x].category;
				for (int y = 0; y < modelCateRegister[x].category.size(); y++)
				{
					if (modelCateRegister[x].category[y] == event->category)
					{
						modelReceive->ReceiveEvent(event);
					}
				}
			}
		}
	}
}

extern "C" _declspec(dllexport) EventForwardService* CreateServices()
{
	return new EventForwardService();
}