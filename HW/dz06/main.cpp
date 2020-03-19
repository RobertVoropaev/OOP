//
// Created by RobertVoropaev on 15.02.2020.
//

#include "iostream"
#include <BigInteger.h>

using namespace std;

template <class R1, class R2, class T, class U>
void print_error(R1 res1, R2 res2, T a, T b, U A, U B){
    cout << "ERROR" << endl;
    cout << res1 << "!=" << res2 << endl;
    cout << a << " " << b << endl;
    cout << A << " " << B << endl;
}

int main(){
    int min = -100, max = 100;
    for(int a = min; a <= max; a++){
        for(int b = min; b <= max; b++){
            BigInteger A(a), B(b);
            if(b == 0){
                continue;
            }
            int res1 = a / b;
            BigInteger res2 = A % B;
            if(res1 != res2){
                if(res1 != res2){
                    print_error(res1, res2, a, b, A, B);
                }
            }
        }
    }
    cout << "OK" << endl;
    return 0;
}
