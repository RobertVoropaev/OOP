#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() {
	x = y = 0;
	FieldSideX = FieldSideY = 20000;
	r = 10;
}

void Circle::setFieldSide(double sideX, double sideY) {
	FieldSideX = sideX;
	FieldSideY = sideY;
}

double Circle::getX() {
	return x;
}

double Circle::getY() {
	return y;
}

double Circle::getR() {
	return r;
}

void Circle::info() {
	std::cout << "Circle\n" << "Field: " << FieldSideX << "x" << FieldSideY << "\n" << "CircleCentrePosition: (" << x << "," << y << ")\n" << "CircleRadius: " << r << "\n\n";
}

void Circle::move(double deltaX, double deltaY) {
	if (((abs(x + r + deltaX)) <= (FieldSideX / 2)) && ((abs(y + r + deltaY) <= (FieldSideY / 2)))) {
		x += deltaX;
		y += deltaY;
	}
	else std::cout << "Error. This command is not executed: move(" << deltaX << "," << deltaY << ")\n\n";
}

void Circle::scale(double k) {
	if (k>0) r *= k;
	else std::cout << "Error. This command is not executed: scale(" << k << ")\n\n";
}
