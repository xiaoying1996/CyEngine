#include "ComponentBase.h"

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

void ComponentBase::PostEvent()
{
}

void ComponentBase::HandleEvent()
{

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

void ComponentBase::HandleComponentState()
{

}

void ComponentBase::SetBasicInfo(Model_BasicInfo info)
{
	_pos = info._pos;
}

Model_Position ComponentBase::GetPos()
{
	return _pos;
}