#ifndef _DECISIONSQUADALGO_
#define _DECISIONSQUADALGO_
#include "DecisionAlgo/DecisionBaseAlgo/DecisionBaseAlgo.h"

class DecisionSquadAlgo:public DecisionBaseAlgo
{
public:
	DecisionSquadAlgo();
	virtual ~DecisionSquadAlgo();

	virtual void UpdateFormationStu(vector<FormationStu> subordinateStus);
	virtual void UpdateEnemy(vector<Model_BasicInfo> enemyList);
	virtual void GetDecision(vector<FormationStu> &subordinateStus);
};

#endif // !_DECISIONSQUADALGO_
