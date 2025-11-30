#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include <Components/ComponentBase/ComponentBase.h>
#include"Service/ServiceInterface/ServiceInterface.h"
#include"Service/ServiceBase/ServiceBase.h"
#include"Service/ModelManagerBaseService/ModelManagerBaseService.h"
#include "DecisionAlgo/DecisionBaseAlgo/DecisionBaseAlgo.h"
using namespace std;
class ModelBase {
public:
	ModelBase();
	virtual ~ModelBase();

	//-----以下函数对外开放------
	/*
	* 陈颖 2025.05.15
	* 通过XML节点对模型进行初始化
	* 外部接口
	* 注意遵循XML节点中的格式
	*/
	virtual void Init(TiXmlElement* unitElement);
	/*
	* * 陈颖 2025.05.15
	* 通过基础数据结构体对模型进行初始化
	* 外部接口同上面的Init函数可选择调用
	* 与上面的Init函数只需调用一个即可
	*/
	virtual void InitByBasicInfo(Model_BasicInfo basicInfo, int jobType, string authname, std::vector<int> subordinates);
	/*
	* * 陈颖 2025.05.20
	* 运行前的准备函数
	* 在所有模型Init结束以后必须调用
	* 可按需求重写
	*/
	virtual void Prepare();
	/*
	* * 陈颖 2025.05.15
	* 通过想定文件或其他数据来源读取相关数据
	* 可选择性调用
	* 可按需求重写
	*/
	virtual void ReadScenario();
	/*
	* * 陈颖 2025.05.15
	* 模型的周期执行函数
	* 每个步长执行一次
	* 可按需求重写
	*/
	virtual void Run(double t);
	/*
	* * * 陈颖 2025.05.15
	* 从模型中获取模型当前的基础信息
	* 对外接口
	* 当前只对基础数据进行处理
	*/
	void GetBasicInfo(Model_BasicInfo &info);
	/*
	* * * 陈颖 2025.05.15
	* 向模型内部推送事件
	* 对外接口
	*/
	void AddEvent(shared_ptr<EventBase> event);

	//-----以下函数非对外开放------
	/*
	* * 陈颖 2025.05.15
	* 模型销毁
	*/
	virtual void Destory();
	/*
	* 陈颖 2025.05.15
	* 推送事件至事件管理服务
	* 未完善，参数未完善
	*/
	virtual void PostEvent();
	/*
	* 陈颖 2025.05.15
	* 模型接收事件
	* 该函数由事件处理服务调用
	* 未完善
	*/
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	/*
	* 陈颖 2025.05.19
	* 向事件转发服务注册和公布事件类型
	*/
	virtual void RegisterPublishEvent();

	//以下为模型内部使用接口，不对外开放
protected:
	void InitComponent();
	void SetServiceInterFace();
	double GetHealth();
	void SetHealth(double health);
	void SetType(int type);
	Model_Position GetPos();
	int GetType();
	int GetID();
	void SetHurt(double hurt);
	void SetModelFunction(vector<ModelFunction> f);
	vector<ModelFunction> GettModelFunction();
	ServiceInterface* _serviceInter = nullptr;
	ModelManagerBaseService* _modelManagerService = nullptr;
private:
	std::vector<ComponentBase*> _myComponents;
	bool _isInit;
	bool _isReadScenario;
	int _id;
	int _type;
	vector<ModelFunction> _modelFun;//模型可执行功能
	string _shareMemoryID;
	SMStruct* pData;
	HANDLE hMapFile;

public:
	JobType _job;
	vector<int> _subordinates;
	string _authName;
	vector<FormationStu> _subordinateStus;
};

#endif // !_MODEL_BASE_
