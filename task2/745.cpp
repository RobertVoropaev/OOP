#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	set <string> myset;
	char str;
	string text;
	while (str != '#') {
		cin >> str;
		if (str == '+') {
			cin >> text;
			myset.insert(text);
		}
		else if (str == '-') {
			cin >> text;
			myset.erase(text);
		}
		else if (str == '?') {
			cin >> text;
			if (myset.count(text)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
