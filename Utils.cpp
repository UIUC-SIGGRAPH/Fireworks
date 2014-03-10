#include "Utils.hpp"


Point::Point(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}
Point::~Point(){return; }


Vec::Vec(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}
Vec::~Vec(){return; }

Vec add(Vec A, Vec B)
{
	return Vec(A.x + B.x, A.y + B.y, A.z + B.z);
}



