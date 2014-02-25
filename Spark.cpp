#include <GL/gl.h>
#include "Utils.hpp"
#include "Spark.hpp"


Spark::Spark(Point start_pos, Vec start_vel)
{
	position = start_pos;
	velocity = start_vel;
	age = 0;
}

Spark::~Spark()
{
	/*delete position;
	delete velocity;*/
}

void Spark::update()
{
	position = add(position, velocity);
}


Vector<Spark> Spark::children()
{
	return false;
}
