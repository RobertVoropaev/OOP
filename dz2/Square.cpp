#include "Square.h"
#include <cmath>
#include <iostream>

Square::Square() {
	x = y = 0;
	FieldSideX = FieldSideY = 20000;
	side = 10;
}

void Square::setFieldSide(double sideX, double sideY) {
	FieldSideX = sideX;
	FieldSideY = sideY;
}

double Square::getX() {
	return x;
}

double Square::getY() {
	return y;
}

double Square::getSide() {
	return side;
}

void Square::info() {
	std::cout << "Square\n" << "Field: " << FieldSideX << "x" << FieldSideY << "\n" << "SquareCentrePosition: (" << x << "," << y << ")\n" << "SideSquare: " << side << "\n\n";
}

void Square::move(double deltaX, double deltaY) {
	if (((abs(x + side/2 + deltaX)) <= (FieldSideX / 2)) && ((abs(y + side/2 + deltaY) <= (FieldSideY / 2)))) {
		x += deltaX;
		y += deltaY;
	}
	else std::cout << "Error. This command is not executed: move(" << deltaX << "," << deltaY << ")\n\n";
}

void Square::scale(double k) {
	if(k>0) side *= k;
	else std::cout << "Error. This command is not executed: scale(" << k << ")\n\n";
}
