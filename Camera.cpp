
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <stdio.h>
#include <GL/glut.h>

#include "Utils.hpp"
#include "Camera.hpp"

Camera::Camera(Point look_from_, Point look_at_)
{
	look_from = look_from_;
	look_at = look_at_;
}

Camera::~Camera()
{
	/*delete look_from;
	delete look_at;*/
}

void Camera::update()
{
	return;
}

void Camera::view()
{
	//todo
}

Point Camera::position()
{
	return look_from;
}
