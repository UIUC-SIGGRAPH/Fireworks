

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "GL_Utils.hpp"

#include <GL/gl.h>
#include <GL/glext.h>
#include <stdio.h>

#define GEOMETRY_SIZE 3
#define BYTES_PER_ELEMENT (GEOMETRY_SIZE * sizeof(float))

GL_Model::GL_Model()
{
	glGenBuffersARB(1, &geometry_buffer);

	GLchar * vertexShaderCode = (GLchar *)
		// This matrix member variable provides a hook to manipulate
		// the coordinates of the objects that use this vertex shader
		"uniform mat4 uMVPMatrix;" 
		"attribute vec3 vPositionIn;" 
		"void main() {" 
		// the matrix must be included as a modifier of gl_Position
		"  vec4 position = vec4(vPositionIn, 1.0);" 
		"  gl_Position = uMVPMatrix * position;" 
		"}";
	GLchar * fragmentShaderCode = (GLchar *)
		"precision mediump float;"
		"void main() {"
		"  gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);"	//test color
		"}";
	vertexShader = loadShader(GL_VERTEX_SHADER, vertexShaderCode);
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
	glslProgram = glCreateProgram();
	glAttachShader(glslProgram, vertexShader);
	glAttachShader(glslProgram, fragmentShader);
	glLinkProgram(glslProgram);

	vertexPosHandle = glGetAttribLocation(glslProgram, "vPositionIn");
	if(vertexPosHandle == -1)
	{
		printf("Unable to get handle\n");
	}
	MVPMatrixHandle = glGetAttribLocation(glslProgram, "uMVPMatrix");
	if(MVPMatrixHandle == -1)
	{
		printf("Unable to get handle\n");
	}
}

GL_Model::~GL_Model()
{
	glDeleteBuffers(1, &geometry_buffer);
}

void GL_Model::set_geometry(float * geometry, unsigned int geometry_size_)
{
	geometry_size = geometry_size_;
	geometry_elements = geometry_size / (BYTES_PER_ELEMENT); 
	glBindBuffer(GL_ARRAY_BUFFER, geometry_buffer);
	glBufferData(GL_ARRAY_BUFFER, geometry_size, geometry, GL_DYNAMIC_DRAW);
}

void GL_Model::draw()
{

	glUseProgram(glslProgram);

	glBindBuffer(GL_ARRAY_BUFFER, geometry_buffer);
	glVertexAttribPointer(vertexPosHandle, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, geometry_elements);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}

int GL_Model::loadShader(GLenum type, GLchar * shaderCode){
	int shader = glCreateShader(type);
	int isCompiled;
	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if(!isCompiled)
	{
		printf("Shader did not compile\n");
	}
	return shader;
}
