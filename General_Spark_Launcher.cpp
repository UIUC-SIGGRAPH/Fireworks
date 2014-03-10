

#include <GL/gl.h>
#include "Utils.hpp"
#include "General_Spark_Launcher.hpp"
#include "Spark.hpp"
#include <vector>

#define TIME_UNTIL_EXPLOSION 1000
#define SIZE_OF_EXPLOSION 1000

using namespace std;

/*
Description:

A starting spark for the general spark firework display type
It is intended to start by going up. Once it reaches a certain age, it will create a bunch of children and die

*/


General_Spark_Launcher::General_Spark_Launcher(Point start_pos, Vec start_vel):Spark(start_pos, start_vel)
{

}


bool General_Spark_Launcher::dead()
{
	if(age == TIME_UNTIL_EXPLOSION)
		return true;
	return false;
}

bool General_Spark_Launcher::has_children()
{
	if(age == TIME_UNTIL_EXPLOSION)
		return true;
	return false;
}

vector<Spark> General_Spark_Launcher::create_explosion()
{
	vector<Spark> new_sparks;
	for(int i = 0; i < SIZE_OF_EXPLOSION; i++)
	{
		Point new_sparks_position(position.x, position.y, position.z);
		Vec delta_velocity = Vec.random_vec();
		Vec new_sparks_velocity = Vec.add(delta_velocity, velocity);
		//delete delta_velocity;
		
		Spark new_spark(new_sparks_position, new_sparks_velocity);

		new_sparks.push_back(new_spark);
	}
	return new_sparks;
}

vector<Spark> General_Spark_Launcher::children()
{
	if(age == TIME_UNTIL_EXPLOSION)
	{
		return create_explosion();
	}
}
