#include "BigInteger.h"


BigInteger::BigInteger(long long a) {
    size_ = 0;
    for(int i = 0; i < 250; i++)
        arr_[i] = 0;
    if(a >= 0)
        isSignPlus_ = true;
    else {
        isSignPlus_ = false;
        a *= (-1);
    }
    while(a != 0) {
        arr_[size_] = a % 10;
        a /= 10;
        size_++;
    }
}

BigInteger::BigInteger(const char* st) {
    size_ = 0;
    for(int i = 0; i < 250; i++)
        arr_[i] = 0;
    int l = strlen(st);
    char str[250];
    for(int i = 0; i < l; i++)
        str[i] = st[i];
    if(str[0] == '-' || str[0] == '+') {
        isSignPlus_ = str[0] != '-';
        for(int i = 1; i < l; i++) {
            str[i - 1] = str[i];
        }
        l--;
    } else
        isSignPlus_ = true;
    int u = 0;
    for(int i = 0; i < l; i++) {
        if(str[i] == '0')
            u++;
        else
            break;
    }
    if(u == l) {
        isSignPlus_ = true;
        arr_[0] = 0;
        size_ = 1;
    } else {
        for(int i = u; i < l; i++) {
            str[i - u] = str[i];
        }
        l -= u;
        while(l) {
            arr_[size_] = str[l - 1] - '0';
            size_++;
            l--;
        }
    }
}


ostream& operator<<(ostream& stream, const BigInteger& A) {
    if(!A.isSignPlus_)
        stream << '-';
    for(int i = A.size_ - 1; i >= 0; i--)
        stream << A.arr_[i];
    return stream;
}


istream& operator>>(istream& stream, BigInteger& A) {
    char str[250];
    stream >> str;
    BigInteger B(str);
    A = B;
    return stream;
}


int compare(const BigInteger& A, const BigInteger& B) {
    if(A.size_ > B.size_)
        return 1;
    else if(A.size_ < B.size_)
        return 2;
    else {
        for(int i = A.size_ - 1; i > -1; i--) {
            if(A.arr_[i] > B.arr_[i])
                return 1;
            else if(B.arr_[i] > A.arr_[i])
                return 2;
        }
        return 0;
    }
}


BigInteger& BigInteger::operator=(const BigInteger& A) {
    isSignPlus_ = A.isSignPlus_;
    size_ = A.size_;
    for(int i = 0; i < 250; i++) {
        arr_[i] = A.arr_[i];
    }
    return *this;
}

BigInteger& BigInteger::operator=(long long a) {
    BigInteger A(a);
    *this = A;
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger& A) const {
    BigInteger V;
    V.size_ = max(A.size_, size_);
    int r = 0;
    if((A.isSignPlus_ && isSignPlus_) || ((!A.isSignPlus_) && (!isSignPlus_))) {
        for(int i = 0; i < V.size_; i++) {
            V.arr_[i] = arr_[i] + A.arr_[i] + r;
            if(V.arr_[i] >= 10) {
                r = 1;
                V.arr_[i] -= 10;
            } else
                r = 0;
        }
        if(r > 0) {
            V.size_++;
            V.arr_[V.size_ - 1] = r;
        }
        if(!A.isSignPlus_ && !isSignPlus_)
            V.isSignPlus_ = false;
    } else {
        int y = compare(*this, A);
        if(y == 1) {
            V.size_ = size_;
            int r = 0;
            for(int i = 0; i < V.size_; i++) {
                V.arr_[i] = arr_[i] - A.arr_[i] - r;
                if(V.arr_[i] < 0) {
                    r = 1;
                    V.arr_[i] += 10;
                } else
                    r = 0;
            }
            while(V.arr_[V.size_ - 1] == 0 && V.size_ > 1)
                V.size_--;
            V.isSignPlus_ = isSignPlus_;
        } else if(y == 2) {
            V.size_ = A.size_;
            int r = 0;
            for(int i = 0; i < V.size_; i++) {
                V.arr_[i] = A.arr_[i] - arr_[i] - r;
                if(V.arr_[i] < 0) {
                    r = 1;
                    V.arr_[i] += 10;
                } else
                    r = 0;
            }
            while(V.arr_[V.size_ - 1] == 0 && V.size_ > 1)
                V.size_--;
            V.isSignPlus_ = A.isSignPlus_;
        } else if(y == 0) {
            V.size_ = 1;
            V.arr_[0] = 0;
        }
    }
    return V;
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

BigInteger BigInteger::operator-(
        const BigInteger& A) const {
    BigInteger N1 = A;
    N1.isSignPlus_ = !N1.isSignPlus_;
    return *this + N1;
}

BigInteger BigInteger::operator-(long long a) const {
    BigInteger A(a);
    return *this - A;
}

BigInteger operator-(long long a, const BigInteger& A) {
    BigInteger V(a);
    return V - A;
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

BigInteger BigInteger::operator*(const BigInteger& A) const {
    BigInteger C;
    C.size_ = size_ + A.size_ + 1;
    for(int i = 0; i < size_; i++)
        for(int j = 0; j < A.size_; j++)
            C.arr_[i + j] += arr_[i] * A.arr_[j];
    for(int i = 0; i < C.size_; i++) {
        C.arr_[i + 1] += C.arr_[i] / 10;
        C.arr_[i] %= 10;
    }
    while(C.arr_[C.size_ - 1] == 0 && C.size_ > 1)
        C.size_--;
    return C;
}

BigInteger BigInteger::operator*(long long a) const {
    BigInteger C(a);
    return *this * C;
}

BigInteger operator*(long long a, const BigInteger& A) {
    BigInteger C(a);
    return C * A;
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

BigInteger BigInteger::operator/(const BigInteger& A) const {
    BigInteger L("0"), R(1), M;
    while(compare(A * R, *this) == 2)
        R = R * 2;
    BigInteger I("1"), O("0");
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

bool BigInteger::operator==(const BigInteger& A) const {
    if(A.size_ != size_)
        return false;
    for(int i = 0; i < size_; i++) {
        if(A.arr_[i] != arr_[i])
            return false;
    }
    return true;
}

bool BigInteger::operator!=(const BigInteger& A) const {
    return !(*this == A);
}

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

BigInteger del2_(const BigInteger& A) {
    BigInteger B;
    B.size_ = A.size_;
    int ost = 0, r = 0;
    for(int i = A.size_ - 1; i >= 0; i--) {
        r = ost * 10 + A.arr_[i];
        B.arr_[i] = r / 2;
        ost = r % 2;
    }
    if(B.arr_[B.size_ - 1] == 0)
        B.size_--;
    return B;
}