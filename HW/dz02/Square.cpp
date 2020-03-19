//
// Created by RobertVoropaev on 16.02.2016.
//

#include "Square.h"

Square::Square(double x1, double y1, double side, Field field) : field_(field), x1_(x1), y1_(y1), side_(side) {
    Field withoutBordersField = field_.generateFieldWithoutLeftAndTopBorders(side_);
    if(!withoutBordersField.isPointInTheField(x1_, y1_)) {
        throw OutOfFieldException();
    }
}

double Square::getX1() const {
    return x1_;
}

double Square::getY1() const {
    return y1_;
}

double Square::getSide() const {
    return side_;
}

void Square::scale(double k) {
    if(k < 0) {
        throw NegativeScaleException();
    }

    double new_side = side_ * k;
    Field withoutBordersField = field_.generateFieldWithoutLeftAndTopBorders(new_side);
    if(!withoutBordersField.isPointInTheField(x1_, y1_)) {
        throw OutOfFieldException();
    }

    side_ = new_side;
}

void Square::move(double deltaX, double deltaY) {
    double new_x = x1_ + deltaX;
    double new_y = y1_ + deltaY;

    Field withoutBordersField = field_.generateFieldWithoutLeftAndTopBorders(side_);
    if(!withoutBordersField.isPointInTheField(new_x, new_y)) {
        throw OutOfFieldException();
    }

    x1_ = new_x;
    y1_ = new_y;
}
