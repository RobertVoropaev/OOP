//
// Created by RobertVoropaev on 22.03.2016.
//

#ifndef DZ05_SQUAREMATRIX_H
#define DZ05_SQUAREMATRIX_H

#include <iostream>
#include <cmath>

#include "Matrix.h"

using namespace std;

template<size_t N>
class SquareMatrix : public Matrix<N, N> {
public:
    SquareMatrix();
    SquareMatrix(Matrix<N, N> matrix);
    explicit SquareMatrix(double matrix[N][N]);
};

template<size_t N>
double det(SquareMatrix<N> const& A);

template<size_t N>
SquareMatrix<N> inverse(SquareMatrix<N> const& A);

template<size_t N>
bool isOrthogonal(SquareMatrix<2> const& A);

class NotInverseExciption : std::exception {};

#include "SquareMatrix_definitions.h"

#endif //DZ05_SQUAREMATRIX_H