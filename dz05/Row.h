//
// Created by RobertVoropaev on 22.03.2016.
//

#ifndef DZ05_ROW_H
#define DZ05_ROW_H

#include <cstddef>
#include <iostream>

template <size_t M>
class Row{
public:
    Row();
    explicit Row(double const* row);
    Row(Row<M> const& obj);
    virtual ~Row();

    size_t getSize() const;

    Row<M>& operator=(Row<M> const& R);

    explicit operator double*() const;

    double& operator[](size_t m);
    double operator[](size_t m) const;

    template <size_t T>
    friend std::ostream& operator<<(std::ostream& os, const Row<T>& R);

    template<size_t T>
    friend std::istream& operator>>(std::istream& stream, Row<T>& R);

    Row<M>& operator+=(Row<M> const& R);
    Row<M>& operator-=(Row<M> const& R);
    Row<M>& operator*=(double a);
    Row<M>& operator/=(double a);

private:
    double* row_;
    size_t  sizeM_;
};

template <size_t M>
Row<M> operator+(Row<M> R1, Row<M> const& R2);

template <size_t M>
Row<M> operator-(Row<M> R1, Row<M> const& R2);

template <size_t M>
Row<M> operator*(Row<M> R1, double a);

template <size_t M>
Row<M> operator/(Row<M> R1, double a);

template <size_t M>
bool operator==(Row<M> const& R1, Row<M> const& R2);

template <size_t M>
bool operator!=(Row<M> const& R1, Row<M> const& R2);

#include "Row_definitions.h"

#endif //DZ05_ROW_H
