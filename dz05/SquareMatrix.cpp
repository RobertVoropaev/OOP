//
// Created by RobertVoropaev on 22.03.2016.
//

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(size_t a) {
    sizeN_ = a;
    matrix_ = new double* [sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = new double[sizeN_];
        for(int j = 0; j < sizeN_; j++)
            matrix_[i][j] = 0;
    }
}

SquareMatrix::SquareMatrix(const SquareMatrix& obj) {
    sizeN_ = obj.sizeN_;
    matrix_ = new double* [sizeN_];
    for(int i = 0; i < sizeN_; i++) {
        matrix_[i] = new double[sizeN_];
        for(int j = 0; j < sizeN_; j++)
            matrix_[i][j] = obj.matrix_[i][j];
    }
}

SquareMatrix::~SquareMatrix() {
    for(int i = 0; i < sizeN_; i++)
        delete[] matrix_[i];
    delete[]matrix_;
}

SquareMatrix SquareMatrix::operator=(SquareMatrix A) {
    if(sizeN_ != A.sizeN_)
        throw SizeException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            matrix_[i][j] = A.matrix_[i][j];
    }
    return *this;
}

SquareMatrix SquareMatrix::operator+(SquareMatrix A) {
    if(sizeN_ != A.sizeN_)
        throw SizeException();
    SquareMatrix B(sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            B.matrix_[i][j] = matrix_[i][j] + A.matrix_[i][j];
    }
    return B;
}

SquareMatrix SquareMatrix::operator+=(SquareMatrix A) {
    if(sizeN_ != A.sizeN_)
        throw SizeException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            matrix_[i][j] += A.matrix_[i][j];
    }
    return *this;
}

SquareMatrix SquareMatrix::operator*(double a) {
    SquareMatrix B(sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            B.matrix_[i][j] = matrix_[i][j] * a;
    }
    return B;
}

SquareMatrix SquareMatrix::operator*=(double a) {
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            matrix_[i][j] *= a;
    }
    return *this;
}

SquareMatrix SquareMatrix::operator/(double a) {
    if(a == 0)
        throw DivisionByZeroException();
    SquareMatrix B(sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            B.matrix_[i][j] = matrix_[i][j] / a;
    }
    return B;
}

SquareMatrix SquareMatrix::operator/=(double a) {
    if(a == 0)
        throw DivisionByZeroException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            matrix_[i][j] /= a;
    }
    return *this;
}

SquareMatrix operator*(double a, SquareMatrix A) {
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeN_; j++)
            A.matrix_[i][j] *= a;
    }
    return A;
}

SquareMatrix SquareMatrix::operator*(SquareMatrix A) {
    if(sizeN_ != A.sizeN_)
        throw SizeException();
    SquareMatrix B(sizeN_);
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            for(int k = 0; k < sizeN_; k++) {
                B.matrix_[i][j] += (matrix_[i][k] * A.matrix_[k][j]);
            }
    }
    return B;
}

SquareMatrix SquareMatrix::operator*=(SquareMatrix A) {
    if(sizeN_ != A.sizeN_)
        throw SizeException();
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            for(int k = 0; k < sizeN_; k++) {
                matrix_[i][k] += A.matrix_[k][j];
            }
    }
    return *this;
}

double& SquareMatrix::get(size_t n, size_t m) {
    if(n > sizeN_ || m > sizeN_)
        throw InvalidIndexException();
    return matrix_[n - 1][m - 1];
}

SquareMatrix transpose(SquareMatrix A) {
    SquareMatrix B(A.sizeN_);
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeN_; j++) {
            B.matrix_[j][i] = A.matrix_[i][j];
        }
    }
    return B;
}

ostream& operator<<(ostream& stream, SquareMatrix A) {
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeN_; j++)
            stream << A.matrix_[i][j] << " ";
        stream << endl;
    }
    return stream;
}

istream& operator>>(istream& stream, SquareMatrix& A) {
    for(int i = 0; i < A.sizeN_; i++) {
        for(int j = 0; j < A.sizeN_; j++)
            stream >> A.matrix_[i][j];
    }
    return stream;
}

double det(SquareMatrix A) {
    if(A.sizeN_ == 2)
        return A.matrix_[0][0] * A.matrix_[1][1] - A.matrix_[0][1] * A.matrix_[1][0];
    else {
        double Det = 0;
        for(int i = 0; i < A.sizeN_; i++) {
            SquareMatrix B(A.sizeN_ - 1);
            for(int j = 1; j < A.sizeN_; j++) {
                for(int k = 0; k < A.sizeN_; k++) {
                    if(k < i)
                        B.matrix_[j - 1][k] = A.matrix_[j][k];
                    else if(k > i)
                        B.matrix_[j - 1][k - 1] = A.matrix_[j][k];
                }
            }
            Det += pow(-1, i) * A.matrix_[0][i] * det(B);
        }
        return Det;
    }
}

SquareMatrix inverse(SquareMatrix A, bool& isInverse) {
    if(det(A) == 0) {
        isInverse = false;
        return A;
    } else {
        isInverse = true;
        SquareMatrix B(A.sizeN_);
        for(int i = 0; i < A.sizeN_; i++) {
            for(int j = 0; j < A.sizeN_; j++) {
                SquareMatrix C(A.sizeN_ - 1);
                for(int m = 0; m < A.sizeN_; m++) {
                    for(int k = 0; k < A.sizeN_; k++) {
                        if(m < i && k < j) {
                            C.matrix_[m][k] = A.matrix_[m][k];
                        } else if(m < i && k > j) {
                            C.matrix_[m][k - 1] = A.matrix_[m][k];
                        } else if(m > i && k < j) {
                            C.matrix_[m - 1][k] = A.matrix_[m][k];
                        } else if(m > i && k > j) {
                            C.matrix_[m - 1][k - 1] = A.matrix_[m][k];
                        }
                    }
                }
                B.matrix_[i][j] = pow(-1, i + j) * det(C);
            }
        }
        return transpose(B) / det(A);
    }
}

bool SquareMatrix::operator==(SquareMatrix A) {
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            if(matrix_[i][j] != A.matrix_[i][j])
                return false;
    }
    return true;
}

bool SquareMatrix::operator!=(SquareMatrix A) {
    for(int i = 0; i < sizeN_; i++) {
        for(int j = 0; j < sizeN_; j++)
            if(matrix_[i][j] != A.matrix_[i][j])
                return true;
    }
    return false;
}