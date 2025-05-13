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
	virtual void SetHealth(double health);
	virtual void SetHurt(double hurt);

	void SetID(int id);
	void GetBasicInfo(Model_BasicInfo &info);
	vector<EventBase*> HandleEvent();
	void HandleModelState();
	void InitComponent();
	void PutEventToComponent();
	void SetServiceInterFace();
	ServiceInterface* _serviceInter = nullptr;
private:
	std::vector<ComponentBase*> _myComponents;
	bool _isInit;
	bool _isReadScenario;
	int _id;
	Model_Position _pos;
	Model_Shape _shape;
	string _name;
	int _camp;
	double _health;
	vector<EventBase*> _events;
	vector<EventBase*> _eventsToSend;

protected:
	ModelType _type;
};

#endif // !_MODEL_BASE_
