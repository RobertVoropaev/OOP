#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point() {
	x = y = 0;
	FieldSideX = FieldSideY = 20000;
}

void Point::setFieldSide(double sideX, double sideY) {
	FieldSideX = sideX;
	FieldSideY = sideY;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

void Point::info() {
	std::cout << "Point\n" << "Field: " << FieldSideX << "x" << FieldSideY << "\n" << "PointPosition: (" << x << "," << y << ")\n\n";
}

void Point::move(double deltaX, double deltaY) {
	if (((abs(x + deltaX)) <= (FieldSideX / 2)) && ((abs(y + deltaY) <= (FieldSideY / 2)))) {
		x += deltaX;
		y += deltaY;
	}
	else std::cout << "Error. This command is not executed: move(" << deltaX << "," << deltaY << ")\n\n";
}
