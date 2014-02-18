

#ifndef _FIREWORKS_CPP_
#define _FIREWORKS_CPP_

#include <GL/gl.h>
#include "Utils.hpp"


General_Spark_Launcher::General_Spark_Launcher(Point start_pos, Vec start_vel)
{

}

General_Spark_Launcher::~General_Spark_Launcher()
{
	
}

General_Spark_Launcher::update()
{

}

General_Spark_Launcher::dead()
{

}

General_Spark_Launcher::has_children()
{

}

Vector<Spark> General_Spark_Launcher::create_explosion()
{
	Vector<Spark> new_sparks = new Vector<Spark>(); 
	for(int i = 0; i < 1000; i++)
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

#endif