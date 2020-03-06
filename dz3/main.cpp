//
// Created by RobertVoropaev on 01.03.2016.
//


#include <iostream>
#include "StackArray.h"
#include "StackList.h"
#include <string>

using namespace std;


int main() {
    Stack<int> * s = new StackArray<int>();

    string command;
    int n;
    cin >> command;
    if (command == "push"){
        cin >> n;
        s->push(n);
    }
    while(command != "exit"){
        cin >> command;
        cout << command;
        if (command == "push"){
            cin >> n;
            s->push(n);
        }
        else if (command == "pop"){
            cout << s->top() << endl;
            s->pop();
        }
        else if (command == "back"){
            cout << s->top() << endl;
        }
        else if(command == "size"){
            cout << s->getSize() << endl;
        }
        else if(command == "clear"){
            s->clear();
            cout << "ok" << endl;
        }
        else {
            break;
        }
    }
    cout << "bye";
    return 0;
}