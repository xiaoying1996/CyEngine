#include "People.h"

People::People()
{
}

People::~People()
{
	HumanBase::~HumanBase();
}

void People::Init(TiXmlElement* unitElement)
{
	_type = M_PEOPLE;
	HumanBase::Init(unitElement);
}

void People::ReadScenario()
{
	HumanBase::ReadScenario();
}

void People::Run()
{
	HumanBase::Run();
}

void People::PostEvent()
{
	HumanBase::PostEvent();
}

void People::ReceiveEvent()
{
	HumanBase::ReceiveEvent();
}

void People::Destory()
{
	HumanBase::Destory();
}

extern "C" _declspec(dllexport) People* CreateModel()
{
	return new People();
}