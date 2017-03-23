#include <cstddef>
#include "GL/glut.h"
#include "EasyGL.h"

using namespace std;

void myDisplay(EasyGL *easyGL)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	easyGL->drawCube(5, Translate(0, 0, 0), Color(0, 0, 0));
	glFlush();
}

void myReshape(EasyGL *easyGL)
{
	glViewport(0, 0, easyGL->width, easyGL->heigh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (easyGL->width <= easyGL->heigh)
		glOrtho(-4.0, 4.0, -4.0 * easyGL->heigh / easyGL->width,
			4.0 * easyGL->heigh / easyGL->width, -10.0, 10.0);
	else
		glOrtho(-4.0 * easyGL->width / easyGL->heigh,
			4.0 * easyGL->width / easyGL->heigh, -4.0, 4.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	myDisplay(easyGL);
}

void main(int argc, char **argv)
{
	EasyGL *easyGL = new EasyGL(&argc, argv);
	easyGL->init();
	easyGL->setBackground(1.0, 1, 1.0, 1.0);
	easyGL->setResizeCallback(myReshape);
	easyGL->setDisplayCallback(myDisplay);
	easyGL->start();
}