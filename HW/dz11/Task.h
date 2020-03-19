//
// Created by RobertVoropaev on 03.05.2016.
//

#ifndef DZ11_TASK_H
#define DZ11_TASK_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Task {
public:
    virtual void solve(string in_str) = 0;
};

class TaskA : public Task {
public:
    void solve(string in_str) final {
        string b, c;
        if(in_str.length() % 2 == 0) {
            b.assign(in_str, 0, in_str.length() / 2);
            c.assign(in_str, in_str.length() / 2, in_str.length() / 2);
        } else {
            b.assign(in_str, 0, (in_str.length() / 2) + 1);
            c.assign(in_str, (in_str.length() / 2) + 1, in_str.length() / 2);
        }
        in_str = c + b;
        cout << in_str;
    }
};

class TaskB : public Task {
public:
    void solve(string in_str) final {
        string b, c;
        b.assign(in_str, 0, in_str.find(' '));
        c.assign(in_str, in_str.find(' ') + 1, in_str.size());
        in_str = c + ' ' + b;
        cout << in_str;
    }
};

class TaskC : public Task {
public:
    void solve(string in_str) final {
        if(in_str.find('f') == in_str.npos)
            cout << -2;
        else if(in_str.find('f') == in_str.rfind('f'))
            cout << -1;
        else {
            in_str.erase(in_str.find('f'), 1);
            cout << in_str.find('f') + 1;
        }
    }
};

class TaskD : public Task {
public:
    void solve(string in_str) final {
        int s = 0;
        while(in_str.find(' ') != in_str.npos) {
            s++;
            in_str.erase(in_str.find(' '), 1);
        }
        cout << s + 1;
    }
};

class TaskE : public Task {
public:
    void solve(string in_str) final {
        reverse(in_str.begin() + in_str.find('h') + 1, in_str.begin() + (in_str.rfind('h')));
        cout << in_str;
    }
};

class TaskF : public Task {
public:
    void solve(string in_str) final {
        size_t start = in_str.find('h') + 1;
        while(in_str.find('h', start) < in_str.rfind('h')) {
            start = in_str.find('h', start) + 1;
            in_str.replace(start - 1, 1, "H");
        }
        cout << in_str;
    }
};

#endif //DZ11_TASK_H