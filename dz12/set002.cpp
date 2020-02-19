#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s1, s2, s3;
    int w;
    for(;;) {
        cin >> w;
        if(w == -1)
            break;
        s1.insert(w);
    }
    for(;;) {
        cin >> w;
        if(w == -1)
            break;
        s2.insert(w);
    }
    auto p = s1.begin();
    int s = 0;
    while(p != s1.end()) {
        if(s2.count(*p) != 0) {
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