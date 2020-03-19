//
// Created by RobertVoropaev on 15.05.2016.
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string str;
    deque<int> D;

    while(true) {
        bool b = true;
        int n;

        cin >> str;

        if(str == "push_front") {
            cin >> n;
            D.push_front(n);
            cout << "ok";
        }
        else if(str == "push_back") {
            cin >> n;
            D.push_back(n);
            cout << "ok";
        }
        else if(str == "pop_front") {
            if(!D.empty()) {
                cout << D.front();
                D.pop_front();
            }
            else {
                cout << "error";
            }
        }
        else if(str == "pop_back") {
            if(!D.empty()) {
                cout << D.back();
                D.pop_back();
            }
            else {
                cout << "error";
            }
        }
        else if(str == "front") {
            if(!D.empty()) {
                cout << D.front();
            }
            else {
                cout << "error";
            }
        }
        else if(str == "back") {
            if(!D.empty()) {
                cout << D.back();
            }
            else {
                cout << "error";
            }
        }
        else if(str == "size") {
            cout << D.size();
        }
        else if(str == "clear") {
            while(!D.empty()) {
                D.pop_back();
            }
            cout << "ok";
        }
        else if(str == "exit") {
            while(!D.empty()) {
                D.pop_back();
            }
            cout << "bye";
            return 0;
        }
        else {
            b = false;
        }

        if(b) {
            cout << endl;
        }
    }
}




