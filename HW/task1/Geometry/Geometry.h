//
// Created by RobertVoropaev on 05.04.2016.
//

#ifndef DZ05_GEOMETRY_H
#define DZ05_GEOMETRY_H

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


struct Point {
public:
    double x_;
    double y_;
};


class Vector {
public:
    explicit Vector(Point s);
    Vector(double x1, double y1);

    double crossProduct(Vector A);
    double dotProduct(Vector A);
    double length();

protected:
    Point v_{};
};


class Segment {
public:
    Segment(Point a, Point b);
    Segment(double a, double b, double c, double d);

    bool belong(Point A);
    bool belong(Segment A);
    double distance(Point A);

protected:
    Point p1_{};
    Point p2_{};
};


class Circle {
public:
    Circle(double a, double b, double c);

    bool belong(Point A);
    void belong(double x1, double y1, double r1);

protected:
    double r_;
    double x0_;
    double y0_;
};


class Angle {
public:
    Angle(Point a, Point b, Point c);
    Angle(double a1, double a2, double o1, double o2, double b1, double b2);

    bool belong(Point C);

protected:
    Point a_{};
    Point o_{};
    Point b_{};
};


class Straight {
public:
    Straight(double a, double b, double c);

    bool belong(Point a);

protected:
    double a_;
    double b_;
    double c_;
};


class Polygon {
public:
    explicit Polygon(int a);
    Polygon(const Polygon& obj);
    ~Polygon();

    void set(int i, double x, double y);
    bool convex();

protected:
    Point* arr_;
    int    size_;
};


class CircleAndStraight : public Circle, public Straight {
public:
    CircleAndStraight(double a1, double a2, double a3,
                      double a4, double a5, double a6);

    void belong();
};


#endif //DZ05_GEOMETRY_H

