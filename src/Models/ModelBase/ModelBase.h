#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include <Components/ComponentBase/ComponentBase.h>
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

	void SetID(int id);
	void GetBasicInfo(Model_BasicInfo &info);
	void HandleEvent();
	void HandleModelState();
	void InitComponent();
	void PutEventToComponent();
private:
	std::vector<ComponentBase*> _myComponents;
	bool _isInit;
	bool _isReadScenario;
	int _id;
	Model_Position _pos;
	Model_Shape _shape;
	string _name;
	int _camp;
	
	vector<EventBase*> _events;

protected:
	ModelType _type;
};

#endif // !_MODEL_BASE_
