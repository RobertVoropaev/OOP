//
// Created by RobertVoropaev on 01.02.2016.
//

#pragma once

#include <iostream>
#include <cmath>
#include "Matrix.h"

using namespace std;

class SquareMatrix {
public:
    SquareMatrix(size_t size);
    SquareMatrix(const SquareMatrix& obj);

    ~SquareMatrix();

    SquareMatrix operator=(SquareMatrix A);

    SquareMatrix operator+(SquareMatrix A);
    SquareMatrix operator+=(SquareMatrix A);

    SquareMatrix operator*(double a);
    SquareMatrix operator*=(double a);

    SquareMatrix operator/(double a);
    SquareMatrix operator/=(double a);

    friend SquareMatrix operator*(double a, SquareMatrix A);
    SquareMatrix operator*(SquareMatrix A);
    SquareMatrix operator*=(SquareMatrix A);

    double& get(size_t n, size_t m);

    friend SquareMatrix transpose(SquareMatrix A);
    friend double det(SquareMatrix A);
    friend SquareMatrix inverse(SquareMatrix A, bool& isInverse);

    friend ostream& operator<<(ostream& stream, SquareMatrix A);

    friend istream& operator>>(istream& stream, SquareMatrix& A);

    bool operator==(SquareMatrix A);
    bool operator!=(SquareMatrix A);

private:
    double**    matrix_;
    size_t      sizeN_;
};