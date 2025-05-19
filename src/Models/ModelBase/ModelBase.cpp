#include "ModelBase.h"
#include "Tools/MapToJson/MapToJson.h"
#include "Tools/WriteReadShareMemory/WriteReadShareMemory.h"

ModelBase::ModelBase()
{
	_isInit = false;
	_isReadScenario = false;
}

ModelBase::~ModelBase()
{
	/*for (int i = 0; i < _myComponents.size(); i++)
	{
		delete _myComponents[i];
	}*/
	UnmapViewOfFile(pData);
	CloseHandle(hMapFile);
}

void ModelBase::Init(TiXmlElement* unitElement)
{
	if (_isInit)
	{
		return;
	}
	if (unitElement == nullptr)
	{
		//没有找到XML节点，无法进行初始化,后面加入日志服务
		return;
	}
	GetIDFromTiXmlElement(_id, unitElement);
	if (_id == 0)
	{
		//模型没有设置ID，无法进行初始化,后面加入日志服务
		return;
	}
	_shareMemoryID = "_SM_" + to_string(_id);
	SMStruct sm;
	Model_BasicInfo basicInfo;
	basicInfo._id = _id;
	GetCampFromTiXmlElement(basicInfo._camp, unitElement);
	basicInfo._health = 100;
	string name;
	GetNameFromTiXmlElement(name, unitElement);
	strncpy_s(basicInfo._name, name.c_str(), sizeof(name) - 1);
	basicInfo._name[sizeof(name) - 1] = '\0'; // 确保终止符
	basicInfo._pos;
	std::vector<double> posVec;
	GetPositionFromTiXmlElement(posVec, unitElement);
	basicInfo._pos._lon = posVec[0];
	basicInfo._pos._lat = posVec[1];
	basicInfo._pos._alt = posVec[2];
	basicInfo._shape;
	GetTypeFromTiXmlElement(basicInfo._type, unitElement);
	_type = basicInfo._type;
	sm.basicInfo = basicInfo;
	CreateSmData(sm, _shareMemoryID, hMapFile, pData);
	SetServiceInterFace();
	InitComponent();
	_isInit = true;
}

void ModelBase::InitByBasicInfo(Model_BasicInfo basicInfo)
{
	if (_isInit)
	{
		return;
	}
	_shareMemoryID = "_SM_" + to_string(basicInfo._id);
	SMStruct sm;
	sm.basicInfo = basicInfo;
	CreateSmData(sm, _shareMemoryID, hMapFile, pData);
	SetServiceInterFace();
	InitComponent();
	_id = basicInfo._id;
	_type = basicInfo._type;
	_isInit = true;
}

void ModelBase::ReadScenario()
{
	_isReadScenario = true;
}

void ModelBase::PostEvent()
{
}

void ModelBase::SetHealth(double health)
{
	//_health = health;
	//1.通过共享内存获取模型信息结构体
	SMStruct sm = GetSMData(hMapFile,pData);
	string name = sm.basicInfo._name;
	if (sm.basicInfo._id)
	{
		sm.basicInfo._health = health;
	}
	SetSMData(sm,pData);
}

void ModelBase::SetType(int type)
{
	SMStruct sm = GetSMData(hMapFile, pData);
	if (sm.basicInfo._id)
	{
		sm.basicInfo._type = type;
	}
	SetSMData(sm,pData);
}

void ModelBase::SetHurt(double hurt)
{
	double health = GetHealth();
	if (health - hurt <= 0)
	{
		health = 0;
	}
	else
	{
		health = health - hurt;
	}
	SetHealth(health);
}

vector<shared_ptr<EventBase>> ModelBase::HandleEvent()
{
	std::vector<shared_ptr<EventBase>> ret = _eventsToSend;
	_eventsToSend.clear();
	return ret;
}

void ModelBase::ReceiveEvent(shared_ptr<EventBase> event)
{
	//对接收到的事件进行处理，并推送给组件
}

void ModelBase::RegisterPublishEvent()
{

}

void ModelBase::Run(double t)
{
	//判断生命值，如果小于等于0，不执行
	if (GetHealth() <= 0)
	{
		return;
	}
	//在运行的基类里面,先执行所有组件的Run函数
	for (int i = 0; i < _myComponents.size(); i++)
	{
			_myComponents[i]->Run(t);
			//在这里通过组件的handleEvent函数读取组件产生的事件
			std::vector<shared_ptr<EventBase>> events = _myComponents[i]->HandleEvent();
			for (int i = 0; i < events.size(); i++)
			{
				_eventsToSend.push_back(events[i]);
			}
	}
	//在执行完周期函数以后，应当向ModelManager更新自身状态
	if (_modelManagerService)
	{
		Model_BasicInfo info;
		GetBasicInfo(info);
		_modelManagerService->UpdateEntity(info);
	}
	
}

void ModelBase::Destory()
{
}

void ModelBase::GetBasicInfo(Model_BasicInfo &info)
{
	info = GetSMData(hMapFile,pData).basicInfo;
}

void ModelBase::AddEvent(shared_ptr<EventBase> event)
{
	ReceiveEvent(event);
	for (int i = 0; i < _myComponents.size(); i++)
	{
		_myComponents[i]->ReceiveEvent(event);
	}
}

void ModelBase::InitComponent()
{
	//读取类型对应配置文件名称
	int type = GetType();
	
	int t_Value = 0;
	std::string t_Name;

	TiXmlDocument* xmlDocument = new TiXmlDocument();
	if (!xmlDocument->LoadFile("data\\modelInfo\\model_enum.config"))
	{
		std::string err = xmlDocument->ErrorDesc();
	}
	TiXmlElement* rootElement = xmlDocument->FirstChildElement("Models");
	if (rootElement == nullptr) //节点不存在
	{
		delete xmlDocument;
		return ;
	}
	if (rootElement)
	{
		for (TiXmlElement* enumElement = rootElement->FirstChildElement("Enum");
			enumElement != nullptr; enumElement = enumElement->NextSiblingElement("Enum"))
		{
			for (TiXmlElement* valElement = enumElement->FirstChildElement();
				valElement != nullptr; valElement = valElement->NextSiblingElement())
			{
				std::string key = valElement->Value();
				if (key == "Value")
				{
					t_Value = atoi(valElement->FirstChild()->Value());
				}
				else if (key == "Name")
				{
					t_Name = valElement->FirstChild()->Value();
				}
			}
			if (t_Value == type)
			{
				break;
			}
		}
	}
	delete xmlDocument;
	//获取到了我应该读取哪个配置文件里面的动态库
	vector<string> libraryNameList;
	std::string configName = "data\\modelInfo\\ModelConfig\\" + t_Name + ".config";
	TiXmlDocument* xmlDocument1 = new TiXmlDocument();
	if (!xmlDocument1->LoadFile(configName.c_str()))
	{
		std::string err = xmlDocument1->ErrorDesc();
	}
	TiXmlElement* rootElement1 = xmlDocument1->FirstChildElement("Model");
	if (rootElement1 == nullptr) //节点不存在
	{
		delete xmlDocument1;
		return ;
	}
	if (rootElement1)
	{
		TiXmlElement* componentElement = rootElement1->FirstChildElement("Components");
		if (componentElement)
		{
			for (TiXmlElement* enumElement = componentElement->FirstChildElement("Component");
				enumElement != nullptr; enumElement = enumElement->NextSiblingElement("Component"))
			{
				for (TiXmlElement* valElement = enumElement->FirstChildElement();
					valElement != nullptr; valElement = valElement->NextSiblingElement())
				{
					std::string key = valElement->Value();
					if (key == "Library")
					{
						libraryNameList.push_back(valElement->FirstChild()->Value());
					}
				}
			}
		}
	}
	delete xmlDocument1;
	//导入组件列表
	for (int i = 0; i < libraryNameList.size(); i++)
	{
		HINSTANCE hDll;
		#if _DEBUG
		std::string dllPath = "dll\\Debug\\" + libraryNameList[i] + "d.dll";
		hDll = LoadLibrary(stringToLPCWSTR(dllPath));
		#endif
		#if NDEBUG
		std::string dllPath = "dll\\Release\\" + libraryNameList[i] + ".dll";
		hDll = LoadLibrary(stringToLPCWSTR(dllPath));
		#endif
		if (hDll == NULL)
		{
			std::cout << "Load dll failed!";
			return;
		}
		using functionPtr = ComponentBase * (*)();
		functionPtr addFunction = (functionPtr)GetProcAddress(hDll, "CreateComponent");
		if (addFunction == NULL)
		{
			std::cout << "cannot find target function!";
			return ;
		}
		ComponentBase* com = addFunction();
		com->SetServiceInterface(_serviceInter);
		com->Init(nullptr);
		com->ReadScenario();
		Model_BasicInfo info;
		GetBasicInfo(info);
		com->SetBasicInfo(info, pData,hMapFile);
		com->RegisterPublishEvent();
		_myComponents.push_back(com);
	}
}

void ModelBase::SetServiceInterFace()
{
	_serviceInter = ServiceInterface::GetInstance();
	if (_serviceInter)
	{
		ServiceBase  * servicebase = _serviceInter->GetServiceByName("ModelManagerService");
		_modelManagerService = dynamic_cast<ModelManagerBaseService*>(servicebase);
	}
}

double ModelBase::GetHealth()
{
	return  GetSMData(hMapFile,pData).basicInfo._health;
}

Model_Position ModelBase::GetPos()
{
	return GetSMData(hMapFile, pData).basicInfo._pos;
}

int ModelBase::GetType()
{
	return GetSMData(hMapFile, pData).basicInfo._type;
}

int ModelBase::GetID()
{
	return _id;
}