
#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include <GL/gl.h>
#include "Utils.hpp"

class Camera
{
	public:
		Camera(Point look_from_, Point look_at_);
		~Camera();
		void view();
		void update();
		Point position();
	private:
		Point look_from;
		Point look_at;
};

#endif