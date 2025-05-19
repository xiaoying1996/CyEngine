#ifndef _PUBLIC_ENUM
#define _PUBLIC_ENUM
#include <string>
#include <map>

enum ErrorState
{
	NERROR = 1,
	ELSEERROR,
	THREADPOOLERR,
};

enum ModelType
{
	M_UNKNOW = 0,
	M_PEOPLE = 1,

	M_OPTICALATTACKUAV = 101,
};

//引擎状态枚举
enum EngineStatus
{
	EN_NOSTU = 0,
	EN_READSEC,
};

//时间推进状态
enum TimeAdvanceStu
{
	ADV_FINISH = 0,
	ADV_READY ,
	ADV_RUNNING,
};

//人员职责枚举类型
enum JobType
{
	JOB_UNKNOW=0,
	JOB_SOLDIER = 1,
	JOB_GROUP_LEADER,//组长
	JOB_SQUAD_LEADER,//班长
	JOB_PLATOON_LEADER,//排长
	JOB_COMPANY_LEADER,//连长
};

#endif // !_PUBLIC_ENUM

