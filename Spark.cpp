

#ifndef _FIREWORKS_CPP_
#define _FIREWORKS_CPP_

#include <GL/gl.h>
#include "Utils.hpp"

Spark::Spark(Point start_pos, Vec start_vel)
{
	position = start_pos;
	velocity = start_vel;
	age = 0;
}

Spark::~Spark()
{
	delete position;
	delete velocity;
}

Spark::update()
{
	position = add(position, velocity);
}


Vector<Spark> Spark::children()
{
	return false;
}

#endif
