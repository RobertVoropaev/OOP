//
// Created by RobertVoropaev on 16.02.2016.
//

#include "Point.h"

Point::Point(double x, double y, Field field) : field_(field), x_(x), y_(y) {
    if(!field_.isPointInTheField(x, y)) {
        throw OutOfFieldException();
    }
}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

void Point::move(double deltaX, double deltaY) {
    double new_x = x_ + deltaX;
    double new_y = y_ + deltaY;

    if(!field_.isPointInTheField(new_x, new_y)) {
        throw OutOfFieldException();
    }

    x_ = new_x;
    y_ = new_y;
}




