#ifndef _COMPONENT_BASE_
#define _COMPONENT_BASE_
#include "Public/PublicEnum.h"
#include "Public/EventStruct.h"
#include "Public/PublicStruct.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "ComponentEnum.h"
#include <iostream>

class ComponentBase {
public:
	ComponentBase();
	virtual ~ComponentBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();

	void HandleEvent();
	void HandleComponentState();
	void SetBasicInfo(Model_BasicInfo info);
	Model_Position GetPos();
private:
	bool _isInit;
	bool _isReadScenario;
	
public:
	ComType _type;
	Model_Position _pos;
};

#endif // !_COMPONENT_BASE_
