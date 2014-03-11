#ifndef _GL_UTILS_HPP_
#define _GL_UTILS_HPP_

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include <GL/gl.h>

class GL_Model
{
	public:
		GL_Model();
		~GL_Model();
		void set_geometry(float * geometry_, unsigned int geometry_size_);
		void draw();
		int loadShader(GLenum type, GLchar * shaderCode);
	private:
		GLfloat * geometry;
		GLuint geometry_buffer;
		unsigned int geometry_size;
		unsigned int geometry_elements;

		int vertexShader;
		int fragmentShader;
		int glslProgram;
		int vertexPosHandle;
		int MVPMatrixHandle;
};

#endif
