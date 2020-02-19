//
// Created by RobertVoropaev on 01.03.2016.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "Task.h"

using namespace std;

int main() {
    string in_str;
    getline(cin, in_str);
    Task* task = new TaskB;
    task->solve(in_str);
    return 0;
}