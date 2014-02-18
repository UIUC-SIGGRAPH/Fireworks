

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "GL_Utils.h"

#include <GL/gl.h>
#include <stdio.h>

GL_Model::GL_Model()
{
	glGenBuffersARB(1, &geometry_buffer);
}

GL_Model::~GL_Model()
{
	glDeleteBuffers(1, &geometry_buffer);
}

GL_Model::set_geometry(float * geometry, unsigned int geometry_size_)
{
	geometry_size = geometry_size_;
	geometry_elements = geometry_size / (BYTES_PER_ELEMENT); 
	glBindBuffer(GL_ARRAY_BUFFER, geometry_buffer);
	glBufferData(GL_ARRAY_BUFFER, geometry_size, geometry_, GL_DYNAMIC_DRAW);
}

GL_Model::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, geometry_buffer);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glTexCoordPointer(3, GL_FLOAT, sizeof(GLfloat)*8, (GLvoid *)(sizeof(GLfloat)*5));
	glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*8, NULL);

	glDrawArrays(GL_TRIANGLES, 0, glm.num_geometry);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}


