#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include <Components/ComponentBase/ComponentBase.h>
#include"Service/ServiceInterface/ServiceInterface.h"
#include"Service/ServiceBase/ServiceBase.h"
using namespace std;
class ModelBase {
public:
	ModelBase();
	virtual ~ModelBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void SetHurt(double hurt);

	void GetBasicInfo(Model_BasicInfo &info);
	vector<EventBase*> HandleEvent();
	void HandleModelState();
	void InitComponent();
	void PutEventToComponent();
	void SetServiceInterFace();
	void CreateSmData(SMStruct sm);
	SMStruct GetSMData();
	void SetSMData(SMStruct sm);
	double GetHealth();
	void SetHealth(double health);
	void SetType(int type);
	Model_Position GetPos();
	int GetType();
	ServiceInterface* _serviceInter = nullptr;
private:
	std::vector<ComponentBase*> _myComponents;
	bool _isInit;
	bool _isReadScenario;
	string _shareMemoryID;
	vector<EventBase*> _events;
	vector<EventBase*> _eventsToSend;
	SMStruct* pData;
	HANDLE hMapFile;
};

#endif // !_MODEL_BASE_
