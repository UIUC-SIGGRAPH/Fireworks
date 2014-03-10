

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "GL_Utils.hpp"

#include <GL/gl.h>
#include <GL/glext.h>
#include <stdio.h>

GL_Model::GL_Model()
{
	glGenBuffersARB(1, &geometry_buffer);

	const GLchar * vertexShaderCode = 
		// This matrix member variable provides a hook to manipulate
		// the coordinates of the objects that use this vertex shader
		"uniform mat4 uMVPMatrix;" +
		"attribute vec3 vPositionIn;" +
		"void main() {" +
		// the matrix must be included as a modifier of gl_Position
		"  vec4 position = vec4(vPositionIn, 1.0);" +
		"  gl_Position = uMVPMatrix * position;" +
		"}";
	const GLchar * fragmentShaderCode =
		"precision mediump float;" +
		"void main() {" +
		"  gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);" +	//test color
		// "  gl_FragColor = gl_Position*10;" +
		"}";
	vertexShader = loadShader(GL_VERTEX_SHADER, vertexShaderCode);
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
	glslProgram = GLES20.glCreateProgram();
	glAttachShader(glslProgram, vertexShader);
	glAttachShader(glslProgram, fragmentShader);
	glLinkProgram(glslProgram);

	vertexPosHandle = glGetAttribLocation()

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
	glBufferData(GL_ARRAY_BUFFER, geometry_size, geometry_, GL_DYNAMIC_DRAW);
}

void GL_Model::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, geometry_buffer);

	glUseProgram(glslProgram);

	glVertexAttribPointer();

	glTexCoordPointer(3, GL_FLOAT, sizeof(GLfloat)*8, (GLvoid *)(sizeof(GLfloat)*5));
	glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*8, NULL);

	glDrawArrays(GL_TRIANGLES, 0, glm.num_geometry);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}

int GL_Model::loadShader(GLenum type, char[] shaderCode){
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
