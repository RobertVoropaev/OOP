//
// Created by RobertVoropaev on 29.03.2016.
//

#ifndef DZ06_BIGINTEGER_H
#define DZ06_BIGINTEGER_H

#include <iostream>
#include <cstring>
#include <algorithm>

class BigInteger {
public:
    BigInteger(long long a = 0);
    BigInteger(const char* st);

    friend std::ostream& operator<<(std::ostream& stream, const BigInteger& A);
    friend std::istream& operator>>(std::istream& stream, BigInteger& A);

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

    friend int compare(const BigInteger& A, const BigInteger& B);
    bool operator==(const BigInteger& A) const;
    bool operator!=(const BigInteger& A) const;

    BigInteger operator%(const BigInteger& A) const;
    BigInteger operator%(long long a) const;
    friend BigInteger operator%(long long a, const BigInteger& A);
    BigInteger operator%=(const BigInteger& A);
    BigInteger operator%=(long long a);

    friend BigInteger sqrt(const BigInteger& A);
private:
    int     data_[250];
    int     size_;
    bool    isSignPlus_;

    friend BigInteger del2_(const BigInteger& A);
};

#endif //DZ06_BIGINTEGER_H