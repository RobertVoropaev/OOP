//
// Created by RobertVoropaev on 01.03.2016.
//

#ifndef DZ3_STACKARRAY_DEF_H
#define DZ3_STACKARRAY_DEF_H

#include "StackArray.h"

/////////////////////////////////////// Base ///////////////////////////////////////

template<class T>
StackArray<T>::StackArray(size_t max_size, size_t resize_scale) :  max_size_(max_size),
                                                                resize_scale_(resize_scale),
                                                                top_index_(-1),
                                                                stack_(new T[max_size]) {}

template<class T>
StackArray<T>::StackArray(StackArray<T> const& obj) : max_size_(obj.max_size),
                                    resize_scale_(obj.resize_scale),
                                    top_index_(obj.top_index_),
                                    stack_(new T[obj.max_size]) {
    for(int i = 0; i <= top_index_; i++) {
        stack_[i] = obj.stack_[i];
    }
}

template<class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T> const& obj) {
    if(this != &obj) {
        delete stack_;
        max_size_ = obj.max_size_;
        resize_scale_ = obj.resize_scale_;
        top_index_ = obj.top_index_;
        stack_ = new T[max_size_];
        for(int i = 0; i <= top_index_; i++) {
            stack_[i] = obj.stack_[i];
        }
    }
    return *this;
}

template<class T>
StackArray<T>::~StackArray() {
    delete[] stack_;
}

////////////////////////////////// Stack operations //////////////////////////////////

template<class T>
void StackArray<T>::push(T new_element) {
    top_index_++;
    if(top_index_ == max_size_) {
        resize();
    }
    stack_[top_index_] = new_element;
}

template<class T>
T StackArray<T>::pop() {
    if(isEmpty()) {
        throw EmptyStackException();
    }
    return stack_[top_index_--];
}

template<class T>
T StackArray<T>::top() const {
    if(isEmpty()) {
        throw EmptyStackException();
    }
    return stack_[top_index_];
}

template<class T>
void StackArray<T>::clear() {
    top_index_ = -1;
}

/////////////////////////////////////// Getters ///////////////////////////////////////

template<class T>
size_t StackArray<T>::getSize() const {
    return top_index_ + 1;
}

template<class T>
bool StackArray<T>::isEmpty() const {
    return top_index_ == -1;
}

template<class T>
size_t StackArray<T>::getMaxSize() const {
    return max_size_;
}

template<class T>
size_t StackArray<T>::getResizeScale() const {
    return resize_scale_;
}

/////////////////////////////////////// Resize ///////////////////////////////////////

template<class T>
void StackArray<T>::resize() {
    size_t new_max_size = max_size_ * resize_scale_;
    T* new_stack_ = new T[new_max_size];

    for(int i = 0; i < max_size_; i++) {
        new_stack_[i] = stack_[i];
    }

    delete[] stack_;

    stack_ = new_stack_;
    max_size_ = new_max_size;
}

#endif //DZ3_STACKARRAY_DEF_H
