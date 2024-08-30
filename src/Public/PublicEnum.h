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
};

//����״̬ö��
enum EngineStatus
{
	EN_NOSTU = 0,
	EN_READSEC,
};

//ʱ���ƽ�״̬
enum TimeAdvanceStu
{
	ADV_FINISH = 0,
	ADV_READY ,
	ADV_RUNNING,
};
#endif // !_PUBLIC_ENUM

