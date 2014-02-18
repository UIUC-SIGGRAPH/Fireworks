#include <GL/gl.h>
#include "Utils.hpp"


Fireworks::Fireworks(Point start_pos, Camera camera_)
{
	sparks = new Vector<Spark>;
	camera = camera_;
}

Fireworks::~Fireworks()
{
	for(int i = 0; i < sparks.size(); i++)
	{
		delete sparks[i];
	}
	delete sparks;
}

Fireworks::update()
{
	Vector<Spark> new_sparks;
	for(int i = 0; i < sparks.size(); i++)
	{
		sparks[i].update();
		if(sparks[i].has_children())
		{
			Vector<Spark> temp = sparks[i].children();
			for(int i2 = 0; i2 < temp.size(); i2++)
			{
				new_sparks.push_back(temp[i2]);
			}
			delete temp;
		}
		if(sparks[i].dead)
		{
			delete sparks[i];
		}
		else
		{
			new_sparks.push_back(sparks[i]);
		}
	}
}

Fireworks::draw()
{
	int buffer_size = /*all the space we need*/;	//this is the number of bytes needed to store our geometry
	float * buffer = malloc(buffer_size);
	for(int i = 0; i < sparks.size(); i++)
	{
		int offset = i * /*space of a spark*/;
		sparks[i].fill_buffer(buffer + offest);		//adding an integer offset to the buffer pointer position in memory
													//this will make it so that fill_buffer affects the correct memory location
	}
	model.set_geometry(buffer, buffer_size);
	model.draw();
}
