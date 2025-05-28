#ifndef _FORMATION_STRUCT
#define _FORMATION_STRUCT
#include <string>
#include <map>
#include "PublicStruct.h"

enum SquadStatu
{
	SQ_UNKNOW = 0,
	SQ_IDLE,
};

struct PlaceStruct
{
	ModelType _type;
	ModelFunction _fun;
	int level;
};

struct StatusStruct
{
	int _SoldierStu;
	int _UAVStu;
	int _VehicleStu;
};

struct IntervalStruct
{
	double _GroupInterval;
	double _SoldierInterval;
	double _VehicleInterval;
};

#endif // !_FORMATION_STRUCT

