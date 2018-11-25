#include <bits/stdc++.h>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	rep(i, 1, n + 1) {
		if (i % 2 == 0) {
			continue;
		}
		int y = 0;
		rep(j, 1, i + 1) {
			if (i % j == 0) {
				++y;
			}
		}
		if (y == 8) {
			++sum;
		}
	}
	cout << sum << endl;
}
