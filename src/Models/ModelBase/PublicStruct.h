#ifndef _PUBLIC_STRUCT_
#define _PUBLIC_STRUCT_

#include <iostream>
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

struct Model_BasicInfo {
	int _id;
	int _type;
	string _name;
	Model_Position _pos;
	Model_Shape _shape;
	Model_BasicInfo() {
		_id = 0;
		_name = "";
		_pos._lon = 0;_pos._lat = 0;_pos._alt = 0;
		_shape._length = 0; _shape._width = 0; _shape._hight = 0;
		_type = 0;
	}
	Model_BasicInfo(int id, int type,string name, Model_Position pos,Model_Shape shape) {
		_id = id;
		_name = name;
		_pos = pos;
		_shape = shape;
		_type = type;
	}
};

#endif // !_PUBLIC_STRUCT_

