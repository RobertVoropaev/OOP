//
// Created by RobertVoropaev on 05.04.2016.
//

#ifndef DZ07_VECTOR_DEF_H
#define DZ07_VECTOR_DEF_H

#include "Vector.h"

///////////////////////////// Constructors //////////////////////////////

template <class T>
Vector<T>::Vector() {
    size_ = 0;
    capacity_ = default_capacity_;
    resize_scale_ = default_resize_scale_;
    array_ = new T[capacity_];
}

template <class T>
Vector<T>::Vector(size_t size) {
    size_ = size;
    capacity_ = default_capacity_;
    resize_scale_ = default_resize_scale_;
    capacity_ = getValidCapacity(size);
    array_ = new T[capacity_];

    for(int i = 0; i < size_; i++) {
        array_[i] = 0;
    }
}

template <class T>
Vector<T>::Vector(T element, size_t num) {
    size_ = num;
    capacity_ = default_capacity_;
    resize_scale_ = default_resize_scale_;
    capacity_ = getValidCapacity(num);
    array_ = new T[capacity_];

    for(int i = 0; i < size_; i++) {
        array_[i] = element;
    }
}

template <class T>
Vector<T>::Vector(T const* array, size_t array_size) {
    size_ = array_size;
    capacity_ = default_capacity_;
    resize_scale_ = default_resize_scale_;
    capacity_ = getValidCapacity(array_size);
    array_ = new T[capacity_];

    for(int i = 0; i < size_; i++) {
        array_[i] = array[i];
    }
}

///////////////////////////// Destructors //////////////////////////////

template <class T>
Vector<T>::~Vector() {
    delete[] array_;
}

///////////////////////////// Сopying //////////////////////////////

template <class T>
Vector<T>::Vector(Vector<T> const& obj) {

    size_ = obj.size_;
    capacity_ = obj.capacity_;
    resize_scale_ = obj.resize_scale_;
    array_ = new T[obj.capacity_];

    for(int i = 0; i < size_; i++) {
        array_[i] = obj.array_[i];
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T> const& obj) {
    if(this != &obj) {
        delete[] array_;

        capacity_ = obj.capacity_;
        resize_scale_ = obj.resize_scale_;
        size_ = obj.size_;
        array_ = new T[obj.capacity_];

        for(int i = 0; i < size_; i++) {
            array_[i] = obj.array_[i];
        }
    }
    return *this;
}

///////////////////////////// const Getters //////////////////////////////

template <class T>
size_t Vector<T>::getSize() const {
    return size_;
}

template <class T>
size_t Vector<T>::getCapacity() const {
    return capacity_;
}

template <class T>
size_t Vector<T>::getResizeScale() const {
    return resize_scale_;
}

template <class T>
bool Vector<T>::isEmpty() const {
    return size_ == 0;
}

template <class T>
T Vector<T>::getBack() const {
    if(isEmpty()) {
        throw VectorIsEmptyException();
    }
    return array_[size_ - 1];
}

template <class T>
T Vector<T>::getFront() const {
    if(isEmpty()) {
        throw VectorIsEmptyException();
    }
    return array_[0];
}

///////////////////////////// Operator [] //////////////////////////////

template <class T>
T& Vector<T>::operator[](size_t i) {
    if(!isItValidIndex(i)) {
        throw IncorrectIndexException();
    }
    return array_[i];
}


template <class T>
T Vector<T>::operator[](size_t i) const {
    if(!isItValidIndex(i)) {
        throw IncorrectIndexException();
    }
    return array_[i];
}

///////////////////////////// Insert //////////////////////////////

template <class T>
void Vector<T>::insert(T const& new_element, size_t index) {
    if(!isItValidIndex(index) && (index != size_)) {
        throw IncorrectIndexException();
    }

    size_t valid_capacity = getValidCapacity(size_ + 1);
    if(capacity_ != valid_capacity) {
        resize(valid_capacity);
    }

    if(index == size_) {
        array_[size_++] = new_element;
    } else {
        size_++;
        for(int i = size_; i > index; i--) {
            array_[i] = array_[i - 1];
        }
        array_[index] = new_element;
    }
}

template <class T>
void Vector<T>::push_back(T const& new_element) {
    insert(new_element, size_);
}

///////////////////////////// Delete //////////////////////////////

template <class T>
T Vector<T>::erase(size_t index) {
    if(!isItValidIndex(index)) {
        throw IncorrectIndexException();
    }

    T delete_value = array_[index];

    size_--;
    for(int i = index; i < size_; i++) {
        array_[i] = array_[i + 1];
    }

    size_t valid_capacity = getValidCapacity(size_);
    if(capacity_ != valid_capacity) {
        resize(valid_capacity);
    }

    return delete_value;
}

template <class T>
T Vector<T>::pop_back() {
    if(isEmpty()) {
        throw VectorIsEmptyException();
    }
    return erase(size_ - 1);
}

template <class T>
void Vector<T>::clear() {
    delete[] array_;

    size_ = 0;
    capacity_ = default_capacity_;
    resize_scale_ = default_resize_scale_;
    array_ = new T[capacity_];
}

///////////////////////////// Resize //////////////////////////////

template <class T>
void Vector<T>::resize(size_t new_capacity) {
    if(size_ > new_capacity) {
        throw SizeIsLessThanCapacityException();
    } else if(capacity_ == new_capacity) {
        return;
    } else {
        capacity_ = new_capacity;
        T* new_array = new T[capacity_];
        for(int i = 0; i < size_; i++) {
            new_array[i] = array_[i];
        }
        delete[] array_;
        array_ = new_array;
    }
}

template <class T>
void Vector<T>::setResizeScale(size_t resize_scale) {
    if(resize_scale <= 1) {
        throw IncorrectResizeScaleException();
    }
    resize_scale_ = resize_scale;
}

///////////////////////////// Streams //////////////////////////////

template <class D>
std::ostream& operator<<(std::ostream& stream, const Vector<D>& A) {
    for(int i = 0; i < A.getSize(); i++) {
        stream << A[i] << " ";
    }
    return stream;
}

template <class D>
std::istream& operator>>(std::istream& stream, Vector<D>& A) {
    A.clear();

    size_t size;
    stream >> size;

    size_t new_capacity = A.getValidCapacity(size);
    A.resize(new_capacity);

    for(int i = 0; i < size; i++) {
        D new_element;
        stream >> new_element;
        A.push_back(new_element);
    }
    return stream;
}

///////////////////////////// Validation //////////////////////////////

template <class T>
size_t Vector<T>::getValidCapacity(size_t size) const {
    size_t prev_capacity = capacity_ / resize_scale_;
    size_t next_capacity = capacity_ * resize_scale_;
    if((capacity_ == default_capacity_ || prev_capacity < size) && size <= capacity_) {
        return capacity_;
    } else if(size <= prev_capacity) {
        return prev_capacity;
    } else {
        return next_capacity;
    }
}

template <class T>
bool Vector<T>::isItValidIndex(size_t index) const {
    return (index >= 0) && (index < size_);
}

///////////////////////////// Equality //////////////////////////////

template <class T>
bool operator==(Vector<T> const& A, Vector<T> const& B) {
    if(A.size() != B.size()) {
        return false;
    }
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool operator!=(Vector<T> const& A, Vector<T> const& B) {
    return !(A == B);
}

#endif //DZ07_VECTOR_DEF_H