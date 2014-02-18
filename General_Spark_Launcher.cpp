

#ifndef _FIREWORKS_CPP_
#define _FIREWORKS_CPP_

#include <GL/gl.h>
#include "Utils.hpp"

#define TIME_UNTIL_EXPLOSION 1000
#define SIZE_OF_EXPLOSION 1000

/*
Description:

A starting spark for the general spark firework display type
It is intended to start by going up. Once it reaches a certain age, it will create a bunch of children and die

*/


General_Spark_Launcher::General_Spark_Launcher(Point start_pos, Vec start_vel):Spark(start_pos, start_vel)
{}


General_Spark_Launcher::dead()
{
	if(age == TIME_UNTIL_EXPLOSION)
		return true;
	return false;
}

General_Spark_Launcher::has_children()
{
	if(age == TIME_UNTIL_EXPLOSION)
		return true;
	return false;
}

Vector<Spark> General_Spark_Launcher::create_explosion()
{
	Vector<Spark> new_sparks = new Vector<Spark>(); 
	for(int i = 0; i < SIZE_OF_EXPLOSION; i++)
	{
		Point new_sparks_position = new Position(position.x, position.y, position.z);
		Vec delta_velocity = random_vec();
		Vec new_sparks_velocity = add(delta_velocity, velocity);
		delete delta_velocity;
		
		Spark new_spark = new Spark(new_sparks_position, new_sparks_velocity, 1);

		new_sparks.push_back(new_spark);
	}
	return new_sparks;
}

Vector<Spark> Spark::children()
{
	if(age == TIME_UNTIL_EXPLOSION)
	{
		return create_explosion();
	}
}

#endif