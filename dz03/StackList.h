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
    StackList();

    StackList(StackList<T> const& obj);
    StackList<T>& operator=(StackList<T> const& obj);

    virtual ~StackList();

    void    push(T new_value);
    T       pop();
    T       top()               const;

    void    clear();

    size_t  getSize()           const;
    bool    isEmpty()           const;

private:
    struct ListElement {
        ListElement(int value, ListElement* next);

        T               value;
        ListElement*    next;
    };

    ListElement*    head_;
    size_t          size_;
};

#include "StackList_def.h"

#endif //DZ3_STACKLIST_H