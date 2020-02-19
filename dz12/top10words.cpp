#include <iostream>
#include <string>
#include <map>
#include <algorithm>

struct myF {
    bool operator()(int a, int b) {
        return (a > b);
    }
};

using namespace std;

int main() {
    string str, s;
    multimap<string, int> Map;
    multimap<string, int>::iterator p;
    getline(cin, str);
    int i = 0;
    while(str[i] == ' ')
        i++;
    str.erase(0, i);
    i = str.size() - 1;
    while(str[i] == ' ')
        i--;
    str.erase(i + 1, str.size() - i);
    int u = 0;
    for(int k = 0; k < str.size(); k++) {
        if(str[k] == ' ')
            u++;
        else {
            if(u > 1)
                str.erase(k - u + 1, u - 1);
            u = 0;
        }
    }
    int start = 0, end = str.find(' '), e = 0;
    while(e != 1) {
        s.assign(str, start, end - start);
        start = end + 1;
        end = str.find(' ', start);
        if(end == -1) {
            end = str.size();
            e++;
        }
        p = Map.find(s);
        if(p != Map.end()) {
            p->second++;
        } else {
            Map.insert(pair<string, int>(s, 1));
        }
    }
    multimap<int, string, myF> MultiMap;
    p = Map.begin();
    while(p != Map.end()) {
        MultiMap.insert(pair<int, string>(p->second, p->first));
        p++;
    }
    multimap<int, string, myF>::iterator g;
    g = MultiMap.begin();
    int j = 0;
    while(g != MultiMap.end()) {
        if(j == 10)
            break;
        cout << g->second << " " << g->first << endl;
        g++;
        j++;
    }
    return 0;
}