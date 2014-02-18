

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1


#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>

#include "Camera.hpp"
#include "Fireworks.hpp"

struct controller
{
    int frame;
    Camera * cam;
    Fireworks * fd;
    double last_T;
};

controller cont;

static double ftime(void) {
	int time = glutGet(GLUT_ELAPSED_TIME);
	return (double)time/1000;
}

void animate();

/*
* Animate every 60th of a second
*/
void idle(void) {
    double now_T = ftime();
    double delta_T = now_T - cont.last_T;
    if(delta_T >= (1.0 / 60.0)) //time since last frame is more than 60th of a second
    {
        cont.last_T = now_T;
        animate();
    }

}

void animate()
{
    cont.cam->update();
    cont.fd->update();
    glutPostRedisplay();
}

/*
* Execute everything that will happen in one frame
*/
void display()
{
    //update game objects

    //draw game objects
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    cont.cam->draw();
    glColor3f(0.0, 1.0, 1.0);
    cont.fd->draw();
    glFlush();
}

/*
* initialize every data structure
* setup openGL and window
* prepare for game execution
*/
void init()
{

    //init openGL
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("simple");
    glutIdleFunc(idle);
    glutPostRedisplay();
    glutDisplayFunc(display);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45, 1, .01, 1000);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);

    cont.cam = new Camera(new Point(0.0, 6.0, -12.0), new Point(0.0, 0.0, 0.0));
    cont.fd = new Fireworks(new Point(0.0, 0.0, 0.0));
    
    glutMainLoop();

}


/*
* clean up any variables/memory
*/
void exit();

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    init();
}
