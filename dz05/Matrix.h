//
// Created by RobertVoropaev on 22.03.2016.
//

#ifndef DZ05_MATRIX_H
#define DZ05_MATRIX_H

#include <iostream>

#include "Row.h"

template<size_t N, size_t M>
class Matrix {
public:
    Matrix();
    explicit Matrix(double** matrix);
    explicit Matrix(double matrix[N][M]);

    Matrix(Matrix<N, M> const& obj);

    virtual ~Matrix();

    Matrix<N, M>& operator=(Matrix<N, M> const& obj);

    size_t getSizeM() const;
    size_t getSizeN() const;

    explicit operator double**() const;

    Row<M>& operator[](size_t n);
    Row<M>  operator[](size_t n) const;

    Matrix<N, M>& operator+=(Matrix<N, M> const& A);
    Matrix<N, M>& operator-=(Matrix<N, M> const& B);
    Matrix<N, M>& operator*=(double a);
    Matrix<N, M>& operator/=(double a);

    template<size_t T, size_t D>
    friend std::ostream& operator<<(std::ostream& stream, Matrix<T, D> const& A);

    template<size_t T, size_t D>
    friend std::istream& operator>>(std::istream& stream, Matrix<T, D>& A);

private:
    Row<M>* matrix_;
    size_t  sizeN_;
    size_t  sizeM_;
};

template<size_t N, size_t M>
Matrix<N, M> operator+(Matrix<N, M> A, Matrix<N, M> const& B);

template<size_t N, size_t M>
Matrix<N, M> operator-(Matrix<N, M> A, Matrix<N, M> const& B);

template<size_t N, size_t M>
Matrix<N, M> operator*(Matrix<N, M> A, double a);

template<size_t N, size_t M>
Matrix<N, M> operator*(double a, Matrix<N, M> A);

template<size_t N, size_t M>
Matrix<N, N> operator*(Matrix<M, N> const& A, Matrix<M, N> const& B);

template<size_t N, size_t M>
Matrix<N, M> operator/(double a, Matrix<N, M> A);

template<size_t N, size_t M>
bool operator==(Matrix<N, M> const& A, Matrix<N, M> const& B);

template<size_t N, size_t M>
bool operator!=(Matrix<N, M> const& A, Matrix<N, M> const& B);

template<size_t N, size_t M>
Matrix<M, N> transpose(Matrix<N, M> const& A);

#include "Matrix_definitions.h"

#endif //DZ05_MATRIX_H
