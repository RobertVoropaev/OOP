//
// Created by RobertVoropaev on 22.03.2016.
//

#ifndef DZ05_ROW_DEF_H
#define DZ05_ROW_DEF_H

#include "Row.h"

template <size_t M>
Row<M>::Row() : sizeM_(M) {
    row_ = new double [sizeM_];
    for(int i = 0; i < sizeM_; i++){
        row_[i] = 0;
    }
}

template <size_t M>
Row<M>::Row(double const* row) : sizeM_(M) {
    row_ = new double [sizeM_];
    for(int i = 0; i < sizeM_; i++){
        row_[i] = row[i];
    }
}

template <size_t M>
Row<M>::Row(Row const& obj) : sizeM_(M) {
    row_ = new double [sizeM_];
    for(int i = 0; i < sizeM_; i++){
        row_[i] = obj.row_[i];
    }
}

template<size_t M>
Row<M>::~Row() {
    delete [] row_;
}

template<size_t M>
Row<M>& Row<M>::operator=(const Row<M> &R) {
    if(this != &R) {
        delete[] row_;
        sizeM_ = R.sizeM_;
        row_ = new double[sizeM_];
        for(int i = 0; i < sizeM_; i++) {
            row_[i] = R.row_[i];
        }
    }
    return *this;
}

template<size_t M>
Row<M>::operator double* () const {
    auto row = new double[sizeM_];
    for(int i = 0; i < sizeM_; i++){
        row[i] = row_[i];
    }
    return row;
}

template<size_t M>
double& Row<M>::operator[](size_t m){
    return row_[m];
}

template<size_t M>
double Row<M>::operator[](size_t m) const{
    return row_[m];
}

template<size_t M>
std::ostream& operator<<(std::ostream& stream, const Row<M>& R) {
    for(int i = 0; i < R.sizeM_; i++){
        stream << R.row_[i] << " ";
    }
    return stream;
}

template<size_t M>
std::istream& operator>>(std::istream& stream, Row<M>& R) {
    for(int i = 0; i < R.sizeM_; i++) {
        stream >> R.row_[i];
    }
    return stream;
}

template<size_t M>
size_t Row<M>::getSize() const {
    return sizeM_;
}


template <size_t M>
Row<M>& Row<M>::operator+=(Row<M> const& R){
    for(int i = 0; i < sizeM_; i++) {
            row_[i] += R.row_[i];
    }
    return *this;
}

template <size_t M>
Row<M> operator+(Row<M> R1, Row<M> const& R2){
    return R1 += R2;
}

template <size_t M>
Row<M>& Row<M>::operator-=(Row<M> const& R){
    for(int i = 0; i < sizeM_; i++) {
        row_[i] -= R.row_[i];
    }
    return *this;
}

template <size_t M>
Row<M> operator-(Row<M> R1, Row<M> const& R2){
    return R1 += R2;
}

template <size_t M>
Row<M>& Row<M>::operator*=(double a){
    for(int i = 0; i < sizeM_; i++) {
        row_[i] *= a;
    }
    return *this;
}

template <size_t M>
Row<M> operator*(Row<M> R1, double a){
    return R1 *= a;
}

template <size_t M>
Row<M>& Row<M>::operator/=(double a){
    for(int i = 0; i < sizeM_; i++) {
        row_[i] /= a;
    }
    return *this;
}

template <size_t M>
Row<M> operator/(Row<M> R1, double a){
    return R1 *= a;
}

template <size_t M>
bool operator==(Row<M> const& R1, Row<M> const& R2){
    for(int i = 0; i < M; i++){
        if(R1[i] != R2[i]){
            return false;
        }
    }
    return true;
}

template <size_t M>
bool operator!=(Row<M> const& R1, Row<M> const& R2){
    return !(R1 == R2);
}

#endif //DZ05_ROW_DEF_H
