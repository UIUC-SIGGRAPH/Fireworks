#ifndef _SPARKS_HPP_
#define _SPARKS_HPP_

#include <GL/gl.h>
#include "Utils.hpp"
#include <vector>

using namespace std;

class Spark
{
public:
	Spark(Point start_pos, Vec start_vel);
	virtual ~Spark();
	virtual void update();
	virtual bool dead();
	virtual bool has_children();
	virtual vector<Spark> children();

	virtual void fill_buffer(float * addr);
	virtual void set_vertex(float * addr, Vec p)
protected:
	Point position;
	Vec velocity;
	int type;
	int age;
};


#endif
