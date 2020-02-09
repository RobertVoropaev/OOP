//
// Created by RobertVoropaev on 01.02.2016.
//

#pragma once

#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(size_t sizeN, size_t sizeM);
    Matrix(const Matrix& obj);

    ~Matrix();

    Matrix& operator=(Matrix A);

    Matrix operator+(Matrix A);
    Matrix operator+=(Matrix A);

    Matrix operator*(double a);
    Matrix operator*=(double a);

    Matrix operator/(double a);
    Matrix operator/=(double a);

    friend Matrix operator*(double a, Matrix A);
    Matrix operator*(Matrix A);
    Matrix operator*=(Matrix A);

    double& get(int n, int m);

    friend Matrix transpose(Matrix A);

    friend ostream& operator<<(ostream& stream, Matrix A);
    friend istream& operator>>(istream& stream, Matrix& A);

    bool operator==(Matrix A);
    bool operator!=(Matrix A);

private:
    double**    matrix_;
    size_t      sizeN_;
    size_t      sizeM_;
};

class InvalidIndexException : std::exception {};
class SizeException : std::exception {};
class DivisionByZeroException : std::exception {};