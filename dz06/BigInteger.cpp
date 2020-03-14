//
// Created by RobertVoropaev on 29.03.2016.
//

#include "BigInteger.h"

///////////////////////////// Constructors //////////////////////////////

BigInteger::BigInteger(long long a) {
    size_ = 0;
    for(int i = 0; i < 250; i++)
        data_[i] = 0;
    if(a >= 0)
        isSignPlus_ = true;
    else {
        isSignPlus_ = false;
        a *= (-1);
    }
    while(a != 0) {
        data_[size_] = a % 10;
        a /= 10;
        size_++;
    }
}

BigInteger::BigInteger(const char* st) {
    size_ = 0;
    for(int i = 0; i < 250; i++)
        data_[i] = 0;
    int len = strlen(st);
    char str[250];
    for(int i = 0; i < len; i++)
        str[i] = st[i];
    if(str[0] == '-' || str[0] == '+') {
        isSignPlus_ = str[0] != '-';
        for(int i = 1; i < len; i++) {
            str[i - 1] = str[i];
        }
        len--;
    } else
        isSignPlus_ = true;
    int u = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == '0')
            u++;
        else
            break;
    }
    if(u == len) {
        isSignPlus_ = true;
        data_[0] = 0;
        size_ = 1;
    } else {
        for(int i = u; i < len; i++) {
            str[i - u] = str[i];
        }
        len -= u;
        while(len) {
            data_[size_] = str[len - 1] - '0';
            size_++;
            len--;
        }
    }
}

///////////////////////////// Streams //////////////////////////////

std::ostream& operator<<(std::ostream& stream, const BigInteger& A) {
    if(!A.isSignPlus_)
        stream << '-';
    for(int i = A.size_ - 1; i >= 0; i--)
        stream << A.data_[i];
    return stream;
}


std::istream& operator>>(std::istream& stream, BigInteger& A) {
    char str[250];
    stream >> str;
    BigInteger B(str);
    A = B;
    return stream;
}

///////////////////////////// Opeartor = //////////////////////////////

BigInteger& BigInteger::operator=(const BigInteger& A) {
    isSignPlus_ = A.isSignPlus_;
    size_ = A.size_;
    for(int i = 0; i < 250; i++) {
        data_[i] = A.data_[i];
    }
    return *this;
}

BigInteger& BigInteger::operator=(long long a) {
    BigInteger A(a);
    *this = A;
    return *this;
}

///////////////////////////// Operator + //////////////////////////////

BigInteger BigInteger::operator+(const BigInteger& A) const {
    BigInteger B;
    B.size_ = std::max(A.size_, size_);
    int r = 0;
    if((A.isSignPlus_ && isSignPlus_) || ((!A.isSignPlus_) && (!isSignPlus_))) {
        for(int i = 0; i < B.size_; i++) {
            B.data_[i] = data_[i] + A.data_[i] + r;
            if(B.data_[i] >= 10) {
                r = 1;
                B.data_[i] -= 10;
            } else
                r = 0;
        }
        if(r > 0) {
            B.size_++;
            B.data_[B.size_ - 1] = r;
        }
        if(!A.isSignPlus_ && !isSignPlus_)
            B.isSignPlus_ = false;
    } else {
        int y = compare(*this, A);
        if(y == 1) {
            B.size_ = size_;
            int r = 0;
            for(int i = 0; i < B.size_; i++) {
                B.data_[i] = data_[i] - A.data_[i] - r;
                if(B.data_[i] < 0) {
                    r = 1;
                    B.data_[i] += 10;
                } else
                    r = 0;
            }
            while(B.data_[B.size_ - 1] == 0 && B.size_ > 1)
                B.size_--;
            B.isSignPlus_ = isSignPlus_;
        } else if(y == 2) {
            B.size_ = A.size_;
            int r = 0;
            for(int i = 0; i < B.size_; i++) {
                B.data_[i] = A.data_[i] - data_[i] - r;
                if(B.data_[i] < 0) {
                    r = 1;
                    B.data_[i] += 10;
                } else
                    r = 0;
            }
            while(B.data_[B.size_ - 1] == 0 && B.size_ > 1)
                B.size_--;
            B.isSignPlus_ = A.isSignPlus_;
        } else if(y == 0) {
            B.size_ = 1;
            B.data_[0] = 0;
        }
    }
    return B;
}

BigInteger BigInteger::operator+(long long a) const {
    BigInteger A(a);
    return *this + A;
}

BigInteger operator+(long long a, const BigInteger& A) {
    BigInteger V(a);
    return V + A;
}

BigInteger BigInteger::operator+=(const BigInteger& A) {
    *this = *this + A;
    return *this;
}

BigInteger BigInteger::operator+=(long long a) {
    BigInteger A(a);
    *this = *this + A;
    return *this;
}

///////////////////////////// Operator - //////////////////////////////

BigInteger BigInteger::operator-(const BigInteger& A) const {
    BigInteger N1 = A;
    N1.isSignPlus_ = !N1.isSignPlus_;
    return *this + N1;
}

BigInteger BigInteger::operator-(long long a) const {
    BigInteger A(a);
    return *this - A;
}

BigInteger operator-(long long a, const BigInteger& A) {
    BigInteger B(a);
    return B - A;
}

BigInteger BigInteger::operator-=(const BigInteger& A) {
    *this = *this - A;
    return *this;
}

BigInteger BigInteger::operator-=(long long a) {
    BigInteger A(a);
    *this = *this - A;
    return *this;
}

///////////////////////////// Operator * //////////////////////////////

BigInteger BigInteger::operator*(const BigInteger& A) const {
    BigInteger B;
    B.size_ = size_ + A.size_ + 1;
    for(int i = 0; i < size_; i++)
        for(int j = 0; j < A.size_; j++)
            B.data_[i + j] += data_[i] * A.data_[j];
    for(int i = 0; i < B.size_; i++) {
        B.data_[i + 1] += B.data_[i] / 10;
        B.data_[i] %= 10;
    }
    while(B.data_[B.size_ - 1] == 0 && B.size_ > 1)
        B.size_--;
    return B;
}

BigInteger BigInteger::operator*(long long a) const {
    BigInteger A(a);
    return *this * A;
}

BigInteger operator*(long long a, const BigInteger& A) {
    BigInteger B(a);
    return B * A;
}

BigInteger BigInteger::operator*=(const BigInteger& A) {
    *this = *this * A;
    return *this;
}

BigInteger BigInteger::operator*=(long long a) {
    BigInteger A(a);
    *this = *this * A;
    return *this;
}

///////////////////////////// Operator / //////////////////////////////

BigInteger BigInteger::operator/(const BigInteger& A) const {
    BigInteger L("0");
    BigInteger R(1);
    while(compare(A * R, *this) == 2) {
        R = R * 2;
    }
    
    BigInteger I("1"), O("0");
    BigInteger M;
    while((R - L) != I && (R - L) != O) {
        M = del2_(L + R);
        if(compare(A * M, *this) == 2) {
            L = M;
        } else {
            R = M;
        }
    }
    if(R * A == *this)
        return R;
    else
        return L;
}

BigInteger BigInteger::operator/(long long a) const {
    BigInteger A(a);
    return *this / A;
}

BigInteger operator/(long long a, const BigInteger& A) {
    BigInteger B(a);
    return B / A;
}

BigInteger BigInteger::operator/=(const BigInteger& A) {
    *this = *this / A;
    return *this;
}

BigInteger BigInteger::operator/=(long long a) {
    BigInteger A(a);
    *this = *this / A;
    return *this;
}

///////////////////////////// Compare //////////////////////////////

int compare(const BigInteger& A, const BigInteger& B) {
    if(A.size_ > B.size_)
        return 1;
    else if(A.size_ < B.size_)
        return 2;
    else {
        for(int i = A.size_ - 1; i > -1; i--) {
            if(A.data_[i] > B.data_[i])
                return 1;
            else if(B.data_[i] > A.data_[i])
                return 2;
        }
        return 0;
    }
}

bool BigInteger::operator==(const BigInteger& A) const {
    if(A.size_ != size_)
        return false;
    for(int i = 0; i < size_; i++) {
        if(A.data_[i] != data_[i])
            return false;
    }
    return true;
}

bool BigInteger::operator!=(const BigInteger& A) const {
    return !(*this == A);
}

///////////////////////////// Operator % //////////////////////////////

BigInteger BigInteger::operator%(const BigInteger& A) const {
    return *this - A * (*this / A);
}

BigInteger BigInteger::operator%(long long a) const {
    BigInteger A(a);
    return *this - A * (*this / A);
}

BigInteger operator%(long long a, const BigInteger& A) {
    BigInteger B(a);
    return B - A * (B / A);
}

BigInteger BigInteger::operator%=(const BigInteger& A) {
    *this = *this % A;
    return *this;
}

BigInteger BigInteger::operator%=(long long a) {
    BigInteger A(a);
    *this = *this % A;
    return *this;
}

///////////////////////////// Sqrt //////////////////////////////

BigInteger sqrt(const BigInteger& A) {
    BigInteger L("0"), R(1), M;
    while(compare(R * R, A) == 2)
        R = R * 2;
    BigInteger I("1"), O("0");
    while((R - L) != I && (R - L) != O) {
        M = del2_(L + R);
        if(compare(M * M, A) == 2) {
            L = M;
        } else {
            R = M;
        }
    }
    if(R * R == A)
        return R;
    else
        return L;
}

///////////////////////////// Extra //////////////////////////////

//for binary search
BigInteger del2_(const BigInteger& A) {
    BigInteger B;
    B.size_ = A.size_;
    int ost = 0, r = 0;
    for(int i = A.size_ - 1; i >= 0; i--) {
        r = ost * 10 + A.data_[i];
        B.data_[i] = r / 2;
        ost = r % 2;
    }
    if(B.data_[B.size_ - 1] == 0)
        B.size_--;
    return B;
}