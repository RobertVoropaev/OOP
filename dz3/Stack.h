//
// Created by RobertVoropaev on 05.03.2020.
//

#ifndef DZ3_STACK_H
#define DZ3_STACK_H

#include <cstddef>
#include <bits/exception.h>

template<class T>
class Stack {
public:
    virtual void push(T new_element) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual size_t getSize() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
};

class EmptyStackException : std::exception {};

#endif //DZ3_STACK_H
