#pragma once

#include "Rotate.h"
#include "Translate.h"
#include "Color.h"

class EasyGL {
protected:
	static EasyGL *instance;
public:
	static double width, heigh;
	typedef void(*CallbackPtr)(EasyGL*);

	EasyGL(int *argc, char **argv);

	void init(int window_w = 800, int window_h = 600, char *title = "EasyGL", int displayMode = GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
	void setBackground(double r, double g, double b, double apha);

	void drawPoint(double size, Translate &coordinate, Color &color);
	void drawLine(double size, Translate &fromCoordinate, Translate &toCoordinate, Color &color);
	void drawCube(double size, Translate &coordinate, Color &color);
	void drawCube(double size, Translate &coordinate, Color &color, Rotate &rotate);

	// �|�� glut �]�w callback�A�ð��� glutMainLoop
	void start();

	// �]�w callback �禡
	void setResizeCallback(CallbackPtr callbackptr);
	void setDisplayCallback(CallbackPtr callbackptr);

	// �U�� callback �|�����b start �ɸj�J glut
	static void displayCallback();
	static void resizeCallback(int w, int h);

private:
	CallbackPtr cResizeCallback;
	CallbackPtr cDisplayCallback;
};