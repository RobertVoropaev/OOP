#pragma once

#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(int a, int b);

    Matrix(const Matrix &obj);

    ~Matrix();

    Matrix operator=(Matrix A);

    Matrix operator+(Matrix A);

    Matrix operator+=(Matrix A);

    Matrix operator*(double a);

    Matrix operator*=(double a);

    Matrix operator/(double a);

    Matrix operator/=(double a);

    friend Matrix operator*(double a, Matrix A);

    Matrix operator*(Matrix A);

    Matrix operator*=(Matrix A);

    double operator()(int a, int b);

    friend Matrix tran(Matrix A);

    friend ostream &operator<<(ostream &stream, Matrix A);

    friend istream &operator>>(istream &stream, Matrix &A);

    bool operator==(Matrix A);

    bool operator!=(Matrix A);

private:
    double **matrix;
    int sizeN, sizeM;

};
