//
// Created by RobertVoropaev on 16.02.2016.
//

#include "Field.h"

#include <algorithm>

Field::Field(){
    x1_ = -10000;
    x2_ = 10000;
    y1_ = -10000;
    y2_ = 10000;
}

Field::Field(double x1, double y1, double x2, double y2){
    x1_ = std::min(x1, x2);
    x2_ = std::max(x1, x2);
    y1_ = std::min(y1, y2);
    y2_ = std::max(y1, y2);
}

double Field::getX1() const {
    return x1_;
}

double Field::getY1() const {
    return y1_;
}

double Field::getX2() const {
    return x2_;
}

double Field::getY2() const {
    return y2_;
}

bool Field::isPointInTheField(double x, double y) const {
    if(x < x1_ || x > x2_){
        return false;
    }
    else if (y < y1_ || y > y2_){
        return false;
    }
    return true;
}

Field Field::generateFieldWithoutBorders(double border) const {
    return Field(x1_ + border, y1_ + border, x2_ - border, y2_ - border);
}

Field Field::generateFieldWithoutLeftAndTopBorders(double border) const {
    return Field(x1_, y1_, x2_ - border, y2_ - border);
}