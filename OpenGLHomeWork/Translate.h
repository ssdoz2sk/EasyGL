#pragma once
#ifndef TRANSLATE
#define TRANSLATE
class Translate {
public:
	double x;
	double y;
	double z;
	Translate() {
		x = 0;
		y = 0;
		z = 0;
	}

	Translate(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
#endif#pragma once
