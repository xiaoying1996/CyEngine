#ifndef _PUBLIC_STRUCT_
#define _PUBLIC_STRUCT_

#include <iostream>
#include <map>
using namespace std;

struct Model_Position {
	double _lon;
	double _lat;
	double _alt;
	Model_Position() {
		_lon = 0;
		_lat = 0;
		_alt = 0;
	}
	Model_Position(double lon,double lat,double alt) {
		_lon = lon;
		_lat = lat;
		_alt = alt;
	}
};

struct Model_Posture {
	double _pitch;
	double _yaw;
	double _roll;
	Model_Posture() {
		_pitch = 0;
		_yaw = 0;
		_roll = 0;
	}
	Model_Posture(double pitch, double yaw, double roll) {
		_pitch = pitch;
		_yaw = yaw;
		_roll = roll;
	}
};

struct Model_Velocity {
	double _x;
	double _y;
	double _z;
	Model_Velocity() {
		_x = 0;
		_y = 0;
		_z = 0;
	}
	Model_Velocity(double x, double y, double z) {
		_x = x;
		_y = y;
		_z = x;
	}
};

struct Model_Shape {
	double _length;
	double _width;
	double _hight;
	Model_Shape() {
		_length = 0;
		_width = 0;
		_hight = 0;
	}
	Model_Shape(double length,double width,double hight)
	{
		_length = length;
		_width = width;
		_hight = hight;
	}
};

//模型基础数据
struct Model_BasicInfo {
	int _id;
	int _type;
	char _name[128];
	int _camp;
	double _health;
	Model_Position _pos;
	Model_Shape _shape;
	Model_BasicInfo() {
		_id = 0;
		strncpy_s(_name, "", 0);
		_name[0] = '\0'; // 确保终止符
		_pos._lon = 0;_pos._lat = 0;_pos._alt = 0;
		_shape._length = 0; _shape._width = 0; _shape._hight = 0;
		_type = 0;
		_camp = 0;
		_health = 0;
	}
	Model_BasicInfo(int id, int type,string name,int camp, Model_Position pos,Model_Shape shape,double health) {
		_id = id;
		strncpy_s(_name, name.c_str(), sizeof(name) - 1);
		_name[sizeof(name) - 1] = '\0'; // 确保终止符
		_pos = pos;
		_shape = shape;
		_type = type;
		_camp = camp;
		_health = health;
	}
};

//带有模型基础数据的的共享内存结构体
struct SMStruct
{
	Model_BasicInfo basicInfo;
	std::string otherInfo;
};

#endif // !_PUBLIC_STRUCT_

