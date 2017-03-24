#pragma once
#ifndef TRANSLATE
#define TRANSLATE
class Translate {
public:
	double x;
	double y;
	double z;
	Translate() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Translate(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
#endif#pragma once
