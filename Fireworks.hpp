


#ifndef _FIREWORKS_HPP_
#define _FIREWORKS_HPP_

#include <GL/gl.h>
#include "Utils.hpp"

class Spark
{
public:
	Spark(Point start_pos, Vec start_vel, int type);
	~Spark();
	void update();
	bool dead();
	bool has_children();
	Vector<Spark> children();

	void fill_buffer(float * addr);
private:
	Point position;
	Vec velocity;
	int type;
	int age;
};

class Fireworks
{
public:
	Fireworks(Point start_pos);
	~Fireworks();
	void update();
	void draw();

private:
	Vector<Spark> sparks;
	Camera camera;	//needed so that the sparks can face the camera
};

#endif