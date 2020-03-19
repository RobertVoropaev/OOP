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
    explicit StackArray(size_t max_size = 100, size_t resize_scale = 2);

    StackArray(StackArray<T> const& obj);
    StackArray<T>& operator=(StackArray<T> const& obj);

    virtual ~StackArray();

    void    push(T new_element);
    T       pop();
    T       top()               const;

    void    clear();

    size_t  getSize()           const;
    size_t  getMaxSize()        const;
    size_t  getResizeScale()    const;
    bool    isEmpty()           const;

private:
    T*          stack_;
    int         top_index_;

    size_t      max_size_;
    size_t      resize_scale_;

    void        resize();
};

#include "StackArray_def.h"

#endif //DZ3_STACKARRAY_H