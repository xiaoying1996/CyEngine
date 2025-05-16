#include "ServiceBase.h"

ServiceBase::ServiceBase()
{
}

ServiceBase::~ServiceBase()
{
}

void ServiceBase::Init(TiXmlElement* unitElement)
{

}

void ServiceBase::ReadScenario()
{
}

void ServiceBase::PostEvent(EventBase* event)
{
	//_EventListToSend.push_back(event);
}

void ServiceBase::HandleEvent()
{

}

void ServiceBase::ReceiveEvent(EventBase *event)
{
}

void ServiceBase::Run(double t)
{

}

void ServiceBase::Destory()
{
}

void ServiceBase::PublishRegister()
{

}

void ServiceBase::AddEventPublic(std::vector<EventCategory> events)
{
	bool exist;
	for (int x = 0; x < events.size(); x++)
	{
		exist = false;
		for (int i = 0; i < _EventPublic.size(); i++)
		{
			if (_EventPublic[i] == events[x])
			{
				exist = true;
				break;
			}
		}
		if (!exist)
		{
			_EventPublic.push_back(events[x]);
		}
	}
}
void ServiceBase::AddEventRegister(std::vector<EventCategory> events)
{
	bool exist;
	for (int x = 0; x < events.size(); x++)
	{
		exist = false;
		for (int i = 0; i < _EventRegister.size(); i++)
		{
			if (_EventRegister[i] == events[x])
			{
				exist = true;
				break;
			}
		}
		if (!exist)
		{
			_EventRegister.push_back(events[x]);
		}
	}
}
void ServiceBase::AddModelPublic(std::vector<ModelType> models)
{
	bool exist;
	for (int x = 0; x < models.size(); x++)
	{
		exist = false;
		for (int i = 0; i < _ModelPublic.size(); i++)
		{
			if (_ModelPublic[i] == models[x])
			{
				exist = true;
				break;
			}
		}
		if (!exist)
		{
			_ModelPublic.push_back(models[x]);
		}
	}
}
void ServiceBase::AddModelRegister(std::vector<ModelType> models)
{
	bool exist;
	for (int x = 0; x < models.size(); x++)
	{
		exist = false;
		for (int i = 0; i < _ModelRegister.size(); i++)
		{
			if (_ModelRegister[i] == models[x])
			{
				exist = true;
				break;
			}
		}
		if (!exist)
		{
			_ModelRegister.push_back(models[x]);
		}
	}
}

void ServiceBase::GetDataPublicRegister(std::vector<EventCategory>& EventPublic, std::vector<EventCategory>& EventRegister, std::vector<ModelType>& ModelPublic, std::vector<ModelType>& ModelRegister)
{
	EventPublic = _EventPublic;
	EventRegister = _EventRegister;
	ModelPublic = _ModelPublic;
	ModelRegister = _ModelRegister;
}

void ServiceBase::AddAttackEvent(AttackBase* attack)
{
	
}

void ServiceBase::GetAllEventByID(std::vector<Message_Attack>& events,int id)
{
	for (auto iter = _EventListToSend.begin(); iter != _EventListToSend.end(); iter++)
	{
		if (iter->receicerID == id)
		{
			events.push_back(*iter);
			iter = _EventListToSend.erase(iter);
			if (iter == _EventListToSend.end())
			{
				break;
			}
		}
	}
	
}