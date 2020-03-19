//
// Created by RobertVoropaev on 05.04.2016.
//

#ifndef DZ07_VECTOR_H
#define DZ07_VECTOR_H

#include <cstdio>
#include <bits/exception.h>
#include <iostream>

template <class T>
class Vector {
public:
    Vector();
    Vector(size_t size);
    Vector(T element, size_t num);
    Vector(T const* array, size_t array_size);

    Vector(Vector<T> const& obj);
    Vector<T>& operator=(Vector<T> const& obj);

    virtual ~Vector();

    size_t  getSize()               const;
    size_t  getCapacity()           const;
    size_t  getResizeScale()        const;

    bool    isEmpty()               const;

    T       getBack()               const;
    T       getFront()              const;

    T&      operator[](size_t i);
    T       operator[](size_t i)    const;

    void    insert(T const& new_element, size_t index);
    void    push_back(T const& new_element);

    T       erase(size_t index);
    T       pop_back();

    void    clear();

    void    resize(size_t new_capacity);
    void    setResizeScale(size_t resize_scale);

    template <class D>
    friend std::ostream& operator<<(std::ostream& stream, Vector<D> const& A);
    template <class D>
    friend std::istream& operator>>(std::istream& stream, Vector<D>& A);

private:
    T*              array_;
    size_t          size_;

    size_t          capacity_;
    const size_t    default_capacity_ = 10;

    size_t          resize_scale_;
    const size_t    default_resize_scale_ = 2;

    bool    isItValidIndex(size_t index)    const;
    size_t  getValidCapacity(size_t size)   const;
};

template <class T>
bool operator==(Vector<T> const& A, Vector<T> const& B);
template <class T>
bool operator!=(Vector<T> const& A, Vector<T> const& B);


class SizeIsLessThanCapacityException : std::exception {};
class IncorrectResizeScaleException :   std::exception {};
class IncorrectIndexException :         std::exception {};
class VectorIsEmptyException :          std::exception {};

#include "Vector_def.h"

#endif //DZ07_VECTOR_H