//
// Created by RobertVoropaev on 22.03.2016.
//

#include "SquareMatrix.h"

template<size_t N>
SquareMatrix<N>::SquareMatrix(): Matrix<N, N>() {
}

template<size_t N>
SquareMatrix<N>::SquareMatrix(Matrix<N, N> matrix): Matrix<N, N>(matrix) {
}

template<size_t N>
SquareMatrix<N>::SquareMatrix(double matrix[N][N]): Matrix<N, N>(matrix) {
}

template<size_t N>
double det(SquareMatrix<N> const& A) {
    double Det = 0;
    for(int t = 0; t < A.getSizeN(); t++) {
        SquareMatrix<N - 1> B;
        for(int i = 1; i < A.getSizeN(); i++) {
            for(int j = 0; j < A.getSizeN(); j++) {
                if(j < t) {
                    B[i - 1][j] = A[i][j];
                } else if(j > t) {
                    B[i - 1][j - 1] = A[i][j];
                }
            }
        }
        Det += pow(-1, t) * A[0][t] * det(B);
    }
    return Det;
}

template<>
double det(SquareMatrix<1> const& A) {
    return A[0][0];
}

template<size_t N>
SquareMatrix<N> inverse(SquareMatrix<N> const& A) {
    if(det(A) == 0) {
        throw NotInverseExciption();
    } else {
        SquareMatrix<N> B;
        for(int i = 0; i < A.getSizeN(); i++) {
            for(int j = 0; j < A.getSizeN(); j++) {
                SquareMatrix<N - 1> C;
                for(int m = 0; m < A.getSizeN(); m++) {
                    for(int k = 0; k < A.getSizeN(); k++) {
                        if(m < i && k < j) {
                            C[m][k] = A[m][k];
                        } else if(m < i && k > j) {
                            C[m][k - 1] = A[m][k];
                        } else if(m > i && k < j) {
                            C[m - 1][k] = A[m][k];
                        } else if(m > i && k > j) {
                            C[m - 1][k - 1] = A[m][k];
                        }
                    }
                }
                B[i][j] = pow(-1, i + j) * det(C);
            }
        }
        return transpose(B) / det(A);
    }
}

template<size_t N>
bool isOrthogonal(SquareMatrix<N> const& A) {
    return transpose(A) == inverse(A);
}