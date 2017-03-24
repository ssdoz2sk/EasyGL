#include <cstddef>
#include <cstdio>
#include "GL/glut.h"
#include "EasyGL.h"
#include "Exception.h"

EasyGL *EasyGL::instance = 0;
double EasyGL::width = 0;
double EasyGL::heigh = 0;

EasyGL::EasyGL(int *argc, char **argv) {
	glutInit(argc, argv);
}

void EasyGL::init(int window_w, int window_h, 
				  char *title,
				  int displayMode) {
	instance = this;
	glutInitDisplayMode(displayMode);
	glutInitWindowSize(window_w, window_h);
	glutCreateWindow(title);
}

void EasyGL::setBackground(double r, double g, double b, double apha) {
	glClearColor(r, g, b, apha);
}


void EasyGL::drawPoint(double size, Translate & coordinate, Color & color)
{
	glPointSize(size);
	if (&color != NULL) {
		glColor3d(color.getDoubleR(), color.getDoubleG(), color.getDoubleB());
	}
	glBegin(GL_POINTS);
	glVertex3d(coordinate.x, coordinate.y, coordinate.z);
	glEnd();
	glFlush();
}

void EasyGL::drawLine(double size, Translate & fromCoordinate, Translate & toCoordinate, Color & color)
{
	if (&color != NULL) {
		glColor3d(color.getDoubleR(), color.getDoubleG(), color.getDoubleB());
	}
	glLineWidth(size);
	glBegin(GL_LINES);
	glVertex3d(fromCoordinate.x, fromCoordinate.y, fromCoordinate.z);
	glVertex3d(toCoordinate.x, toCoordinate.y, toCoordinate.z);
	glEnd();
	glFlush();
}

void EasyGL::drawCube(double size, Translate & coordinate, Color & color)
{
	this->drawCube(size, coordinate, color, Rotate());
}

void EasyGL::drawCube(double size, Translate &coordinate, Color &color, Rotate &rotate) {
	if (&color != NULL) {
		glColor3d(color.getDoubleR(), color.getDoubleG(), color.getDoubleB());
	}
	glPushMatrix();
	glRotatef(rotate.angle, rotate.x, rotate.y, rotate.z);
	glTranslated(coordinate.x, coordinate.y, coordinate.z);
	glutWireCube(size);
	glPopMatrix();
	glFlush();
}

void EasyGL::setResizeCallback(CallbackPtr callbackptr) {
	this->cResizeCallback = callbackptr;
}

void EasyGL::setDisplayCallback(CallbackPtr callbackptr) {
	this->cDisplayCallback = callbackptr;
}

void EasyGL::start() 
{
	glutReshapeFunc(EasyGL::resizeCallback);
	glutDisplayFunc(EasyGL::displayCallback);
	glutMainLoop();
}

void EasyGL::displayCallback()
{
	instance->cDisplayCallback(instance);
}

void EasyGL::resizeCallback(int w, int h)
{
	EasyGL::width = w;
	EasyGL::heigh = h;
	instance->cResizeCallback(instance);
}
