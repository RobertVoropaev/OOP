//
// Created by RobertVoropaev on 16.02.2016.
//

#include "Circle.h"

Circle::Circle(double x, double y, double r, Field field) : field_(field), x_(x), y_(y), r_(r) {
    Field withoutBordersField = field_.generateFieldWithoutBorders(r_);

    if(!withoutBordersField.isPointInTheField(x_, y_)) {
        throw OutOfFieldException();
    }
}

double Circle::getX() const {
    return x_;
}

double Circle::getY() const {
    return y_;
}

double Circle::getR() const {
    return r_;
}

void Circle::scale(double k) {
    if(k < 0) {
        throw NegativeScaleException();
    }

    double new_r = r_ * k;
    Field withoutBordersField = field_.generateFieldWithoutBorders(new_r);

    if(!withoutBordersField.isPointInTheField(x_, y_)) {
        throw OutOfFieldException();
    }
    r_ = new_r;
}

void Circle::move(double deltaX, double deltaY) {
    double new_x = x_ + deltaX;
    double new_y = y_ + deltaY;

    Field withoutBordersField = field_.generateFieldWithoutBorders(r_);
    if(!withoutBordersField.isPointInTheField(new_x, new_y)) {
        throw OutOfFieldException();
    }

    x_ = new_x;
    y_ = new_y;
}