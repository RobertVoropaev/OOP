#include "Point.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
using namespace std;
int main() {
	Point p1;
	p1.move(500, 200);
	p1.info();
	p1.move(100000, 10000);
	p1.info();

	Circle c1;
	c1.move(500, 200);
	c1.scale(2);
	c1.info();
	c1.move(100000, 10000);
	c1.scale(-2);
	c1.info();
	
	Square s1;
	s1.move(500, 200);
	s1.scale(2);
	s1.info();
	s1.move(100000, 10000);
	s1.scale(-2);
	s1.info();

	cin.get();
	return 0;
}