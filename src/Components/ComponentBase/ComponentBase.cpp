#include "ComponentBase.h"
#include "Public/ServiceInterShareMemoryDefs.h"

ComponentBase::ComponentBase()
{
	_isInit = false;
	_isReadScenario = false;
}

ComponentBase::~ComponentBase()
{
}

void ComponentBase::Init(TiXmlElement* unitElement)
{
	//对模型的一些初始化信息进行读取
	_isInit = true;
}

void ComponentBase::ReadScenario()
{
	_isReadScenario = true;
}

void ComponentBase::PostEvent(EventBase* event)
{
	_EventListToSend.push_back(event);
}

std::vector<EventBase*> ComponentBase::HandleEvent()
{
	std::vector<EventBase*> ret = _EventListToSend;
	_EventListToSend.clear();
	return ret;
}

void ComponentBase::ReceiveEvent(EventBase *event)
{
}

void ComponentBase::Run(double t)
{

}

void ComponentBase::Destory()
{
}

void ComponentBase::SetBasicInfo(Model_BasicInfo info, SMStruct* pData, HANDLE hMapFile)
{
	_id = info._id;
	_shareMemoryID = "_SM_" + to_string(_id);
	this->pData = pData;
	this->hMapFile = hMapFile;
}

void ComponentBase::SetServiceInterface(ServiceInterface* inter)
{
	_serviceInterface = inter;
}