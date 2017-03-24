#pragma once
#ifndef COLOR
#define COLOR
class Color {
public:
	int r;
	int g;
	int b;
	double getDoubleR() { return r > 255 ? 1.0 : r <= 0 ? 0.0 : (double)r / 256; };
	double getDoubleG() { return g > 255 ? 1.0 : g <= 0 ? 0.0 : (double)g / 256; };
	double getDoubleB() { return b > 255 ? 1.0 : b <= 0 ? 0.0 : (double)b / 256; };

	Color() {
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}

	Color(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
};
#endif