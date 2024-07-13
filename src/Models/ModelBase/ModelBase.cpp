#include "ModelBase.h"

ModelBase::ModelBase()
{
	_isInit = false;
	_isReadScenario = false;
}

ModelBase::~ModelBase()
{
}

void ModelBase::Init(TiXmlElement* unitElement)
{
	_type = M_PEOPLE;
	std::vector<int> posVec;
	GetPositionFromTiXmlElement(posVec, unitElement);
	_pos._lon = posVec[0];
	_pos._lat = posVec[1];
	_pos._alt = posVec[2];
	Model_Shape _shape;

	_isInit = true;
}

void ModelBase::ReadScenario()
{
	_isReadScenario = true;
}

void ModelBase::Run()
{
}

void ModelBase::PostEvent()
{
}

void ModelBase::ReceiveEvent()
{
}

void ModelBase::Destory()
{
}

void ModelBase::SetID(int id)
{
	this->_id = id;
}
