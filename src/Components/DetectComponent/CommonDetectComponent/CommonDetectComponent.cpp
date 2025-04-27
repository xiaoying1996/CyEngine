#include "CommonDetectComponent.h"

CommonDetectComponent::CommonDetectComponent()
{
	ComponentBase::ComponentBase();
	_type = COM_DETECT;
}

CommonDetectComponent::~CommonDetectComponent()
{
	ComponentBase::~ComponentBase();
}

void CommonDetectComponent::Init(TiXmlElement* unitElement)
{
	ComponentBase::Init(unitElement);
	_detectDis = 100.0;
}

void CommonDetectComponent::ReadScenario()
{
	ComponentBase::ReadScenario();
}

void CommonDetectComponent::PostEvent()
{
	ComponentBase::PostEvent();
}

void CommonDetectComponent::ReceiveEvent(EventBase *event)
{
	ComponentBase::ReceiveEvent(event);
}

void CommonDetectComponent::Run(double t)
{
	ComponentBase::Run(t);
	if (_serviceInterface)
	{
		ServiceBase* service =  _serviceInterface->GetServiceByName("ModelManagerService");
		std::vector<Model_BasicInfo> entitys;
		service->GetAllEntity(entitys);
		int i = 0;
	}
}

void CommonDetectComponent::Destory()
{
	ComponentBase::Destory();
}

extern "C" _declspec(dllexport) CommonDetectComponent* CreateComponent()
{
	return new CommonDetectComponent();
}