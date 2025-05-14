#include "ModelBase.h"
#include "Windows.h"
#include "Tools/MapToJson/MapToJson.h"

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
	if (unitElement == nullptr)
	{
		//û���ҵ�XML�ڵ㣬�޷����г�ʼ��,���������־����
		return;
	}
	int id = 0;
	GetIDFromTiXmlElement(id, unitElement);
	if (id == 0)
	{
		//ģ��û������ID���޷����г�ʼ��,���������־����
		return;
	}
	_shareMemoryID = "_SM_" + to_string(id);
	SMStruct sm;
	Model_BasicInfo basicInfo;
	basicInfo._id = id;
	GetCampFromTiXmlElement(basicInfo._camp, unitElement);
	basicInfo._health = 100;
	string name;
	GetNameFromTiXmlElement(name, unitElement);
	strncpy_s(basicInfo._name, name.c_str(), sizeof(name) - 1);
	basicInfo._name[sizeof(name) - 1] = '\0'; // ȷ����ֹ��
	basicInfo._pos;
	std::vector<double> posVec;
	GetPositionFromTiXmlElement(posVec, unitElement);
	basicInfo._pos._lon = posVec[0];
	basicInfo._pos._lat = posVec[1];
	basicInfo._pos._alt = posVec[2];
	basicInfo._shape;
	basicInfo._type = 0;
	sm.basicInfo = basicInfo;
	CreateSmData(sm);
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
	//1.ͨ�������ڴ��ȡģ����Ϣ�ṹ��
	SMStruct sm = GetSMData();
	string name = sm.basicInfo._name;
	if (sm.basicInfo._id)
	{
		sm.basicInfo._health = health;
	}
	SetSMData(sm);
}

void ModelBase::SetType(int type)
{
	SMStruct sm = GetSMData();
	if (sm.basicInfo._id)
	{
		sm.basicInfo._type = type;
	}
	SetSMData(sm);
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
	//�ж�����ֵ�����С�ڵ���0����ִ��
	if (GetHealth() <= 0)
	{
		return;
	}
	//�����еĻ�������,��ִ�����������Run����
	for (int i = 0; i < _myComponents.size(); i++)
	{
			_myComponents[i]->Run(t);
			//������ͨ�������handleEvent������ȡ����������¼�
			std::vector<EventBase*> events = _myComponents[i]->HandleEvent();
			for (int i = 0; i < events.size(); i++)
			{
				_eventsToSend.push_back(events[i]);
			}
	}
	//��Run��֮�󣬸���������ͻ�ȡ��Ӧ����
	//��һ�β���Ҫ�ˣ���Ϊֱ���ڹ����ڴ������޸�
	/*for (int i = 0; i < _myComponents.size(); i++)
	{
		if (_myComponents[i]->_type == COM_MOVE)
		{
			_pos = _myComponents[i]->GetPos();
		}
	}*/
	//GetAllEventByID(std::vector<Message_Attack>& events,int id)
	//�ӷ����ȡ�Լ����ܵĻ���
	ServiceBase* service = _serviceInter->GetServiceByName("BattleAdjustService");
	if (service)
	{
		std::vector<Message_Attack> events;
		//service->GetAllEventByID(events, _id);//***���޸��깲���ڴ����д***
		if (events.size())
		{
			for (int i = 0; i < events.size(); i++)
			{
				SetHurt(events[i].attackRes._hurt);
				AttackResult result;
				result._agentID = events[i].attackRes._agentID;
				result._effectID = events[i].attackRes._effectID;
				result._category = events[i].attackRes._category;
				result._hurt = events[i].attackRes._hurt;
				//�����������¼�����Ӧ��ʵ��
				Message_Attack* msg = new Message_Attack();
				msg->receicerID = result._effectID;
				msg->attackRes = result;
				_eventsToSend.push_back(msg);
			}
		}
	}
}

void ModelBase::Destory()
{
}

void ModelBase::GetBasicInfo(Model_BasicInfo &info)
{
	//***����Ļ�ȡ�����������޸��깲���ڴ����д***
	/*info._id = _id;
	info._name = _name;
	info._type = _type;
	info._pos = _pos;
	info._shape = _shape;
	info._camp = _camp;
	info._health = _health;*/
}

void ModelBase::InitComponent()
{
	//��ȡ���Ͷ�Ӧ�����ļ�����
	int type = GetType();
	
	int t_Value = 0;
	std::string t_Name;

	TiXmlDocument* xmlDocument = new TiXmlDocument();
	if (!xmlDocument->LoadFile("data\\modelInfo\\model_enum.config"))
	{
		std::string err = xmlDocument->ErrorDesc();
	}
	TiXmlElement* rootElement = xmlDocument->FirstChildElement("Models");
	if (rootElement == nullptr) //�ڵ㲻����
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
	//��ȡ������Ӧ�ö�ȡ�ĸ������ļ�����Ķ�̬��
	vector<string> libraryNameList;
	std::string configName = "data\\modelInfo\\ModelConfig\\" + t_Name + ".config";
	TiXmlDocument* xmlDocument1 = new TiXmlDocument();
	if (!xmlDocument1->LoadFile(configName.c_str()))
	{
		std::string err = xmlDocument1->ErrorDesc();
	}
	TiXmlElement* rootElement1 = xmlDocument1->FirstChildElement("Model");
	if (rootElement1 == nullptr) //�ڵ㲻����
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
	//��������б�
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
		com->SetBasicInfo(info);
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

void ModelBase::SetServiceInterFace()
{
	_serviceInter = ServiceInterface::GetInstance();
	if (_serviceInter)
	{
		int i = 0;
	}
}

void ModelBase::CreateSmData(SMStruct sm)
{
	std::wstring wideStr(_shareMemoryID.begin(), _shareMemoryID.end());
	LPCWSTR lpcwstr = wideStr.c_str();
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // ʹ�÷�ҳ�ļ�
		NULL,                    // Ĭ�ϰ�ȫ����
		PAGE_READWRITE,          // ��дȨ��
		0,                       // ����DWORD���ļ�ӳ���С
		sizeof(SMStruct),      // ����DWORD���ļ�ӳ���С
		lpcwstr); // �����ڴ�����

	if (hMapFile == NULL) {
		std::cerr << "CreateFileMapping failed: " << GetLastError() << std::endl;//***�������д��log������
		return ;
	}

	pData = (SMStruct*)MapViewOfFile(
		hMapFile,                // ӳ�������
		FILE_MAP_ALL_ACCESS,     // ��дȨ��
		0,
		0,
		sizeof(SMStruct));

	if (pData == NULL) {
		std::cerr << "MapViewOfFile failed: " << GetLastError() << std::endl;//***�������д��log������
		CloseHandle(hMapFile);
		return ;
	}
	pData->basicInfo = sm.basicInfo;
	pData->otherInfo = sm.otherInfo;
}

SMStruct ModelBase::GetSMData()
{
	SMStruct sm;
	if (hMapFile && pData)
	{
		sm.basicInfo = pData->basicInfo;
		sm.otherInfo = pData->otherInfo;
	}
	return sm;
}

void ModelBase::SetSMData(SMStruct sm)
{
	*pData = sm;
}

double ModelBase::GetHealth()
{
	return  GetSMData().basicInfo._health;
}

Model_Position ModelBase::GetPos()
{
	return GetSMData().basicInfo._pos;
}

int ModelBase::GetType()
{
	return GetSMData().basicInfo._type;
}