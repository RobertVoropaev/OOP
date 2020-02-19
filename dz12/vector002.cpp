#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int SIZE = 1e7;
    vector<bool> m(SIZE), n(SIZE);
    for(int i = 0; i < m.size(); i++)
        m[i] = n[i] = false;
    int w;
    for(;;) {
        cin >> w;
        if(w == -1)
            break;
        m[w] = true;
    }
    for(;;) {
        cin >> w;
        if(w == -1)
            break;
        n[w] = true;
    }
    bool a = true;
    for(int i = 0; i < SIZE; i++) {
        if(n[i] == true && m[i] == true) {
            cout << i << " ";
            a = false;
        }
        if(i == n.size() - 1 && a)
            cout << "empty";
    }
    return 0;
}