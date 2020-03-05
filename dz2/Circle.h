//
// Created by RobertVoropaev on 16.02.2016.
//

#ifndef DZ2_CIRCLE_H
#define DZ2_CIRCLE_H

#include "Field.h"

class Circle {
public:
    explicit Circle(double x = 0, double y = 0, double r = 0, Field field = Field());

    double getX() const;
    double getY() const;
    double getR() const;

    void scale(double k);
    void move(double deltaX, double deltaY);
private:
    double x_;
    double y_;
    double r_;

    Field field_;
};

#endif //DZ2_CIRCLE_H