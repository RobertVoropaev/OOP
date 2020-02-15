#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class BigInteger {
public:
    BigInteger();
    BigInteger(long long a);
    BigInteger(const char* st);

    friend ostream& operator<<(ostream& stream, const BigInteger& A);
    friend istream& operator>>(istream& stream, BigInteger& A);

    BigInteger& operator=(const BigInteger& A);

    BigInteger operator+(const BigInteger& A) const;
    BigInteger operator+(long long a) const;

    BigInteger operator-(const BigInteger& A) const;
    BigInteger operator-(long long a) const;

    friend BigInteger operator+(long long a, const BigInteger& A);
    friend BigInteger operator-(long long a, const BigInteger& A);

    friend int compare(const BigInteger& A, const BigInteger& B);
private:
    bool isSignPlus_;
    int numberArray_[250];
    int size_;
};