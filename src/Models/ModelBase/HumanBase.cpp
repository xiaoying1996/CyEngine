#include "HumanBase.h"

HumanBase::HumanBase()
{
	
}

HumanBase::~HumanBase()
{
	ModelBase::~ModelBase();
}

void HumanBase::Init(TiXmlElement* unitElement)
{
	ModelBase::Init(unitElement);
}

void HumanBase::ReadScenario()
{
	ModelBase::ReadScenario();
}

void HumanBase::Run()
{
	ModelBase::Run();
}

void HumanBase::PostEvent()
{
	ModelBase::PostEvent();
}

void HumanBase::ReceiveEvent()
{
	ModelBase::ReceiveEvent();
}

void HumanBase::Destory()
{
	ModelBase::Destory();
}