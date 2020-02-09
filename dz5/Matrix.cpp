//
// Created by RobertVoropaev on 01.02.2016.
//


#include "Matrix.h"

Matrix::Matrix(size_t sizeN, size_t sizeM) {
    sizeN_ = sizeN;
    sizeM_ = sizeM;
    matrix_ = new double* [sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = new double[sizeM_];
        for(int j = 0; j < sizeM_; j++)
            matrix_[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& obj) {
    sizeN_ = obj.sizeN_;
    sizeM_ = obj.sizeM_;
    matrix_ = new double* [sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = new double[sizeM_];
        for(int j = 0; j < sizeM_; j++)
            matrix_[i][j] = obj.matrix_[i][j];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < sizeN_; i++)
        delete[] matrix_[i];
    delete[]matrix_;
}

Matrix& Matrix::operator=(Matrix A) {
    if(sizeN_ != A.sizeN_ || sizeM_ != A.sizeM_)
        throw SizeException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            matrix_[i][j] = A.matrix_[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(Matrix A) {
    if(sizeN_ != A.sizeN_ || sizeM_ != A.sizeM_)
        throw SizeException();
    Matrix B(sizeN_, sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            B.matrix_[i][j] = matrix_[i][j] + A.matrix_[i][j];
    }
    return B;
}

Matrix Matrix::operator+=(Matrix A) {
    if(sizeN_ != A.sizeN_ || sizeM_ != A.sizeM_)
        throw SizeException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            matrix_[i][j] += A.matrix_[i][j];
    }
    return *this;
}

Matrix Matrix::operator*(double a) {
    Matrix B(sizeN_, sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            B.matrix_[i][j] = matrix_[i][j] * a;
    }
    return B;
}

Matrix Matrix::operator*=(double a) {
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            matrix_[i][j] *= a;
    }
    return *this;
}

Matrix Matrix::operator/(double a) {
    if(a == 0)
        throw DivisionByZeroException();
    Matrix B(sizeN_, sizeM_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            B.matrix_[i][j] = matrix_[i][j] / a;
    }
    return B;
}

Matrix Matrix::operator/=(double a) {
    if(a == 0)
        throw DivisionByZeroException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            matrix_[i][j] /= a;
    }
    return *this;
}

Matrix operator*(double a, Matrix A) {
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeM_; j++)
            A.matrix_[i][j] *= a;
    }
    return A;
}

Matrix Matrix::operator*(Matrix A) {
    if(sizeM_ != A.sizeN_)
        throw SizeException();
    Matrix B(sizeN_, sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            for(int k = 0; k < sizeM_; k++) {
                B.matrix_[i][j] += (matrix_[i][k] * A.matrix_[k][j]);
            }
    }
    return B;
}

Matrix Matrix::operator*=(Matrix A) {
    if(sizeM_ != A.sizeN_)
        throw SizeException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            for(int k = 0; k < sizeM_; k++) {
                matrix_[i][k] += A.matrix_[k][j];
            }
    }
    return *this;
}

double& Matrix::get(int n, int m){
    if(n > sizeN_ || m > sizeM_)
        throw InvalidIndexException();
    return matrix_[n - 1][m - 1];
}

Matrix transpose(Matrix A) {
    Matrix B(A.sizeM_, A.sizeN_);
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeM_; j++) {
            B.matrix_[j][i] = A.matrix_[i][j];
        }
    }
    return B;
}

ostream& operator<<(ostream& stream, Matrix A) {
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeM_; j++)
            stream << A.matrix_[i][j] << " ";
        stream << endl;
    }
    return stream;
}

istream& operator>>(istream& stream, Matrix& A) {
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeM_; j++)
            stream >> A.matrix_[i][j];
    }
    return stream;
}

bool Matrix::operator==(Matrix A) {
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            if(matrix_[i][j] != A.matrix_[i][j])
                return false;
    }
    return true;
}

bool Matrix::operator!=(Matrix A) {
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeM_; j++)
            if(matrix_[i][j] != A.matrix_[i][j])
                return true;
    }
    return false;
}

size_t Matrix::getSizeN() const {
    return sizeN_;
}

size_t Matrix::getSizeM() const {
    return sizeM_;
}
