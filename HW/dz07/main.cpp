//
// Created by RobertVoropaev on 01.03.2016.
//

using namespace std;

#include <cstdio>
#include <bits/exception.h>
#include <iostream>

#include "Vector.h"


template <class T>
void info(Vector<T> const& vector){
    cout << "Vector\n";
    cout << "size_: " << vector.getSize() <<
            " | capacity_: " << vector.getCapacity() <<
            " | resize_scale_: " << vector.getResizeScale() << endl;
    cout << vector << endl;
}

int main() {
    Vector<int> v;
    string s;
    int n;
    while(true){
        cin >> s;
        if(s == "push"){
            cin >> n;
            v.push_back(n);
            cout << "ok";
            cout << endl;
        }
        else if(s == "pop"){
            try{
                cout << v.pop_back();
            } catch (VectorIsEmptyException ex){
                cout << "error";
            }
            cout << endl;
        }
        else if(s == "back"){
            try{
                cout << v.getBack();
            } catch (VectorIsEmptyException ex){
                cout << "error";
            }
            cout << endl;
        }
        else if(s == "size"){
            cout << v.getSize();
            cout << endl;
        }
        else if(s == "clear"){
            v.clear();
            cout << "ok";
            cout << endl;
        }
        else {
            cout << "bye";
            cout << endl;
            break;
        }
    }
    return 0;
}
