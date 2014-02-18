



#ifndef _FIREWORKS_HPP_
#define _FIREWORKS_HPP_

#include <GL/gl.h>
#include "Utils.hpp"


class Spark
{
public:
	Spark(Point start_pos, Vec start_vel);
	virtual ~Spark();
	virtual void update();
	virtual bool dead();
	virtual bool has_children();
	virtual Vector<Spark> children();

	virtual void fill_buffer(float * addr);
protected:
	Point position;
	Vec velocity;
	int type;
	int age;
};


#endif
