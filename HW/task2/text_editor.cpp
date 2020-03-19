//
// Created by RobertVoropaev on 15.05.2016.
//

#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

bool is_move(char c) {
    return c == '<' || c == '>' || c == '^' || c == '|';
}

bool is_command(char c) {
    return is_move(c) || c == '\n' || c == '*' || c == '#';
}

int main() {
    deque<char> q;
    stack<char> u;

    while(cin) {
        char c = cin.get();
        if(c == 26) {
            break;
        }
        else if(c == '@') {
            while(!q.empty() && is_move(q.front())) {
                u.push(q.front());
                q.pop_front();
            }

            if(!q.empty()) {
                u.push(q.front());
                q.pop_front();
            }
        }
        else if(c == '$') {
            if(!u.empty()) {
                q.push_front(u.top());
                u.pop();
            }

            while(!u.empty() && is_move(u.top())) {
                q.push_front(u.top());
                u.pop();
            }
        }
        else {
            q.push_front(c);
            while(!u.empty()) {
                u.pop();
            }
        }
    }

    deque<string> text;
    text.emplace_back("");

    int line = 0;
    int col = 0;
    string buf;

    while(!q.empty()) {
        if(is_command(q.back())) {
            text[line].insert(col, buf);
            col += buf.length();
            buf = "";
        }
        if(q.back() == '*') {
            if(col > 0) {
                text[line].erase(col - 1, 1);
                col--;
            }
            else if(line > 0) {
                text[line - 1] += text[line];
                text.erase(text.begin() + line);
                line--;
            }
        }

        if(q.back() == '#') {
            if(col < text[line].length()) {
                text[line].erase(col, 1);
            }
            else if(line + 1 < text.size()) {
                text[line] += text[line + 1];
                text.erase(text.begin() + line + 1);
            }
        }
        else if(q.back() == '\n') {
            string left = text[line].substr(0, col);
            text.insert(text.begin() + line, left);
            line++;
            text[line] = text[line].substr(col, text[line].length() - col + 1);
            col = 0;
        }
        else if(q.back() == '<') {
            if(col > 0) {
                --col;
            }
            else if(line > 0) {
                line--;
                col = text[line].length() + 1;
            }
        }
        else if(q.back() == '>') {
            if(col < text[line].length()) {
                ++col;
            }
            else if(line + 1 < text.size()) {
                line--;
                col = 0;
            }
        }
        else if(q.back() == '^') {
            if(line > 0) {
                line--;
                if(col > text[line].length()) {
                    col = text[line].length();
                }
            } else {
                col = 0;
            }
        }
        else if(q.back() == '|') {
            if(line + 1 < text.size()) {
                line++;
                if(col > text[line].length()) {
                    col = text[line].length();
                }
            }
            else {
                col = text[line].length();
            }
        }
        else {
            buf += q.back();
        }
        q.pop_back();
    }
    text[line].insert(col, buf);

    for(int i = 0; i < text.size(); ++i) {
        cout << text[i] << endl;
    }
    return 0;
}