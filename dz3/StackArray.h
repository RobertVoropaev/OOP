//
// Created by RobertVoropaev on 01.03.2016.
//

#ifndef DZ3_STACKARRAY_H
#define DZ3_STACKARRAY_H

#include "Stack.h"

#include <cstddef>
#include <bits/exception.h>


template<class T>
class StackArray : public Stack<T> {
public:
    explicit StackArray(size_t max_size = 100, size_t resize_scale = 2) : max_size_(max_size),
                                                                          resize_scale_(resize_scale), top_index_(-1),
                                                                          stack_(new T[max_size]) {
    }

    StackArray(StackArray const& obj) : max_size_(obj.max_size), resize_scale_(obj.resize_scale),
                                        top_index_(obj.top_index_), stack_(new T[obj.max_size]) {
        for(int i = 0; i <= top_index_; i++) {
            stack_[i] = obj.stack_[i];
        }
    }

    StackArray& operator=(StackArray const& obj) {
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

    virtual ~StackArray() {
        delete[] stack_;
    }

    void push(T new_element) {
        top_index_++;
        if(top_index_ == max_size_) {
            resize();
        }
        stack_[top_index_] = new_element;
    }

    T pop() {
        if(isEmpty()) {
            throw EmptyStackException();
        }
        return stack_[top_index_--];
    }

    T top() const {
        if(isEmpty()) {
            throw EmptyStackException();
        }
        return stack_[top_index_];
    }

    void clear() {
        top_index_ = -1;
    }

    size_t getSize() const {
        return top_index_ + 1;
    }

    bool isEmpty() const {
        return top_index_ == -1;
    }

    size_t getMaxSize() const {
        return max_size_;
    }

    size_t getResizeScale() const {
        return resize_scale_;
    }

private:
    T* stack_;
    int top_index_;

    size_t max_size_;
    size_t resize_scale_;

    void resize() {
        size_t new_max_size = max_size_ * resize_scale_;
        T* new_stack_ = new T[new_max_size];

        for(int i = 0; i < max_size_; i++) {
            new_stack_[i] = stack_[i];
        }

        delete[] stack_;

        stack_ = new_stack_;
        max_size_ = new_max_size;
    }
};

#endif //DZ3_STACKARRAY_H