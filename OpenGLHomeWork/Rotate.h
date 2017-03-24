#pragma once
#ifndef ROTATE
#define ROTATE
class Rotate {
public:
	double angle = 0.0;
	int x;
	int y;
	int z;
	Rotate() {
		this->angle = 0;
	}
	Rotate(double angle, int x, int y, int z) {
		this->angle = angle;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
#endif