#include "Matrix.h"

Matrix::Matrix(int a, int b) {
    sizeN = a;
    sizeM = b;
    matrix = new double* [sizeN];
    for(int i = 0; i < sizeN; i++) {
        matrix[i] = new double[sizeM];
        for(int j = 0; j < sizeM; j++)
            matrix[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& obj) {
    sizeN = obj.sizeN;
    sizeM = obj.sizeM;
    matrix = new double* [sizeN];
    for(int i = 0; i < sizeN; i++) {
        matrix[i] = new double[sizeM];
        for(int j = 0; j < sizeM; j++)
            matrix[i][j] = obj.matrix[i][j];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < sizeN; i++)
        delete[] matrix[i];
    delete[]matrix;
}

Matrix Matrix::operator=(const Matrix& A) {
    if(sizeN != A.sizeN || sizeM != A.sizeM)
        exit(1);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            matrix[i][j] = A.matrix[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& A) const {
    if(sizeN != A.sizeN || sizeM != A.sizeM)
        exit(2);
    Matrix B(sizeN, sizeN);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            B.matrix[i][j] = matrix[i][j] + A.matrix[i][j];
    }
    return B;
}

Matrix Matrix::operator+=(const Matrix& A) {
    if(sizeN != A.sizeN || sizeM != A.sizeM)
        exit(3);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            matrix[i][j] += A.matrix[i][j];
    }
    return *this;
}

Matrix Matrix::operator*(double a) const {
    Matrix B(sizeN, sizeN);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            B.matrix[i][j] = matrix[i][j] * a;
    }
    return B;
}

Matrix Matrix::operator*=(double a) {
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            matrix[i][j] *= a;
    }
    return *this;
}

Matrix Matrix::operator/(double a) const {
    if(a == 0)
        exit(4);
    Matrix B(sizeN, sizeM);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            B.matrix[i][j] = matrix[i][j] / a;
    }
    return B;
}

Matrix Matrix::operator/=(double a) {
    if(a == 0)
        exit(5);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            matrix[i][j] /= a;
    }
    return *this;
}

Matrix operator*(double a, const Matrix& A) {
    for(int i = 0; i < A.sizeN; i++) {
        for(int j = 0; j < A.sizeM; j++)
            A.matrix[i][j] *= a;
    }
    return A;
}

Matrix Matrix::operator*(const Matrix& A) const {
    if(sizeM != A.sizeN)
        exit(6);
    Matrix B(sizeN, sizeN);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            for(int k = 0; k < sizeM; k++) {
                B.matrix[i][j] += (matrix[i][k] * A.matrix[k][j]);
            }
    }
    return B;
}

Matrix Matrix::operator*=(const Matrix& A) {
    if(sizeM != A.sizeN)
        exit(7);
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            for(int k = 0; k < sizeM; k++) {
                matrix[i][k] += A.matrix[k][j];
            }
    }
    return *this;
}

double Matrix::operator()(int a, int b) const {
    if(a > sizeN || b > sizeM)
        exit(1);
    return matrix[a - 1][b - 1];
}

Matrix tran(const Matrix& A) {
    Matrix B(A.sizeM, A.sizeN);
    for(int i = 0; i < A.sizeN; i++) {
        for(int j = 0; j < A.sizeM; j++) {
            B.matrix[j][i] = A.matrix[i][j];
        }
    }
    return B;
}

ostream& operator<<(ostream& stream, const Matrix& A) {
    for(int i = 0; i < A.sizeN; i++) {
        for(int j = 0; j < A.sizeM; j++)
            stream << A.matrix[i][j] << " ";
        stream << endl;
    }
    return stream;
}

istream& operator>>(istream& stream, Matrix& A) {
    for(int i = 0; i < A.sizeN; i++) {
        for(int j = 0; j < A.sizeM; j++)
            stream >> A.matrix[i][j];
    }
    return stream;
}

bool Matrix::operator==(const Matrix& A) const {
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            if(matrix[i][j] != A.matrix[i][j])
                return false;
    }
    return true;
}

bool Matrix::operator!=(const Matrix& A) const {
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++)
            if(matrix[i][j] != A.matrix[i][j])
                return true;
    }
    return false;
}