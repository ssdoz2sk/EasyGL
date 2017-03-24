#include <cstddef>
#include <cstdio>
#include "GL/glut.h"
#include "EasyGL.h"
#include <Windows.h>

#define PRECISION_OFFSET 0.00001

using namespace std;

double cube_y = 30;
double cube_size = 1;
bool redraw = false;

void myDisplay(EasyGL *easyGL)
{
	do{
		printf("Cube Size: %f . ", cube_size);
		printf("Cube Center : (0, %f. 0). ", cube_y);
		printf("The distance between Cube and Line is %f\n", cube_y - cube_size / 2);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		// x, y, z 三軸標示，輔助畫圖
		easyGL->drawLine(3, Translate(), Translate(1, 0, 0), Color(255, 0, 0));
		easyGL->drawLine(3, Translate(), Translate(0, 1, 0), Color(0, 255, 0));
		easyGL->drawLine(3, Translate(), Translate(0, 0, 1), Color(0, 0, 255));

		// 方塊中心
		easyGL->drawPoint(4, Translate(0, cube_y, 0), Color(255, 0, 0));
		// 方塊移動路徑
		easyGL->drawLine(1, Translate(0, 0, 0), Translate(0, 100, 0), Color(0, 255, 0));
		// 方塊本身
		easyGL->drawCube(cube_size, Translate(0, cube_y, 0), Color(100, 100, 0), Rotate(0, 1, 1, 0));
		//easyGL->drawCube(0.5, Translate(1, -1, -1), Color(100, 100, 0), Rotate(0, 1, 1, 0));
		// 目標直線
		easyGL->drawLine(1, Translate(300, 0, -100), Translate(-300, 0, 100), Color());

		if (!redraw) cube_y -= 0.1;
		// 處理縮放重繪時長度距離會變負的狀況
		if (cube_y - cube_size / 2 <= 2 * PRECISION_OFFSET) {
			cube_y = cube_size / 2;
		}
		redraw = false;
		Sleep(50);
	} while (cube_y - cube_size / 2 >= PRECISION_OFFSET);
}

void myReshape(EasyGL *easyGL)
{
	int view_size[] = {-10, 10, -10, 10}; // left, right, button, up
	glViewport(0, 0, easyGL->width, easyGL->heigh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (easyGL->width <= easyGL->heigh)
		glOrtho(view_size[0], view_size[1], view_size[2] * easyGL->heigh / easyGL->width,
			view_size[3] * easyGL->heigh / easyGL->width, -100.0, 100.0);
	else
		glOrtho(view_size[0] * easyGL->width / easyGL->heigh,
			view_size[1] * easyGL->width / easyGL->heigh, view_size[2], view_size[3], -100.0, 100.0);
	gluLookAt(50, 40, 30, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	redraw = true;
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