




#ifndef _FIREWORKS_CPP_
#define _FIREWORKS_CPP_

#include <GL/gl.h>
#include "Utils.hpp"


Spark::Spark(Point start_pos, Vec start_vel, int type_)
{
	position = start_pos;
	velocity = start_vel;
	type = type_;
	age = 0;
}

Spark::~Spark()
{
	delete position;
	delete velocity;
}

bool Spark::dead()
{
	if(age >= 1000 && type == 0)	//Firework launcher
	{
		return true;
	}
	if(age >= 400 && type == 1)		//extra child spark don't live as long
	{
		return true;
	}
	return false;
}

bool Spark::has_children()
{
	if()
}

Fireworks::Fireworks(Point start_pos, Camera camera_)
{
	sparks = new Vector<Spark>;
	camera = camera_;
}

Fireworks::~Fireworks()
{
	delete sparks;
}
