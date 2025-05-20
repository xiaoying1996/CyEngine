#ifndef _DECISIONBASEALGO_
#define _DECISIONBASEALGO_

#include "Public/PublicEnum.h"
#include "Public/PublicStruct.h"

class DecisionBaseAlgo
{
public:
	DecisionBaseAlgo();
	virtual ~DecisionBaseAlgo();

	virtual void UpdateFormationStu(vector<FormationStu> subordinateStus);
	virtual void UpdateEnemy(vector<Model_BasicInfo> enemyList);
	virtual void GetDecision(vector<FormationStu> &subordinateStus);

protected:
	vector<Model_BasicInfo> _enemyList;
	vector<FormationStu> _subordinateStus;
};

#endif // !_DECISIONBASEALGO_
