#include "BigInteger.h"

BigInteger::BigInteger(){
    BigInteger((long long) 0);
}


BigInteger::BigInteger(long long a) {
    size_ = 0;
    for(int i = 0; i < 250; i++)
        numberArray_[i] = 0;
    if(a >= 0)
        isSignPlus_ = true;
    else {
        isSignPlus_ = false;
        a *= (-1);
    }
    while(a != 0) {
        numberArray_[size_] = a % 10;
        a /= 10;
        size_++;
    }
}

BigInteger::BigInteger(const char* st) {
    size_ = 0;
    for(int i = 0; i < 250; i++)
        numberArray_[i] = 0;
    int l = strlen(st);
    char str[250];
    for(int i = 0; i < l; i++)
        str[i] = st[i];
    if(str[0] == '-' || str[0] == '+') {
        if(str[0] == '-')
            isSignPlus_ = false;
        else
            isSignPlus_ = true;
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
        numberArray_[0] = 0;
        size_ = 1;
    } else {

        for(int i = u; i < l; i++) {
            str[i - u] = str[i];
        }
        l -= u;
        while(l) {
            numberArray_[size_] = str[l - 1] - '0';
            size_++;
            l--;
        }
    }
}

ostream& operator<<(ostream& stream, const BigInteger& A) {
    if(!A.isSignPlus_)
        stream << '-';
    for(int i = A.size_ - 1; i >= 0; i--)
        stream << A.numberArray_[i];
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
            if(A.numberArray_[i] > B.numberArray_[i])
                return 1;
            else if(B.numberArray_[i] > A.numberArray_[i])
                return 2;
        }
        return 0;
    }
}

BigInteger& BigInteger::operator=(const BigInteger& A) {
    isSignPlus_ = A.isSignPlus_;
    size_ = A.size_;
    for(int i = 0; i < 250; i++) {
        numberArray_[i] = A.numberArray_[i];
    }
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger& A) const {
    BigInteger V;
    V.size_ = max(A.size_, size_);
    int r = 0;
    if((A.isSignPlus_ && isSignPlus_) || ((!A.isSignPlus_) && (!isSignPlus_))) {
        for(int i = 0; i < V.size_; i++) {
            V.numberArray_[i] = numberArray_[i] + A.numberArray_[i] + r;
            if(V.numberArray_[i] >= 10) {
                r = 1;
                V.numberArray_[i] -= 10;
            } else
                r = 0;
        }
        if(r > 0) {
            V.size_++;
            V.numberArray_[V.size_ - 1] = r;
        }
        if(!A.isSignPlus_ && !isSignPlus_)
            V.isSignPlus_ = false;
    } else {
        int y = compare(*this, A);
        if(y == 1) {
            V.size_ = size_;
            r = 0;
            for(int i = 0; i < V.size_; i++) {
                V.numberArray_[i] = numberArray_[i] - A.numberArray_[i] - r;
                if(V.numberArray_[i] < 0) {
                    r = 1;
                    V.numberArray_[i] += 10;
                } else
                    r = 0;
            }
            while(V.numberArray_[V.size_ - 1] == 0 && V.size_ > 1)
                V.size_--;
            V.isSignPlus_ = isSignPlus_;
        } else if(y == 2) {
            V.size_ = A.size_;
            int r = 0;
            for(int i = 0; i < V.size_; i++) {
                V.numberArray_[i] = A.numberArray_[i] - numberArray_[i] - r;
                if(V.numberArray_[i] < 0) {
                    r = 1;
                    V.numberArray_[i] += 10;
                } else
                    r = 0;
            }
            while(V.numberArray_[V.size_ - 1] == 0 && V.size_ > 1)
                V.size_--;
            V.isSignPlus_ = A.isSignPlus_;
        } else if(y == 0) {
            V.size_ = 1;
            V.numberArray_[0] = 0;
        }
    }
    return V;
}

BigInteger BigInteger::operator-(const BigInteger& A) const {
    BigInteger N1 = A;
    N1.isSignPlus_ = !N1.isSignPlus_;
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

BigInteger operator+(long long a, const BigInteger& A) {
    BigInteger V(a);
    return V + A;
}

BigInteger operator-(long long a, const BigInteger& A) {
    BigInteger V(a);
    return V - A;
}