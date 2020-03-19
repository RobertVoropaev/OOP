#include <iostream>

using namespace std;

#include "Matrix.h"
#include "SquareMatrix.h"

int main(){
    SquareMatrix<2> a;
    cin >> a;
    cout << (a ^ 3);
    return 0;
}