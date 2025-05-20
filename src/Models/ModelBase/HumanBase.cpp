#include "HumanBase.h"

HumanBase::HumanBase()
{
	_DecisionDo = false;
}

HumanBase::~HumanBase()
{
	ModelBase::~ModelBase();
}

void HumanBase::Init(TiXmlElement* unitElement)
{
	ModelBase::Init(unitElement);
	int jobtype;
	string authname;
	vector<int> subs;
	GetAuthorizedFromXmlElement(jobtype,authname,subs,unitElement);
	if (jobtype)
	{
		_job = (JobType)jobtype;
		if (_modelManagerService)
		{
			_modelManagerService->UpdateJob(GetID(), _job);
		}
		_subordinates = subs;
		_authName = authname;
	}
	SetHealth(100);
}

void HumanBase::Prepare()
{
	ModelBase::Prepare();
	InitDecisionAlgo(_job, _authName, _subordinates);
}

void HumanBase::ReadScenario()
{
	ModelBase::ReadScenario();
}

void HumanBase::PostEvent()
{
	ModelBase::PostEvent();
}

void HumanBase::ReceiveEvent(shared_ptr<EventBase> event)
{
	ModelBase::ReceiveEvent(event);
}

void HumanBase::Run(double t)
{
	ModelBase::Run(t);
	if (t >= 0.2 && t < 0.3 && !_DecisionDo)
	{
		if (_DecisionAlgo)
		{
			_DecisionAlgo->UpdateFormationStu(_subordinateStus);
			_DecisionAlgo->GetDecision(_subordinateStus);
		}
		_DecisionDo = true;
	}
}

void HumanBase::Destory()
{
	ModelBase::Destory();
}

void HumanBase::RegisterPublishEvent()
{
	ModelBase::RegisterPublishEvent();
}

void HumanBase::InitDecisionAlgo(int jobType, string authname, std::vector<int> subordinates)
{
	_subordinates = subordinates;
	_authName = authname;
	for (int i = 0; i < subordinates.size(); i++)
	{
		if (_modelManagerService)//从模型管理服务获得成员职责类型
		{
			Model_BasicInfo baseInfo;
			_modelManagerService->GetEntityByID(subordinates[i],baseInfo);
			if (baseInfo._id)
			{
				FormationStu formation;
				//在这里设置相应参数
				formation._id = subordinates[i];
				formation._ability = 1;
				_modelManagerService->GetJobByID(subordinates[i], formation._job);
				formation._type = (ModelType)baseInfo._type;
				_modelManagerService->GetModelFunctionByID(subordinates[i], formation._f);
				formation._currpos = baseInfo._pos;
				formation._duty;
				_subordinateStus.push_back(formation);
			}
		}
	}
	string libraryName = "";
	switch (_job)
	{
	case JOB_UNKNOW:
		break;
	case JOB_SOLDIER:
		break;
	case JOB_GROUP_LEADER:
		break;
	case JOB_SQUAD_LEADER:
	{
		libraryName = "DecisionSquadAlgo";
		break;
	}
	case JOB_PLATOON_LEADER:
		break;
	case JOB_COMPANY_LEADER:
		break;
	default:
		break;
	}
	HINSTANCE hDll;
	#if _DEBUG
	std::string dllPath = "dll\\Debug\\" + libraryName + "d.dll";
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
	using functionPtr = DecisionBaseAlgo * (*)();
	functionPtr addFunction = (functionPtr)GetProcAddress(hDll, "CreateAlgo");
	if (addFunction == NULL)
	{
		std::cout << "cannot find target function!";
		return;
	}
	_DecisionAlgo = addFunction();
}