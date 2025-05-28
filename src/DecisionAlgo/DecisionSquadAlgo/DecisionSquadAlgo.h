#ifndef _DECISIONSQUADALGO_
#define _DECISIONSQUADALGO_
#include "DecisionAlgo/DecisionBaseAlgo/DecisionBaseAlgo.h"
#include "Tools/XML_Utils/XML_Utils.h"

class DecisionSquadAlgo:public DecisionBaseAlgo
{
public:
	DecisionSquadAlgo();
	virtual ~DecisionSquadAlgo();

	virtual void UpdateFormationStu(vector<FormationStu> subordinateStus);
	virtual void UpdateEnemy(vector<Model_BasicInfo> enemyList);
	virtual void GetDecision(vector<FormationStu> &subordinateStus);

private:
	int _FormationType;
	double _FormationOrientation;
	int _GroupLevel;
	SquadStatu _SqStu;
	StatusStruct _StaStu;
	IntervalStruct _IntStu;
	vector<PlaceStruct> _PlaceStu;

};

#endif // !_DECISIONSQUADALGO_
