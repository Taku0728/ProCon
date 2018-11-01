#include <iostream>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))

using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;
	rep(i, 0, k) {
		if (s[i] > '1') {
			cout << s[i] << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
