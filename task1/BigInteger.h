#pragma once

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class BigInteger {
public:
    BigInteger(long long a = 0);
    BigInteger(const char* st);

    friend ostream& operator<<(ostream& stream, const BigInteger& A);
    friend istream& operator>>(istream& stream, BigInteger& A);
    friend int compare(const BigInteger& A, const BigInteger& B);

    BigInteger& operator=(const BigInteger& A);
    BigInteger& operator=(long long a);

    BigInteger operator+(const BigInteger& A) const;
    BigInteger operator+(long long a) const;
    friend BigInteger operator+(long long a, const BigInteger& A);
    BigInteger operator+=(const BigInteger& A);
    BigInteger operator+=(long long a);

    BigInteger operator-(const BigInteger& A) const;
    BigInteger operator-(long long a) const;
    friend BigInteger operator-(long long a, const BigInteger& A);
    BigInteger operator-=(const BigInteger& A);
    BigInteger operator-=(long long a);

    BigInteger operator*(const BigInteger& A) const;
    BigInteger operator*(long long a) const;
    friend BigInteger operator*(long long a, const BigInteger& A);
    BigInteger operator*=(const BigInteger& A);
    BigInteger operator*=(long long a);

    BigInteger operator/(const BigInteger& A) const;
    BigInteger operator/(long long a) const;
    friend BigInteger operator/(long long a, const BigInteger& A);
    BigInteger operator/=(const BigInteger& A);
    BigInteger operator/=(long long a);

    bool operator==(const BigInteger& A) const;
    bool operator!=(const BigInteger& A) const;

    BigInteger operator%(const BigInteger& A) const;
    BigInteger operator%(long long a) const;
    friend BigInteger operator%(long long a, const BigInteger& A);
    BigInteger BigInteger::operator%=(const BigInteger& A);
    BigInteger BigInteger::operator%=(long long a);

    friend BigInteger sqrt(const BigInteger& A);
private:
    bool isSignPlus_;
    int arr_[250]{};
    int size_;
    friend BigInteger del2_(const BigInteger& A);
};