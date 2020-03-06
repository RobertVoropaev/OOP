//
// Created by RobertVoropaev on 01.03.2016.
//

#pragma once

#include <cstdio>

template<class T>
class DinamicArray {
public:
    DinamicArray(unsigned int size = 100, unsigned int autoPlusSize = 100);
    DinamicArray(const DinamicArray& obj);
    ~DinamicArray();

    int size() const;
    int capacity() const;
    void push_back(const T& a);

    T& operator[](unsigned int a);
private:
    T* array_;
    size_t size_;
    size_t initSize_;
    size_t autoPlusSize_;
};

template<class T>
DinamicArray<T>::DinamicArray(unsigned int size, unsigned int autoPlusSize) {
    initSize_ = size;
    autoPlusSize_ = autoPlusSize;
    size_ = 0;
    array_ = new T[initSize_];
    for(int i = 0; i < initSize_; i++)
        array_[i] = 0;
}

template<class T>
DinamicArray<T>::DinamicArray(const DinamicArray& obj) {
    initSize_ = obj.initSize_;
    autoPlusSize_ = obj.autoPlusSize_;
    size_ = obj.size_;
    array_ = new T[initSize_];
    for(int i = 0; i < initSize_; i++)
        array_[i] = obj.array_[i];
}

template<class T>
DinamicArray<T>::~DinamicArray() {
    delete[] array_;
}

template<class T>
void DinamicArray<T>::push_back(const T& a) {
    if(size_ >= initSize_) {
        T* h;
        h = array_;
        initSize_ += autoPlusSize_;
        array_ = new T[initSize_];
        for(int i = 0; i < initSize_ - autoPlusSize_; i++)
            array_[i] = h[i];
        delete[] h;
        for(int i = initSize_ - autoPlusSize_; i < initSize_; i++)
            array_[i] = 0;
        array_[size_] = a;
    } else {
        array_[size_] = a;
    }
    size_++;
}

template<class T>
T& DinamicArray<T>::operator[](unsigned int a) {
    if(a < initSize_)
        return array_[a];
}


template <class T>
int DinamicArray<T>::size() const {
    return size_;
}

template <class T>
int DinamicArray<T>::capacity() const {
    return initSize_;
}
