#ifndef _EVENT_STRUCT_
#define _EVENT_STRUCT_

#include <iostream>
#include <vector>
#include "PublicStruct.h"

enum EventCategory {
	EVENT_UNKNOW = 0,
	EVENT_MISSION_MOVE = 1,
	EVENT_MESSAGE_MODELSINFOALL=500,
	EVENT_MESSAGE_MODELSDETECT,
};

struct EventBase {
	int receicerID;
	EventCategory category;
	virtual void GetData() = 0;
	EventBase()
	{
		receicerID = 0;
		category = EVENT_UNKNOW;
	}
};

struct Mission_Move : public EventBase
{
	vector<Model_Position> moveList;
	virtual void GetData() 
	{

	}
	Mission_Move()
	{
		category = EventCategory::EVENT_MISSION_MOVE;
	}
};

struct Message_ModelsInfoAll : public EventBase
{
	vector<Model_BasicInfo> modelsInfoList;
	virtual void GetData()
	{

	}
	Message_ModelsInfoAll()
	{
		category = EventCategory::EVENT_MESSAGE_MODELSINFOALL;
	}
};

struct Message_ModelsDetect : public EventBase
{
	vector<Model_BasicInfo> modelsInfoList;
	virtual void GetData()
	{

	}
	Message_ModelsDetect()
	{
		category = EventCategory::EVENT_MESSAGE_MODELSDETECT;
	}
};
#endif // !_PUBLIC_STRUCT_

