#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class SquareMatrix {
public:
    SquareMatrix(int a);

    SquareMatrix(const SquareMatrix &obj);

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

    double operator()(int a, int b);

    friend SquareMatrix trans(SquareMatrix A);

    friend ostream &operator<<(ostream &stream, SquareMatrix A);

    friend istream &operator>>(istream &stream, SquareMatrix &A);

    friend double det(SquareMatrix A);

    friend SquareMatrix inverse(SquareMatrix A, bool &noinverse);

    bool operator==(SquareMatrix A);

    bool operator!=(SquareMatrix A);

private:
    double **matrix;
    int sizeN;
};