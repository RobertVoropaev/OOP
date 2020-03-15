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
    BigInteger(const char* input_str);

    friend std::ostream& operator<<(std::ostream& stream, BigInteger const& A);
    friend std::istream& operator>>(std::istream& stream, BigInteger& A);

    BigInteger& operator=(BigInteger const& A);

    int operator[](size_t index) const;
    int& operator[](size_t index);
    size_t getSize() const;
    bool getSign() const;

    BigInteger& operator+=(BigInteger const& A);
    BigInteger& operator-=(BigInteger const& A);
    BigInteger& operator*=(BigInteger const& A);
    BigInteger& operator/=(BigInteger const& A);
    BigInteger& operator%=(BigInteger const& A);

private:
    size_t                  size_;
    static const size_t     max_input_size_ = 256;

    int                     data_[max_input_size_];

    bool                    isSignPlus_;

    friend BigInteger del2_(BigInteger const& A);
    friend int compare_(BigInteger const& A, const BigInteger& B);
};

BigInteger operator+(BigInteger A, BigInteger const& B);
BigInteger operator-(BigInteger A, BigInteger const& B);
BigInteger operator*(BigInteger A, BigInteger const& B);
BigInteger operator/(BigInteger A, BigInteger const& B);
BigInteger operator%(BigInteger A, BigInteger const& B);

bool operator==(BigInteger const& A, BigInteger const& B);
bool operator!=(BigInteger const& A, BigInteger const& B);
bool operator<(BigInteger const& A, BigInteger const& B);
bool operator>(BigInteger const& A, BigInteger const& B);
bool operator<=(BigInteger const& A, BigInteger const& B);
bool operator>=(BigInteger const& A, BigInteger const& B);

BigInteger sqrt(BigInteger const& A);

#endif //DZ06_BIGINTEGER_H