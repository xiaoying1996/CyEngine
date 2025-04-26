#ifndef _MODELMANAGERSERVICE_
#define _MODELMANAGERSERVICE_
#include "Service/ServiceBase/ServiceBase.h"

class ModelManagerService {
public:
	ModelManagerService();
	virtual ~ModelManagerService();
	virtual void Init();
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishEvent();
	virtual void RegisterEvent();
	virtual void PublishModel();
	virtual void RegisterModel();
	void HandleEvent();
private:
	
public:
	
};

#endif // !_MODELMANAGERSERVICE_
