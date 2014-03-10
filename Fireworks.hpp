#ifndef _FIREWORKS_HPP_
#define _FIREWORKS_HPP_

#include <GL/gl.h>
#include "Utils.hpp"
#include "Camera.hpp"
#include <vector>

using namespace std;

class Fireworks
{
public:
	Fireworks(Point start_pos, Camera camera_);
	~Fireworks();
	void update();
	void draw();

private:
	vector<Spark> sparks;
	Camera camera;	//needed so that the sparks can face the camera
	GL_Model model;
};

#endif
