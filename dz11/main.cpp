#include <iostream>
#include <string>
#include <algorithm>
#include <locale.h>
#include <conio.h>
using namespace std;
void informatics(char r, string a) {
	switch (r) {
	case'A': {
		string b, c;
		if (a.length() % 2 == 0) {
			b.assign(a, 0, a.length() / 2);
			c.assign(a, a.length() / 2, a.length() / 2);
		}
		else {
			b.assign(a, 0, (a.length() / 2) + 1);
			c.assign(a, (a.length() / 2) + 1, a.length() / 2);
		}
		a = c + b;
		cout << a;
	}
			 break;
	case 'B': {
		string b, c;
		b.assign(a, 0, a.find(' '));
		c.assign(a, a.find(' ') + 1, a.size());
		a = c + ' ' + b;
		cout << a;
	}
			  break;
	case 'C': {
		if (a.find('f') == a.npos) cout << -2;
		else if (a.find('f') == a.rfind('f')) cout << -1;
		else {
			a.erase(a.find('f'), 1);
			cout << a.find('f') + 1;
		}
	}
			  break;
	case 'D': {
		int s = 0;
		while (a.find(' ') != a.npos) {
			s++;
			a.erase(a.find(' '), 1);
		}
		cout << s + 1;
	}
			  break;
	case 'E': {
		reverse(a.begin() + a.find('h') + 1, a.begin() + (a.rfind('h')));
		cout << a;
	}
			  break;
	case 'F': {
		int start = a.find('h') + 1;
		while (a.find('h', start) < a.rfind('h')) {
			start = a.find('h', start) + 1;
			a.replace(start - 1, 1, "H");
		}
		cout << a;
	}
			  break;
	default:
		cout << "Такой задачи нет.";
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	string a;
	getline(cin, a);
	informatics('A', a); //Параметры - буква задачи, строка
	_getch();
	return 0;
}