#pragma once

#include <vector>

class EasyGL {
public:
	double width, heigh;
	typedef void(*CallbackPtr)(EasyGL*);

	EasyGL(int *argc, char **argv);
	void init(int window_w = 800, int window_h = 600, char *title = "EasyGL", int displayMode = GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	void setBackground(double r, double g, double b, double apha);
	void setResizeCallback(CallbackPtr callbackptr);
	void setDisplayCallback(CallbackPtr callbackptr);
	void start();

private:
	CallbackPtr displayCallback;
	CallbackPtr resizeCallback;
	void cResizeCallback(int w, int h);
	void cDisplayCallback();
};