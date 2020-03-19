//
// Created by RobertVoropaev on 15.05.2016.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    int k = 0;
    cin >> n;

    vector<int> m(n);

    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }

    cin >> x;
    for(int i = 0; i < n; i++) {
        if(m[i] == x) {
            k++;
        }
    }

    cout << k;
    return 0;
}