#include <iostream>
#include "PolishNotation.h"
using namespace std;

int main() {
	bool error;
	char m[100];
	for (;;) {
		cout << "Enter: ";
		cin >> m;
		int a = PolishNotation(m, error);
		if (!error) cout << "Results: " << a << "\n";
		else cout << "Error!\n";
	}
	cin.get();
	return 0;
}