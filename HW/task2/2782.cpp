//
// Created by RobertVoropaev on 15.05.2016.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, temp;
    int y = -1;
    cin >> n;

    set<int> S;
    char A;
    char B = '+';

    for(int i = 0; i < n; i++) {
        cin >> A;

        if(A == '+' && B == '+') {
            cin >> temp;
            S.insert(temp);
        }
        else if(A == '+') {
            cin >> temp;
            S.insert((temp + y) % (int) 1e+9);
        }
        else if(A == '?') {
            cin >> temp;
            auto it = S.lower_bound(temp);
            if(it == S.end()) {
                y = -1;
            }
            else {
                y = *it;
            }
            cout << y << endl;
        }
        B = A;
    }
    return 0;
}