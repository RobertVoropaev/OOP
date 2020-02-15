//
// Created by RobertVoropaev on 01.03.2016.
//

#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main() {
    DinamicArray<int> a;
    a.push_back(12);
    cout << a[0];
    return 0;
}
