#ifndef _HUMAN_BASE_
#define _HUMAN_BASE_
#include "ModelBase.h"
#include "DecisionAlgo/DecisionSquadAlgo/DecisionSquadAlgo.h"

class HumanBase:public ModelBase {
public:
	HumanBase();
	virtual ~HumanBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void Prepare();
	virtual void ReadScenario();
	virtual void PostEvent();
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void RegisterPublishEvent();

	/*
	* 将编制信息初始化
	* 并为指挥体加载相应算法
	*/
	void InitDecisionAlgo(int jobType, string authname, std::vector<int> subordinates);
private:
	double _runSpeed = 0;
	bool _DecisionDo;
	DecisionBaseAlgo* _DecisionAlgo = nullptr;
};

#endif // !_MODEL_BASE_
