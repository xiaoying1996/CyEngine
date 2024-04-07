#ifndef _PUBLIC_STRUCT_
#define _PUBLIC_STRUCT_

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

#endif // !_PUBLIC_STRUCT_

