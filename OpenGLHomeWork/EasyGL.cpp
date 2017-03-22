#include <cstddef>
#include <vector>
#include "GL/glut.h"
#include "EasyGL.h"
#include "Exception.h"

EasyGL::EasyGL(int *argc, char **argv) {
	glutInit(argc, argv);
}

void EasyGL::init(int window_w, int window_h, 
				  char *title,
				  int displayMode) {
	glutInitDisplayMode(displayMode);
	glutInitWindowSize(window_w, window_h);
	glutCreateWindow(title);
	this->displayCallback = NULL;
	this->resizeCallback = NULL;
}

void EasyGL::setBackground(double r, double g, double b, double apha) {
	glClearColor(r, g, b, apha);
}

void EasyGL::setResizeCallback(CallbackPtr callbackptr) {
	this->resizeCallback = callbackptr;
}

void EasyGL::setDisplayCallback(CallbackPtr callbackptr) {
	this->displayCallback = callbackptr;
}

void EasyGL::start() 
{
	glutReshapeFunc(&EasyGL::cResizeCallback);
	glutMainLoop();
}

void EasyGL::cResizeCallback(int w, int h)
{
	this->width = w;
	this->heigh = h;
	if(this->resizeCallback != NULL)
		(this->resizeCallback)(this);
}

void EasyGL::cDisplayCallback()
{
}
