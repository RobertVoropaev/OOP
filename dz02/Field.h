//
// Created by RobertVoropaev on 16.02.2016.
//

#ifndef DZ2_FIELD_H
#define DZ2_FIELD_H

#include <bits/exception.h>

class Field {
public:
    Field();
    Field(double x1, double y1, double x2, double y2);

    double  getX1() const;
    double  getY1() const;
    double  getX2() const;
    double  getY2() const;

    bool    isPointInTheField(double x, double y)                   const;
    Field   generateFieldWithoutBorders(double border)              const;
    Field   generateFieldWithoutLeftAndTopBorders(double border)    const;
private:
    double  x1_;
    double  y1_;

    double  x2_;
    double  y2_;
};

class OutOfFieldException : std::exception {};

class NegativeScaleException : std::exception {};

#endif //DZ2_FIELD_H
