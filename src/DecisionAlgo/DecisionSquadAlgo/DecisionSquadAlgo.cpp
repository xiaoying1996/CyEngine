#include "DecisionSquadAlgo.h"

DecisionSquadAlgo::DecisionSquadAlgo()
{
}

DecisionSquadAlgo::~DecisionSquadAlgo()
{

}

void DecisionSquadAlgo::UpdateFormationStu(vector<FormationStu> subordinateStus)
{
	_subordinateStus.clear();
	_subordinateStus = subordinateStus;
}
void DecisionSquadAlgo::UpdateEnemy(vector<Model_BasicInfo> enemyList)
{
	_enemyList.clear();
	_enemyList = enemyList;
}
void DecisionSquadAlgo::GetDecision(vector<FormationStu>& subordinateStus)
{
	int i = 0;
}

extern "C" _declspec(dllexport) DecisionSquadAlgo* CreateAlgo()
{
	return new DecisionSquadAlgo();
}