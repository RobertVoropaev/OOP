//
// Created by RobertVoropaev on 01.03.2016.
//

#ifndef DZ3_STACKLIST_DEF_H
#define DZ3_STACKLIST_DEF_H

#include "StackList.h"

/////////////////////////////////////// Base ///////////////////////////////////////

template<class T>
StackList<T>::ListElement::ListElement(int value, StackList<T>::ListElement* next) : value(value), next(next) {}

template<class T>
StackList<T>::StackList() : head_(0), size_(0) {}

template<class T>
StackList<T>::~StackList() {
    while(!isEmpty()) {
        pop();
    }
}

template<class T>
StackList<T>::StackList(StackList<T> const& obj) {
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

template<class T>
StackList<T>& StackList<T>::operator=(StackList<T> const& obj) {
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

////////////////////////////////// Stack operations //////////////////////////////////

template<class T>
void StackList<T>::push(T new_value) {
    ListElement* new_head = new ListElement(new_value, head_);
    head_ = new_head;
    size_++;
}

template<class T>
T StackList<T>::pop() {
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

template<class T>
T StackList<T>::top() const {
    if(isEmpty()) {
        throw EmptyStackException();
    }
    return head_->value;
}

template<class T>
void StackList<T>::clear(){
    this->~StackList();
}

/////////////////////////////////////// Getters ///////////////////////////////////////

template<class T>
size_t StackList<T>::getSize() const {
    return size_;
}

template<class T>
bool StackList<T>::isEmpty() const {
    return size_ == 0;
}


#endif //DZ3_STACKLIST_DEF_H
