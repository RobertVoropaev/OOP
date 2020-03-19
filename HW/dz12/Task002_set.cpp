//
// Created by RobertVoropaev on 10.05.2016.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> set1;

    int w;
    while(true) {
        cin >> w;
        if(w == -1)
            break;
        set1.insert(w);
    }

    set<int> set2;
    while(true) {
        cin >> w;
        if(w == -1)
            break;
        set2.insert(w);
    }

    auto p = set1.begin();
    int s = 0;
    while(p != set1.end()) {
        if(set2.count(*p) != 0) {
            cout << *p << " ";
            s++;
        }
        p++;
    }
    if(s == 0){
        cout << "empty";
    }
    return 0;
}