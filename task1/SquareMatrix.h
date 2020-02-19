#pragma once

#include <iostream>
#include "Matrix.h"

using namespace std;

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int a) : Matrix(a, a) {};

    SquareMatrix operator=(const SquareMatrix& A);
    SquareMatrix operator+(const SquareMatrix& A) const;
    SquareMatrix operator+=(const SquareMatrix& A);

    SquareMatrix operator*(double a) const;
    SquareMatrix operator*=(double a);

    SquareMatrix operator/(double a) const;
    SquareMatrix operator/=(double a);

    friend SquareMatrix operator*(double a, const SquareMatrix& A);
    SquareMatrix operator*(const SquareMatrix& A) const;
    SquareMatrix operator*=(const SquareMatrix& A);

    double operator()(int a, int b) const;

    friend SquareMatrix tran(const SquareMatrix& A);

    friend ostream& operator<<(ostream& stream, const SquareMatrix& A);
    friend istream& operator>>(istream& stream, SquareMatrix& A);

    friend double det(const SquareMatrix& A);

    friend SquareMatrix inverse(const SquareMatrix& A, bool& noinverse);

    bool operator==(const SquareMatrix& A) const;
    bool operator!=(const SquareMatrix& A) const;
};