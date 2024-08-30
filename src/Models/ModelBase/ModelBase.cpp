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
	//对模型的一些初始化信息进行读取
	std::vector<int> posVec;
	GetPositionFromTiXmlElement(posVec, unitElement);
	GetNameFromTiXmlElement(_name,unitElement);
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

void ModelBase::GetBasicInfo(Model_BasicInfo &info)
{
	info._id = _id;
	info._name = _name;
	info._type = _type;
	info._pos = _pos;
	info._shape = _shape;
}