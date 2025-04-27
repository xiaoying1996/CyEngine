#include "CommonDetectComponent.h"
#include "Tools/ECEF_LLA/ECEF_LLA.h"

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

void CommonDetectComponent::PostEvent(EventBase* event)
{
	ComponentBase::PostEvent(event);
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
		for (int i = 0; i < entitys.size(); i++)
		{
			if (entitys[i]._camp != _camp && entitys[i]._id != _id)
			{
				LLA lla_self; ECEF ecef_self;
				lla_self.lon = _pos._lon; lla_self.lat = _pos._lat; lla_self.alt = _pos._alt;
				ecef_self = llaToECEF(lla_self);
				LLA lla_target; ECEF ecef_target;
				lla_target.lon = entitys[i]._pos._lon; lla_target.lat = entitys[i]._pos._lat; lla_target.alt = entitys[i]._pos._alt;
				ecef_target = llaToECEF(lla_target);
				double dis = distance(ecef_self, ecef_target);
				bool isExist = false;
				for (auto iter = _TargetList.begin(); iter != _TargetList.end(); iter++)
				{
					if (iter->_id == entitys[i]._id)
					{
						isExist = true;
						if (dis < _detectDis)//更新
						{
							*iter = entitys[i];
						}
						else//清除
						{
							_TargetList.erase(iter);
						}
						break;
					}
				}
				if (!isExist)//不存在，判断是否需要加上
				{
					if (dis < _detectDis)
					{
						_TargetList.push_back(entitys[i]);
					}
				}
			}
		}
	}
	Message_ModelsDetect *modelsDetect = new Message_ModelsDetect();
	modelsDetect->receicerID = _id;
	modelsDetect->modelsInfoList = _TargetList;
	PostEvent(modelsDetect);
}

void CommonDetectComponent::Destory()
{
	ComponentBase::Destory();
}

extern "C" _declspec(dllexport) CommonDetectComponent* CreateComponent()
{
	return new CommonDetectComponent();
}