//
// Created by RobertVoropaev on 16.02.2016.
//

#ifndef DZ2_POINT_H
#define DZ2_POINT_H

#include "Field.h"

class Point {
public:
    explicit Point(double x = 0, double y = 0, Field field = Field());

    double getX() const;
    double getY() const;

    void move(double deltaX, double deltaY);
private:
    double x_;
    double y_;

    Field field_;
};

#endif //DZ2_POINT_H