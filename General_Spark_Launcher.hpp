


#ifndef _FIREWORKS_HPP_
#define _FIREWORKS_HPP_

#include <GL/gl.h>
#include "Utils.hpp"

class General_Spark_Launcher: public Spark 
{
	General_Spark_Launcher(Point start_pos, Vec start_vel);
	bool dead();
	bool has_children();
	Vector<Spark> children();
	Vector<Spark> create_explosion();
};


#endif
