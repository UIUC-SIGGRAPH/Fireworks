#ifndef _GENERAL_SPARK_LAUNCHER_HPP_
#define _GENERAL_SPARK_LAUNCHER_HPP_

#include <GL/gl.h>
#include "Utils.hpp"
#include <vector>
#include "Spark.hpp"

using namespace std;

class General_Spark_Launcher: public Spark 
{
	public:
		General_Spark_Launcher(Point start_pos, Vec start_vel);
		bool dead();
		bool has_children();
		vector<Spark> children();
		vector<Spark> create_explosion();

	private:
		int age;
		Point position;
};


#endif
