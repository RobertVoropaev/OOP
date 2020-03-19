//
// Created by RobertVoropaev on 10.05.2016.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void str_preprocessing_spaces(string & str){
    size_t i = 0;
    while(str[i] == ' ')
        i++;
    str.erase(0, i);

    i = str.size() - 1;
    while(str[i] == ' ')
        i--;
    str.erase(i + 1, str.size() - i);

    size_t u = 0;
    for(int k = 0; k < str.size(); k++) {
        if(str[k] == ' ')
            u++;
        else {
            if(u > 1)
                str.erase(k - u + 1, u - 1);
            u = 0;
        }
    }
}

struct myComp {
    bool operator()(int a, int b) {
        return (a > b);
    }
};

int main() {
    string str;
    getline(cin, str);
    str_preprocessing_spaces(str);

    string s;
    multimap<string, int> dict;
    multimap<string, int>::iterator iter_p;

    size_t start = 0;
    size_t end = str.find(' ');
    size_t e = 0;
    while(e != 1) {
        s.assign(str, start, end - start);
        start = end + 1;
        end = str.find(' ', start);
        if(end == -1) {
            end = str.size();
            e++;
        }
        iter_p = dict.find(s);
        if(iter_p != dict.end()) {
            iter_p->second++;
        } else {
            dict.insert(pair<string, int>(s, 1));
        }
    }

    multimap<int, string, myComp> MultiMap;
    iter_p = dict.begin();
    while(iter_p != dict.end()) {
        MultiMap.insert(pair<int, string>(iter_p->second, iter_p->first));
        iter_p++;
    }

    auto iter_g  = MultiMap.begin();
    size_t j = 0;
    while(iter_g != MultiMap.end()) {
        if(j == 10)
            break;
        cout << iter_g->second << " " << iter_g->first << endl;
        iter_g++;
        j++;
    }
    return 0;
}