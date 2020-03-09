//
// Created by RobertVoropaev on 22.03.2016.
//

#include "Matrix.h"

template<size_t N, size_t M>
Matrix<N, M>::Matrix() : sizeN_(N), sizeM_(M) {
    matrix_ = new Row<M>[sizeN_];
}

template<size_t N, size_t M>
Matrix<N, M>::Matrix(double** matrix): sizeN_(N), sizeM_(M) {
    matrix_ = new Row<M>[sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = Row<M>(matrix[i]);
    }
}

template<size_t N, size_t M>
Matrix<N, M>::Matrix(double matrix[N][M]): sizeN_(N), sizeM_(M) {
    matrix_ = new Row<M>[sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = Row<M>(matrix[i]);
    }
}

template<size_t N, size_t M>
Matrix<N, M>::Matrix(Matrix<N, M> const& obj) : sizeN_(N), sizeM_(M) {
    matrix_ = new Row<M>[sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = obj.matrix_[i];
    }
}

template<size_t N, size_t M>
Matrix<N, M>::~Matrix() {
    delete[] matrix_;
}

template<size_t N, size_t M>
Matrix<N, M>& Matrix<N, M>::operator=(Matrix<N, M> const& obj) {
    if(this != &obj) {
        for(int i = 0; i < sizeN_; i++) {
            matrix_[i] = obj.matrix_[i];
        }
    }
    return *this;
}

template<size_t N, size_t M>
size_t Matrix<N, M>::getSizeN() const {
    return sizeN_;
}

template<size_t N, size_t M>
size_t Matrix<N, M>::getSizeM() const {
    return sizeM_;
}

template<size_t N, size_t M>
Matrix<N, M>::operator double**() const {
    auto matrix = new double* [sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix[i] = (double*) matrix_[i];
    }
    return matrix;
}

template<size_t N, size_t M>
Row<M> Matrix<N, M>::operator[](size_t n) const {
    return matrix_[n];
}

template<size_t N, size_t M>
Row<M>& Matrix<N, M>::operator[](size_t n) {
    return matrix_[n];
}

template<size_t N, size_t M>
Matrix<N, M>& Matrix<N, M>::operator+=(Matrix<N, M> const& A) {
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] += A.matrix_[i];
    }
    return *this;
}

template<size_t N, size_t M>
Matrix<N, M> operator+(Matrix<N, M> A, Matrix<N, M> const& B) {
    return A += B;
}

template<size_t N, size_t M>
Matrix<N, M>& Matrix<N, M>::operator-=(Matrix<N, M> const& A) {
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] -= A.matrix_[i];
    }
    return *this;
}

template<size_t N, size_t M>
Matrix<N, M> operator-(Matrix<N, M> A, Matrix<N, M> const& B) {
    return A -= B;
}

template<size_t N, size_t M>
Matrix<N, M>& Matrix<N, M>::operator*=(double a) {
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] *= a;
    }
    return *this;
}

template<size_t N, size_t M>
Matrix<N, N> operator*(Matrix<N, M> const& A, Matrix<M, N> const& B) {
    Matrix<N, N> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++){
                R[i][j] += A[i][k]*B[k][j];
            }
    }
    return R;
}

template<size_t N>
Matrix<N, N> operator*(Matrix<N, N> const& A, Matrix<N, N> const& B) {
    Matrix<N, N> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++){
                R[i][j] += A[i][k]*B[k][j];
            }
    }
    return R;
}

template<size_t N, size_t M>
Matrix<N, M> operator*(Matrix<N, M> A, double a) {
    return A *= a;
}

template<size_t N, size_t M>
Matrix<N, M> operator*(double a, Matrix<N, M> A) {
    return A *= a;
}

template<size_t N, size_t M>
Matrix<N, M>& Matrix<N, M>::operator/=(double a) {
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] /= a;
    }
    return *this;
}

template<size_t N, size_t M>
Matrix<N, M> operator/(Matrix<N, M> A, double a) {
    return A /= a;
}

template<size_t N, size_t M>
Matrix<N, M> operator/(double a, Matrix<N, M> A) {
    return A /= a;
}


template<size_t T, size_t D>
std::ostream& operator<<(std::ostream& stream, Matrix<T, D> const& A) {
    for(int i = 0; i < A.sizeN_; i++) {
        stream << A.matrix_[i];
        stream << endl;
    }
    return stream;
}

template<size_t T, size_t D>
std::istream& operator>>(std::istream& stream, Matrix<T, D>& A) {
    for(int i = 0; i < A.sizeN_; i++) {
        stream >> A.matrix_[i];
    }
    return stream;
}

template<size_t N, size_t M>
bool operator==(Matrix<N, M> const& A, Matrix<N, M> const& B) {
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i])
            return false;
    }
    return true;
}

template<size_t N, size_t M>
bool operator!=(Matrix<N, M> const& A, Matrix<N, M> const& B) {
    return !(A == B);
}

template<size_t T, size_t D>
Matrix<D, T> transpose(Matrix<T, D> const& A) {
    Matrix<D, T> B;
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < D; j++) {
            B[j][i] = A[i][j];
        }
    }
    return B;
}

