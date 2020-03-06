//
// Created by RobertVoropaev on 01.03.2016.
//

#ifndef DZ3_STACKLIST_H
#define DZ3_STACKLIST_H

#include "Stack.h"

#include <cstddef>
#include <bits/exception.h>

template<class T>
class StackList : public Stack<T> {
public:
    StackList() : head_(0), size_(0) {}

    virtual ~StackList() {
        while(!isEmpty()) {
            pop();
        }
    }

    StackList(StackList const& obj) {
        size_ = 0;

        T* arr = new T[obj.size_];
        ListElement* temp = obj.head_;
        for(int i = 0; i < obj.size_; i++) {
            arr[i] = temp->value;
            temp = temp->next;
        }
        for(int i = obj.size_ - 1; i >= 0; i--) {
            push(arr[i]);
        }
        delete[] arr;
    }

    StackList& operator=(StackList const& obj) {
        if(this != &obj) {
            ~StackList();

            T* arr = new T[obj.size_];
            ListElement* temp = obj.head_;
            for(int i = 0; i < obj.size_; i++) {
                arr[i] = temp->value;
                temp = temp->next;
            }
            for(int i = obj.size_ - 1; i >= 0; i--) {
                push(arr[i]);
            }
            delete[] arr;
        }
        return *this;
    }

    void push(T new_value) {
        ListElement* new_head = new ListElement(new_value, head_);
        head_ = new_head;
        size_++;
    }

    T pop() {
        if(isEmpty()) {
            throw EmptyStackException();
        }

        ListElement* new_head = head_->next;
        T value = head_->value;
        delete head_;

        head_ = new_head;
        size_--;
        return value;
    }

    T top() const {
        if(isEmpty()) {
            throw EmptyStackException();
        }
        return head_->value;
    }

    void clear(){
        this->~StackList();
    }

    size_t getSize() const {
        return size_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

private:
    struct ListElement {
        ListElement(int value, ListElement* next) : value(value), next(next) {
        }

        T value;
        ListElement* next;
    };

    ListElement* head_;
    size_t size_;
};

#endif //DZ3_STACKLIST_H