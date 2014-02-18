

#ifndef _GL_UTILS_H_
#define _GL_UTILS_H_

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "gl_utils.h"

#include <GL/gl.h>

class GL_Model
{
	public:
		GL_Model();
		~GL_Model();
		void set_geometry(float * geometry_, unsigned int geometry_size_);
		void draw();
	private:
		GLfloat * geometry;
		GLuint geometry_buffer;
		unsigned int geometry_size;
};

#endif