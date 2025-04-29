#ifndef _BATTLEADJUSTSERVICE_
#define _BATTLEADJUSTSERVICE_
#include "Service/ServiceBase/ServiceBase.h"

class BattleAdjustService :public ServiceBase{
public:
	BattleAdjustService();
	virtual ~BattleAdjustService();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishRegister();
	void HandleEvent();
	void GetAllEntity(std::vector<Model_BasicInfo>& entitys);
private:
public:
	
};

#endif // !_BATTLEADJUSTSERVICE_
