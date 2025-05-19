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

//��Աְ��ö������
enum JobType
{
	JOB_UNKNOW=0,
	JOB_SOLDIER = 1,
	JOB_GROUP_LEADER,//�鳤
	JOB_SQUAD_LEADER,//�೤
	JOB_PLATOON_LEADER,//�ų�
	JOB_COMPANY_LEADER,//����
};

#endif // !_PUBLIC_ENUM

