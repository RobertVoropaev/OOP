#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	int n, temp, y = -1;
	cin >> n;
	set <int> S;
	char A, B = '+';
	for (int i = 0; i < n; i++) {
		cin >> A;
		if (A == '+' && B == '+') {
			cin >> temp;
			S.insert(temp);
		}
		else if (A == '+') {
			cin >> temp;
			S.insert((temp + y) % (int) 1e+9);
		}
		else if (A == '?') {
			cin >> temp;
			set <int>::const_iterator it = S.lower_bound(temp);
			if (it == S.end()) y = -1;
			else y = *it;
			cout << y << endl;
		}
		B = A;
	}
	return 0;
}