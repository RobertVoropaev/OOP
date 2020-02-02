#include "BigInteger.h"
//����������� �� �����
BigInteger::BigInteger(long long a) {
	n = 0;
	for (int i = 0; i < 250; i++) m[i] = 0;
	if (a >= 0) signplus = true;//��������� �����
	else {
		signplus = false;
		a *= (-1);//���� �������������, �� ���������� ���� � ������ ��������� ����� ������� ��� ������
	}
	while (a != 0) { //������ ����� � ������
		m[n] = a%10;
		a /= 10;
		n++;
	}
}
//����������� �� ������
BigInteger::BigInteger(const char *st) {
	n = 0;
	for (int i = 0; i < 250; i++) m[i] = 0;
	int l = strlen(st); //����� �������� ������
	char str[250];
	for (int i = 0; i < l; i++) str[i] = st[i]; //������������ � ����� ������
	if (str[0] == '-' || str[0] == '+') {//���� ������ ���� �����, �� ���������� ��� � ������� �� ������
		if (str[0] == '-') signplus = false;
		else signplus = true;
		for (int i = 1; i < l; i++) {
			str[i - 1] = str[i];
		}
		l--;
	}
	else signplus = true;//���� ���� �� ������ - ����� �������������
	int u = 0; //���������� ����� ������� ��������� ������
	for (int i = 0; i < l; i++) {//������� ���������� �����
		if (str[i] == '0') u++;
		else break;
	}
	if (u == l) {//���� � ������ ���� ����, �������� ��� ����� 0
		signplus = true;
		m[0] = 0;
		n = 1;
	}
	else {//���� ���� ������ ������� ����� - ������� ��
		for (int i = u; i < l; i++) {
			str[i - u] = str[i];//�������� ������
		}
		l -= u;//��������� �����
		while (l) {//������ ����� � ������
			m[n] = str[l - 1] - '0';
			n++;
			l--;		
		}
	}
}
//����� �����
ostream& operator<<(ostream &stream, const BigInteger &A)
{
	if (!A.signplus) stream << '-'; //������� ����, ���� ����� ������������
	for (int i = A.n - 1; i >= 0; i--) stream << A.m[i];
	return stream;
}
//����� �� ������
istream& operator>>(istream &stream, BigInteger &A) {
	char str[250];// ������, � ������� ����� ������������ �������
	stream >> str; //���������� ��������
	BigInteger B(str);//
	A = B;
	return stream;
}

int compare(const BigInteger &A,const BigInteger &B) {
	if (A.n > B.n) return 1;//��������� ����� �����, ���� ��� �������� - ����� ������� ������� �����
	else if (A.n < B.n) return 2;
	else {
		for (int i = A.n - 1; i > -1; i--) { //��������� ����� �� �������� ������� 
			if (A.m[i]>B.m[i]) return 1;
			else if (B.m[i] > A.m[i]) return 2;
		}
		return 0;//���� �������� �� ������� - ����� ����������
	}
}
BigInteger BigInteger::operator=(const BigInteger &A) {
	signplus = A.signplus;
	n = A.n;
	for (int i = 0; i < 250; i++) {
		m[i] = A.m[i];
	}
	return *this;
}
BigInteger BigInteger::operator+(const BigInteger &A) const {
	BigInteger V;
	V.n = max(A.n, n);
	int r = 0;
	if ((A.signplus&&signplus) || ((!A.signplus) && (!signplus))) {//���� ����� ���������� - ������� ��� ����� �� ������ � ���������� � ������ ��� �� ���� 
		for (int i = 0; i < V.n; i++) {
			V.m[i] = m[i] + A.m[i] + r;
			if (V.m[i] >= 10) {
				r = 1;
				V.m[i] -= 10;
			}
			else r = 0;
		}
		if (r > 0) {
			V.n++;
			V.m[V.n - 1] = r;
		}
		if (!A.signplus&&!signplus) V.signplus = false;
	}
	else {//���� ����� ������ - ������� �� �������� ������� � ���������� ���� ��������
		int y = compare(*this, A);
		if (y == 1) {//���� ������ ������ �������
			V.n = n;
			int r = 0;
			for (int i = 0; i < V.n; i++) {
				V.m[i] = m[i] - A.m[i] - r;
				if (V.m[i] < 0) {
					r = 1;
					V.m[i] += 10;
				}
				else r = 0;
			}
			while (V.m[V.n - 1] == 0 && V.n > 1) V.n--;
			V.signplus = signplus;
		}
		else if (y == 2) {//���� ������ ������ �������
			V.n = A.n;
			int r = 0;
			for (int i = 0; i < V.n; i++) {
				V.m[i] = A.m[i] - m[i] - r;
				if (V.m[i] < 0) {
					r = 1;
					V.m[i] += 10;
				}
				else r = 0;
			}
			while (V.m[V.n - 1] == 0 && V.n > 1) V.n--;
			V.signplus = A.signplus;
		}
		else if (y == 0) {//����� ����� - ��������� ����
			V.n = 1;
			V.m[0] = 0;
		}
	}
	return V;
}
BigInteger BigInteger::operator-(const BigInteger &A) const {//�������� ���� ����������� �� ��������������� � ������������ ��� ��������
	BigInteger N1 = A;
	if (N1.signplus) N1.signplus = false;
	else N1.signplus = true;
	return *this + N1;
}
BigInteger BigInteger::operator+(long long a) const {
	BigInteger A(a);
	return *this + A;
}
BigInteger BigInteger::operator-(long long a) const {
	BigInteger A(a);
	return *this - A;
}
BigInteger operator+(long long a, const BigInteger &A) {
	BigInteger V(a);
	return V + A;
}
BigInteger operator-(long long a, const BigInteger &A) {
	BigInteger V(a);
	return V - A;
}