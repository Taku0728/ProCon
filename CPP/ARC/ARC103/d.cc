#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <chrono>

using namespace std;
using ll = long long;

int main() 
	int N;
	cin >> N;
	vector<int> X;
	vector<int> Y;
	int m;
	int x, y;
	cin >> x >> y;
	X.push_back(x);
	Y.push_back(y);
	bool even = ((x + y) % 2 == 0);
	bool ok = true;
	for (int i = 1; i != N; ++i) {
		int x, y;
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
		m = max(m, abs(x) + abs(y));
		if (even != ((x + y) % 2 == 0)) {
			ok = false;
		}
	}
if (!ok) {
	cout << - 1 << endl;
	return 0;
}
	string s("1");
	for (int i = 0; i != m - 1; ++i) {
		s += " 1";
	}
	cout << m << endl;
	cout << s << endl;
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j < (m - abs(X[i]) - abs(Y[i])) / 2; ++j) {
			cout << "UD";
		}
		string a0 = "R";
		string a1 = "U";
		if (X[i] < 0) {
			a0 = "L";
		}
		if (Y[i] < 0) {
			a1 = "D";
		}
		for (int j = 0; j != abs(X[i]); ++j) {
			cout << a0;
		}
		for (int j = 0; j != abs(Y[i]); ++j) {
			cout << a1;
		}
		cout << endl;
	}
	return 0;
}
