//
// Created by RobertVoropaev on 01.03.2016.
//

#ifndef DZ3_POLISHNOTATION_H
#define DZ3_POLISHNOTATION_H

#include <bits/exception.h>

class ErrorNotationException : public std::exception {};

int PolishNotation(char *str);

#endif //DZ3_POLISHNOTATION_H