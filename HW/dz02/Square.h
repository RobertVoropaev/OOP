//
// Created by RobertVoropaev on 16.02.2016.
//

#ifndef DZ2_SQUARE_H
#define DZ2_SQUARE_H

#include "Field.h"

class Square {
public:
    explicit Square(double x1 = 0, double y1 = 0, double side = 0, Field field = Field());

    double  getX1()     const;
    double  getY1()     const;
    double  getSide()   const;

    void    scale(double k);
    void    move(double deltaX, double deltaY);
private:
    double  x1_;
    double  y1_;
    double  side_;

    Field   field_;
};

#endif //DZ2_SQUARE_H