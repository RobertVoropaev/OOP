#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
public:
    double x, y;
};

class Vector {
protected:
    Point vector;
public:
    Vector(Point s) {
        vector = s;
    }

    Vector(double x1, double y1) {
        vector.x = x1;
        vector.y = y1;
    }

    double crossProduct(Vector A);
    double dotProduct(Vector A);
    double length();
};

class Segment {
protected:
    Point a1, a2;
public:
    Segment(Point a, Point b) {
        a1.x = a.x;
        a1.y = a.y;
        a2.x = b.x;
        a2.y = b.y;
    }

    Segment(double a, double b, double c, double d) {
        a1.x = a;
        a1.y = b;
        a2.x = c;
        a2.y = d;
    }

    bool belong(Point A);
    bool belong(Segment A);
    double distance(Point A);
};

class Circle {
protected:
    double r, x0, y0;
public:
    Circle(double a, double b, double c) {
        x0 = a, y0 = b;
        r = c;
    }

    bool belong(Point A);
    void belong(double x1, double y1, double r1);
};

class Angle {
protected:
    Point A, O, B;
public:
    Angle(Point a, Point b, Point c) {
        A.x = a.x;
        A.y = a.y;
        O.x = b.x;
        O.y = b.y;
        B.x = c.x;
        B.y = c.y;
    }

    Angle(double a1, double a2, double o1, double o2, double b1, double b2) {
        A.x = a1;
        A.y = a2;
        O.x = o1;
        O.y = o2;
        B.x = b1;
        B.y = b2;
    }

    bool belong(Point C);
};

class Straight {
protected:
    double A, B, C;
public:
    Straight(double a, double b, double c) {
        A = a;
        B = b;
        C = c;
    }

    bool belong(Point a);
};

class Polygon {
protected:
    Point* m;
    int N;
public:
    Polygon(int A);
    Polygon(const Polygon& obj);
    ~Polygon();
    void set(int i, double x, double y);
    bool convex();

};

class CircleAndStraight : public Circle, public Straight {
public:
    CircleAndStraight(double a1, double a2, double a3,
                      double a4, double a5, double a6) :
                      Circle(a1, a2, a3),
                      Straight(a4, a5, a6) {
    }

    void belong();
};
