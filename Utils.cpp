

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

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


#endif