#include <iostream>
#include <map>
using namespace std;
int main() {
	map<int, int> M1;
	map<int, int> M2;
	int M, n = 0, x;  
	cin >> M;
	for (int i = 0; cin >> x; i--) {
		if (M1.find(x) == M1.end()) { // Не в кэше 
			cout << '1' << ' ';
			if (n == M) {
				M1.erase(M1.find(M2.rbegin()->second));
				M1[x] = i;
				M2.erase(M2.rbegin()->first);
				M2.insert(pair<int, int>(i, x));
			}
			else {
				n++;
				M1.insert(pair<int, int>(x, i));
				M2.insert(pair<int, int>(i, x));
			}
		}
		else { // В кэше
			cout << '0' << ' ';
			M2.erase(M1.find(x)->second);
			M2.insert(pair<int, int>(i, x));
			M1[x] = i;
		}
	}
	return 0;
}
