//
// Created by RobertVoropaev on 15.05.2016.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, K, x;
    cin >> N >> K;

    vector<int> v;
    multiset<int> s;

    for(int i = 0; i < K; i++) {
        cin >> x;
        v.push_back(x);
        s.insert(x);
    }
    cout << *s.begin() << endl;

    for(int i = K; i < N; i++) {
        s.erase(s.find(v[i % K]));
        cin >> x;
        v[i % K] = x;
        s.insert(x);
        cout << *s.begin() << endl;
    }
    return 0;
}
