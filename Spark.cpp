#include <GL/gl.h>
#include "Utils.hpp"
#include "Spark.hpp"

#define GEOMETRY_SIZE 8


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

void Spark::fill_buffer(float * addr)
{
	float size = 0.5;

	Vec worldZ = Vec(0.0, 0.0, 1.0);
	Vec worldX = Vec(1.0, 0.0, 0.0);
	Vec lowerLeft = Vec(position.x - size, position.y - size, position.z);
	Vec lowerRight = Vec(position.x - size, position.y + size, position.z);
	Vec upperLeft = Vec(position.x + size, position.y - size, position.z);
	Vec upperRight = Vec(position.x + size, position.y + size, position.z);
	//very basic, not actually billboarding


	//make two triangles in clockwise order
	//first triangle
	set_vertex(addr + (GEOMETRY_SIZE * 0), lowerLeft);
	set_vertex(addr + (GEOMETRY_SIZE * 1), upperLeft);
	set_vertex(addr + (GEOMETRY_SIZE * 2), lowerRight);
	//second triangle
	set_vertex(addr + (GEOMETRY_SIZE * 3), upperLeft);
	set_vertex(addr + (GEOMETRY_SIZE * 4), upperRight);
	set_vertex(addr + (GEOMETRY_SIZE * 5), lowerRight);
}

void Spark::set_vertex(float * addr, Vec p)
{
	addr[0] = p.x;
	addr[1] = p.y;
	addr[2] = p.z;
}

