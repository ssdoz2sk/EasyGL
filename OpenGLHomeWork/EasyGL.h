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

	// 會往 glut 設定 callback，並執行 glutMainLoop
	void start();

	// 設定 callback 函式
	void setResizeCallback(CallbackPtr callbackptr);
	void setDisplayCallback(CallbackPtr callbackptr);

	// 各種 callback 會直接在 start 時綁入 glut
	static void displayCallback();
	static void resizeCallback(int w, int h);

private:
	CallbackPtr cResizeCallback;
	CallbackPtr cDisplayCallback;
};