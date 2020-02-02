#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	multimap <int, string> M;
	int N;
	string S;
	while (cin >> N >> S) M.insert(make_pair(N, S));
	for (multimap <int, string> ::iterator p = M.begin(); p != M.end(); p++) cout << p->first << ' ' << p->second << endl;
	return 0;
}