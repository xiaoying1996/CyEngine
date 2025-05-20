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
	M_ASSULTMAN,
	M_SNIPER,

	M_OPTICALATTACKUAV = 101,
	M_GRENADEDRONE = 102,
	M_MISSILEDRONE = 103,
	M_OPTICALINFRAREDDRONE,
	M_COMPOSITEWINGDRONE,

	M_GROUNDASSULTUNMANVEHICLE = 201,
	M_JEEP,
	M_CM33,
	M_GUARANTEEVEHICLE,
};

enum ModelFunction
{
	F_UNKNOW = 0,
	F_ATTACK,
	F_COVER,
	F_DTTECT,
	F_SUPPLY,
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

//��Ա��ְ��
enum Duty
{
	D_UNKNOW = 0,
	D_ATTACK,
	D_DEFEND,
	D_PROTECT,
	D_COVER,
	D_DETECT,
	D_OCCUPY,
	D_AMBUSH,
};

#endif // !_PUBLIC_ENUM

