#include "SquareMatrix.h"
SquareMatrix SquareMatrix::operator=(const SquareMatrix &A) {
	if (sizeN != A.sizeN) exit(1);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) matrix[i][j] = A.matrix[i][j];
	}
	return *this;
}
SquareMatrix SquareMatrix::operator+(const SquareMatrix &A) const{
	if (sizeN != A.sizeN) exit(2);
	SquareMatrix B(sizeN);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) B.matrix[i][j] = matrix[i][j] + A.matrix[i][j];
	}
	return B;
}
SquareMatrix SquareMatrix::operator+=(const SquareMatrix &A) {
	if (sizeN != A.sizeN) exit(3);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) matrix[i][j] += A.matrix[i][j];
	}
	return *this;
}
SquareMatrix SquareMatrix::operator*(double a) const{
	SquareMatrix B(sizeN);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) B.matrix[i][j] = matrix[i][j] * a;
	}
	return B;
}
SquareMatrix SquareMatrix::operator*=(double a) {
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) matrix[i][j] *= a;
	}
	return *this;
}
SquareMatrix SquareMatrix::operator/(double a) const{
	if (a == 0) exit(4);
	SquareMatrix B(sizeN);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) B.matrix[i][j] = matrix[i][j] / a;
	}
	return B;
}
SquareMatrix SquareMatrix::operator/=(double a) {
	if (a == 0) exit(5);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) matrix[i][j] /= a;
	}
	return *this;
}
SquareMatrix operator*(double a, const SquareMatrix &A) {
	for (int i = 0; i < A.sizeN; i++) {
		for (int j = 0; j < A.sizeN; j++) A.matrix[i][j] *= a;
	}
	return A;
}
SquareMatrix SquareMatrix::operator*(const SquareMatrix &A) const{
	if (sizeN != A.sizeN) exit(6);
	SquareMatrix B(sizeN);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++)
			for (int k = 0; k < sizeN; k++) {
				B.matrix[i][j] += (matrix[i][k] * A.matrix[k][j]);
			}
	}
	return B;
}
SquareMatrix SquareMatrix::operator*=(const SquareMatrix &A) {
	if (sizeN != A.sizeN) exit(7);
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++)
			for (int k = 0; k < sizeN; k++) {
				matrix[i][k] += A.matrix[k][j];
			}
	}
	return *this;
}
double SquareMatrix::operator()(int a, int b) const{
	if (a > sizeN || b > sizeN) exit(8);
	return matrix[a - 1][b - 1];
}
SquareMatrix tran(const SquareMatrix &A) {
	SquareMatrix B(A.sizeN);
	for (int i = 0; i < A.sizeN; i++) {
		for (int j = 0; j < A.sizeN; j++) {
			B.matrix[j][i] = A.matrix[i][j];
		}
	}
	return B;
}
ostream& operator<<(ostream &stream, const SquareMatrix &A) {
	for (int i = 0; i < A.sizeN; i++) {
		for (int j = 0; j < A.sizeN; j++) stream << A.matrix[i][j] << " ";
		stream << endl;
	}
	return stream;
}
istream& operator>>(istream& stream, SquareMatrix &A) {
	for (int i = 0; i < A.sizeN; i++) {
		for (int j = 0; j < A.sizeN; j++) stream >> A.matrix[i][j];
	}
	return stream;
}
double det(const SquareMatrix &A) {
	if (A.sizeN == 2) return A.matrix[0][0] * A.matrix[1][1] - A.matrix[0][1] * A.matrix[1][0];
	else {
		double Det = 0;
		for (int i = 0; i < A.sizeN; i++) {
			SquareMatrix B(A.sizeN - 1);
			for (int j = 1; j < A.sizeN; j++) {
				for (int k = 0; k < A.sizeN; k++) {
					if (k < i) B.matrix[j - 1][k] = A.matrix[j][k];
					else if (k > i) B.matrix[j - 1][k - 1] = A.matrix[j][k];
				}
			}
			Det += pow(-1, i)*A.matrix[0][i] * det(B);
		}
		return Det;
	}
}
SquareMatrix inverse(const SquareMatrix &A, bool &noinverse) {
	if (det(A) == 0) {
		noinverse = true;
		return A;
	}
	else {
		SquareMatrix B(A.sizeN);
		for (int i = 0; i < A.sizeN; i++) {
			for (int j = 0; j < A.sizeN; j++) {
				SquareMatrix C(A.sizeN - 1);
				for (int m = 0; m < A.sizeN; m++) {
					for (int k = 0; k < A.sizeN; k++) {
						if (m < i && k < j) C.matrix[m][k] = A.matrix[m][k];
						else if (m < i && k > j) C.matrix[m][k - 1] = A.matrix[m][k];
						else if (m > i && k < j) C.matrix[m - 1][k] = A.matrix[m][k];
						else if (m > i&& k > j) C.matrix[m - 1][k - 1] = A.matrix[m][k];
					}
				}
				B.matrix[i][j] = pow(-1, i + j)*det(C);
			}
		}
		noinverse = false;
		return tran(B)/det(A);
	}
}
bool SquareMatrix::operator==(const SquareMatrix &A) const{
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) if (matrix[i][j] != A.matrix[i][j]) return false;
	}
	return true;
}
bool SquareMatrix::operator!=(const SquareMatrix &A) const{
	for (int i = 0; i < sizeN; i++) {
		for (int j = 0; j < sizeN; j++) if (matrix[i][j] != A.matrix[i][j]) return true;
	}
	return false;
}