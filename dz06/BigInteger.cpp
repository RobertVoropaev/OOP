//
// Created by RobertVoropaev on 29.03.2016.
//

#include "BigInteger.h"

///////////////////////////// Constructors //////////////////////////////

BigInteger::BigInteger(long long a) {
    if(a >= 0) {
        isSignPlus_ = true;
    }
    else {
        isSignPlus_ = false;
        a *= (-1);
    }

    for(int& i : data_) {
        i = 0;
    }

    size_ = 0;
    while(a != 0) {
        data_[size_] = a % 10;
        a /= 10;
        size_++;
    }
}

BigInteger::BigInteger(const char* input_str) {
    size_ = 0;

    for(int& i : data_) {
        i = 0;
    }

    size_t len = strlen(input_str);
    char str[max_input_size_];
    strcpy(str, input_str);

    if(str[0] == '-' || str[0] == '+') {
        isSignPlus_ = str[0] != '-';
        for(int i = 1; i < len; i++) {
            str[i - 1] = str[i];
        }
        len--;
    }
    else {
        isSignPlus_ = true;
    }

    int first_non_null_char = 0;
    while(str[first_non_null_char] == '0') {
        first_non_null_char++;
    }

    if(first_non_null_char == len) {
        isSignPlus_ = true;
        data_[0] = 0;
        size_ = 1;
    }
    else {
        for(int i = first_non_null_char; i < len; i++) {
            str[i - first_non_null_char] = str[i];
        }

        len -= first_non_null_char;
        while(len) {
            data_[size_] = str[len - 1] - '0';
            size_++;
            len--;
        }
    }
}

///////////////////////////// Streams //////////////////////////////

std::ostream& operator<<(std::ostream& stream, BigInteger const& A) {
    if(!A.isSignPlus_) {
        stream << '-';
    }

    for(int i = A.size_ - 1; i >= 0; i--) {
        stream << A.data_[i];
    }
    return stream;
}


std::istream& operator>>(std::istream& stream, BigInteger& A) {
    char str[BigInteger::max_input_size_];
    stream >> str;

    A = BigInteger(str);
    return stream;
}

///////////////////////////// Opeartor = //////////////////////////////

BigInteger& BigInteger::operator=(BigInteger const& A) {
    isSignPlus_ = A.isSignPlus_;
    size_ = A.size_;
    for(int i = 0; i < max_input_size_; i++) {
        data_[i] = A.data_[i];
    }
    return *this;
}

///////////////////////////// Getters //////////////////////////////

int BigInteger::operator[](size_t index) const {
    return data_[size_ - index - 1];
}

int& BigInteger::operator[](size_t index) {
    return data_[size_ - index - 1];
}

size_t BigInteger::getSize() const {
    return size_;
}

bool BigInteger::getSign() const {
    return isSignPlus_;
}

///////////////////////////// Operator + //////////////////////////////

BigInteger& BigInteger::operator+=(BigInteger const& A) {
    BigInteger B;
    B.size_ = std::max(A.size_, size_);

    int r = 0;
    if((A.isSignPlus_ && isSignPlus_) || ((!A.isSignPlus_) && (!isSignPlus_))) {
        for(int i = 0; i < B.size_; i++) {
            B.data_[i] = data_[i] + A.data_[i] + r;
            if(B.data_[i] >= 10) {
                r = 1;
                B.data_[i] -= 10;
            }
            else {
                r = 0;
            }
        }

        if(r > 0) {
            B.size_++;
            B.data_[B.size_ - 1] = r;
        }

        if(!A.isSignPlus_ && !isSignPlus_) {
            B.isSignPlus_ = false;
        }
    } else {
        int y = compare_(*this, A);
        if(y == 1) {
            B.size_ = size_;

            r = 0;
            for(int i = 0; i < B.size_; i++) {
                B.data_[i] = data_[i] - A.data_[i] - r;
                if(B.data_[i] < 0) {
                    r = 1;
                    B.data_[i] += 10;
                }
                else {
                    r = 0;
                }
            }

            while(B.data_[B.size_ - 1] == 0 && B.size_ > 1) {
                B.size_--;
            }

            B.isSignPlus_ = isSignPlus_;
        }
        else if(y == 2) {
            B.size_ = A.size_;
            r = 0;

            for(int i = 0; i < B.size_; i++) {
                B.data_[i] = A.data_[i] - data_[i] - r;
                if(B.data_[i] < 0) {
                    r = 1;
                    B.data_[i] += 10;
                }
                else {
                    r = 0;
                }
            }

            while(B.data_[B.size_ - 1] == 0 && B.size_ > 1) {
                B.size_--;
            }

            B.isSignPlus_ = A.isSignPlus_;
        }
        else if(y == 0) {
            B.size_ = 1;
            B.data_[0] = 0;
        }
    }
    return *this = B;
}

BigInteger operator+(BigInteger A, BigInteger const& B) {
    return A += B;
}

///////////////////////////// Operator - //////////////////////////////

BigInteger& BigInteger::operator-=(BigInteger const& A) {
    BigInteger inv_A = A;
    inv_A.isSignPlus_ = !A.isSignPlus_;
    return *this += inv_A;
}

BigInteger operator-(BigInteger A, BigInteger const& B) {
    return A -= B;
}

///////////////////////////// Operator * //////////////////////////////

BigInteger& BigInteger::operator*=(BigInteger const& A) {
    BigInteger B;
    B.size_ = size_ + A.size_ + 1;
    B.isSignPlus_ = (this->isSignPlus_ == A.isSignPlus_);

    for(int i = 0; i < size_; i++) {
        for(int j = 0; j < A.size_; j++) {
            B.data_[i + j] += data_[i] * A.data_[j];
        }
    }

    for(int i = 0; i < B.size_; i++) {
        B.data_[i + 1] += B.data_[i] / 10;
        B.data_[i] %= 10;
    }

    while(B.data_[B.size_ - 1] == 0 && B.size_ > 1) {
        B.size_--;
    }

    return *this = B;
}

BigInteger operator*(BigInteger A, BigInteger const& B) {
    return A *= B;
}

///////////////////////////// Operator / //////////////////////////////

BigInteger& BigInteger::operator/=(BigInteger const& A) {
    BigInteger Left("0"), Right("1");
    while(A * Right < *this) {
        Right *= 2;
    }

    BigInteger I("1"), O("0");
    BigInteger Middle;
    while((Right - Left) != I && (Right - Left) != O) {
        Middle = del2_(Left + Right);
        if(A * Middle < *this) {
            Left = Middle;
        }
        else {
            Right = Middle;
        }
    }

    if(Right * A == *this)
        return *this = Right;
    else
        return *this = Left;
}

BigInteger operator/(BigInteger A, BigInteger const& B) {
    return A /= B;
}

///////////////////////////// Operator % //////////////////////////////

BigInteger& BigInteger::operator%=(BigInteger const& A) {
    *this -= A * (*this / A);
    return *this;
}

BigInteger operator%(BigInteger A, BigInteger const& B) {
    return A %= B;
}

///////////////////////////// Sqrt //////////////////////////////

BigInteger sqrt(BigInteger const& A) {
    BigInteger L("0"), R(1), M;
    while(R * R < A) {
        R = R * 2;
    }
    BigInteger I("1"), O("0");
    while((R - L) != I && (R - L) != O) {
        M = del2_(L + R);
        if(M * M < A) {
            L = M;
        }
        else {
            R = M;
        }
    }
    if(R * R == A) {
        return R;
    } else {
        return L;
    }
}

///////////////////////////// Compare //////////////////////////////

bool operator==(BigInteger const& A, BigInteger const& B) {
    if(A.getSize() != B.getSize()) {
        return false;
    }

    if(A.getSign() != B.getSign()) {
        return false;
    }

    for(int i = 0; i < A.getSize(); i++) {
        if(A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(BigInteger const& A, BigInteger const& B) {
    return !(A == B);
}

bool operator<(BigInteger const& A, BigInteger const& B) {
    if(A.getSign() != A.getSize()) {
        return !A.getSign();
    }

    if(A.getSign()) {
        if(A.getSize() < B.getSize()) {
            return true;
        }
        else if(A.getSize() > B.getSize()) {
            return false;
        }

        for(int i = 0; i < A.getSize(); i++) {
            if(A[i] >= B[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        if(A.getSize() > B.getSize()) {
            return true;
        }
        else if(A.getSize() < B.getSize()) {
            return false;
        }

        for(int i = 0; i < A.getSize(); i++) {
            if(A[i] <= B[i]) {
                return false;
            }
        }
        return true;
    }
}

bool operator>(BigInteger const& A, BigInteger const& B) {
    return B < A;
}

bool operator<=(BigInteger const& A, BigInteger const& B) {
    return !(B < A);
}

bool operator>=(BigInteger const& A, BigInteger const& B) {
    return !(A < B);
}

///////////////////////////// Extra //////////////////////////////

//for binary search
BigInteger del2_(BigInteger const& A) {
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

int compare_(BigInteger const& A, const BigInteger& B) {
    if(A.getSize() > B.getSize())
        return 1;
    else if(A.getSize() < B.getSize())
        return 2;
    else {
        for(int i = 0; i < A.getSize(); i++) {
            if(A[i] > B[i])
                return 1;
            else if(B[i] > A[i])
                return 2;
        }
        return 0;
    }
}
