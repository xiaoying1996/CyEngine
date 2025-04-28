#include "ModelBase.h"

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
}

void ModelBase::Init(TiXmlElement* unitElement)
{
	//对模型的一些初始化信息进行读取
	std::vector<double> posVec;
	GetPositionFromTiXmlElement(posVec, unitElement);
	GetNameFromTiXmlElement(_name,unitElement);
	GetCampFromTiXmlElement(_camp, unitElement);
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

void ModelBase::PostEvent()
{
}

vector<EventBase*> ModelBase::HandleEvent()
{
	std::vector<EventBase*> ret = _eventsToSend;
	_eventsToSend.clear();
	return ret;
}

void ModelBase::HandleModelState()
{

}

void ModelBase::ReceiveEvent(EventBase *event)
{
	_events.push_back(event);
}

void ModelBase::Run(double t)
{
	//在运行的基类里面,先执行所有组件的Run函数
	for (int i = 0; i < _myComponents.size(); i++)
	{
			_myComponents[i]->Run(t);
			//在这里通过组件的handleEvent函数读取组件产生的事件
			std::vector<EventBase*> events = _myComponents[i]->HandleEvent();
			for (int i = 0; i < events.size(); i++)
			{
				_eventsToSend.push_back(events[i]);
			}
	}
	//在Run完之后，根据组件类型获取相应数据
	for (int i = 0; i < _myComponents.size(); i++)
	{
		if (_myComponents[i]->_type == COM_MOVE)
		{
			_pos = _myComponents[i]->GetPos();
		}
	}
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
	info._camp = _camp;
}

void ModelBase::InitComponent()
{
	//读取类型对应配置文件名称
	int type = _type;
	
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
		com->Init(nullptr);
		com->ReadScenario();
		Model_BasicInfo info;
		GetBasicInfo(info);
		com->SetBasicInfo(info);
		com->SetServiceInterface(_serviceInter);
		_myComponents.push_back(com);
	}
}

void ModelBase::PutEventToComponent()
{
	for (int i = 0; i < _myComponents.size(); i++)
	{
		for (int j = 0; j < _events.size(); j++)
		{
			_myComponents[i]->ReceiveEvent(_events[j]);
		}
	}
	_events.clear();
}

void ModelBase::SetServiceInterFace(ServiceInterface* inter)
{
	_serviceInter = inter;
	int i = 0;
}