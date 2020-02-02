#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <conio.h>
struct myF{ //‘унктор
	bool operator()(int a, int b) { return (a > b); }
};
using namespace std;
int main() {
	string str, s;
	multimap <string, int> Map;
	multimap <string, int>::iterator p;
	getline(cin, str);
	int i = 0;
	while (str[i] == ' ') i++;
	str.erase(0, i);//”деление пробелов из начала строки
	i = str.size()-1;
	while (str[i] == ' ') i--;
	str.erase(i + 1, str.size() - i); //”даление пробелов из конца строки
	int u = 0;
	for (int k = 0; k < str.size(); k++) { // ”даление лишних пробелов, если из больше одного между словами
		if (str[k] == ' ') u++;
		else {
			if (u > 1) str.erase(k - u + 1, u - 1);
			u = 0;
		}
	}
	int start = 0, end = str.find(' '), e = 0;
	while (e!=1) { //¬ыделение слова и запись его в отображение
		s.assign(str, start, end - start);
		start = end + 1;
		end = str.find(' ', start);
		if (end == -1) {
			end = str.size();
			e++;
		}
		p = Map.find(s);
		if (p != Map.end()) {//≈сли такое слово уже есть - увеличить значение, если нет - добавить
			p->second++;
		}
		else {
			Map.insert(pair <string, int>(s, 1));
		}
	}
	multimap <int, string, myF> MultiMap;
	p = Map.begin();
	while (p != Map.end()) {// опирование в упор€доченное по количеству слов отображение
		MultiMap.insert(pair <int, string>(p->second, p->first));
		p++;
	}
	multimap <int, string, myF>::iterator g;
	g = MultiMap.begin();
	int j = 0;
	while (g != MultiMap.end()) {
		if (j == 10) break;
		cout << g->second << " " << g->first << endl;
		g++;
		j++;
	}
	_getch();
	return 0;
}