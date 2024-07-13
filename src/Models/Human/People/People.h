#ifndef _PEOPLE_
#define _PEOPLE_

#include "../../ModelBase/HumanBase.h"
#include "Tools/XML_Utils/XML_Utils.h"

class People :public HumanBase {
public:
	People();
	virtual ~People();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void Run();
	virtual void PostEvent();
	virtual void ReceiveEvent();
	virtual void Destory();
};

#endif // !_PEOPLE_
