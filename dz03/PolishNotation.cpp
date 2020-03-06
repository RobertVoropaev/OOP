//
// Created by RobertVoropaev on 01.03.2016.
//


#include "PolishNotation.h"
#include "StackArray.h"

int PolishNotation(char* str) {
    StackArray<int> s;
    error = false;
    while(*str) {
        if(*str >= '0' && *str <= '9' && s.getSize() < 2) {
            s.push(*str - '0');
        }
        else if(*str == '+' && s.getSize() == 2) {
            s.push(s.pop() + s.pop());
        }
        else if(*str == '-' && s.getSize() == 2) {
            s.push(s.pop() - s.pop());
        }
        else if(*str == '*' && s.getSize() == 2) {
            s.push(s.pop() * s.pop());
        }
        else if((*str == '/') && (s.getSize() == 2) && ((*(str - 2) - '0') != 0)) {
            s.push(s.pop() / s.pop());
        }
        else {
            throw ErrorNotationException();
        }
        str++;
    }
    if(s.getSize() == 1) {
        return s.pop();
    }
    else {
        throw ErrorNotationException();
    }
}