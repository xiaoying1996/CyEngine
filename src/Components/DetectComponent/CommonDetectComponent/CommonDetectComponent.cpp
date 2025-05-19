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
	_detectDis = 10000.0;
	_modelManagerService = dynamic_cast<ModelManagerBaseService*>(ServiceInterface::GetInstance()->GetServiceByName("ModelManagerService"));
	_EventForwardService = dynamic_cast<EventForwardBaseService*>(ServiceInterface::GetInstance()->GetServiceByName("EventForwardService"));
}

void CommonDetectComponent::ReadScenario()
{
	ComponentBase::ReadScenario();
}

void CommonDetectComponent::PostEvent(shared_ptr<EventBase> event)
{
	ComponentBase::PostEvent(event);
	//将该事件发送到事件转发服务
	if (_EventForwardService)
	{
		_EventForwardService->HandleEventByComponent(_id, this, event);
	}
}

void CommonDetectComponent::ReceiveEvent(shared_ptr<EventBase> event)
{
	ComponentBase::ReceiveEvent(event);
}

void CommonDetectComponent::Run(double t)
{
	ComponentBase::Run(t);
	Model_Position pos = GetPos();
	if (_modelManagerService)
	{
		std::vector<Model_BasicInfo> entitys;
		_modelManagerService->GetAllEntity(entitys);
		for (int i = 0; i < entitys.size(); i++)
		{
			if (entitys[i]._camp != _camp && entitys[i]._id != _id)
			{
				LLA lla_self; ECEF ecef_self;
				lla_self.lon = pos._lon; lla_self.lat = pos._lat; lla_self.alt = pos._alt;
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
	auto ptr = std::make_shared<Message_ModelsDetect>();
	ptr->receicerID = _id;
	ptr->modelsInfoList = _TargetList;
	PostEvent(ptr);
}

void CommonDetectComponent::Destory()
{
	ComponentBase::Destory();
}

void CommonDetectComponent::RegisterPublishEvent()
{
	if (_EventForwardService)
	{
		std::vector<EventCategory> RegisterEventsVec;
		std::vector<EventCategory> PublishEventsVec = { EVENT_MESSAGE_MODELSDETECT };
		_EventForwardService->AddPublishRegisterByComponent(_id,this, RegisterEventsVec, PublishEventsVec);
	}
}

Model_Position CommonDetectComponent::GetPos()
{
	return GetSMData(hMapFile, pData).basicInfo._pos;
}

extern "C" _declspec(dllexport) CommonDetectComponent* CreateComponent()
{
	return new CommonDetectComponent();
}