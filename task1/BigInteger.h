#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;
class BigInteger {
	bool signplus; 
	int m[250];
	int n;
public:
	BigInteger(long long a = 0);
	BigInteger(const char *st);
	friend ostream& operator<<(ostream &stream, const BigInteger &A);
	friend istream& operator>>(istream &stream, BigInteger &A);
	friend int compare(const BigInteger &A, const BigInteger &B);
	BigInteger operator=(const BigInteger &A);
	BigInteger operator=(long long a);
	BigInteger operator+(const BigInteger &A) const;
	BigInteger operator+(long long a) const;
	friend BigInteger operator+(long long a, const BigInteger &A);
	BigInteger operator+=(const BigInteger &A);
	BigInteger operator+=(long long a);
	BigInteger operator-(const BigInteger &A) const;
	BigInteger operator-(long long a) const;
	friend BigInteger operator-(long long a, const BigInteger &A);
	BigInteger operator-=(const BigInteger &A);
	BigInteger operator-=(long long a);
	BigInteger operator*(const BigInteger &A) const;
	BigInteger operator*(long long a) const;
	friend BigInteger operator*(long long a, const BigInteger &A);
	BigInteger operator*=(const BigInteger &A);
	BigInteger operator*=(long long a);
	BigInteger operator/(const BigInteger &A) const;
	BigInteger operator/(long long a) const;
	friend BigInteger operator/(long long a, const BigInteger &A);
	BigInteger operator/=(const BigInteger &A);
	BigInteger operator/=(long long a);
	bool operator==(const BigInteger &A) const;
	bool operator!=(const BigInteger &A) const;
	BigInteger operator%(const BigInteger &A) const;
	BigInteger operator%(long long a) const;
	friend BigInteger operator%(long long a, const BigInteger &A);
	BigInteger BigInteger::operator%=(const BigInteger &A);
	BigInteger BigInteger::operator%=(long long a);
	friend BigInteger sqrt(const BigInteger &A);
	friend BigInteger del2(const BigInteger &A);
};