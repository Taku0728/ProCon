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

int main() {
	int n;
	cin >> n;
	pair<int, int> max00 = pair<int, int>(0, 0);
	pair<int, int> max01 = pair<int, int>(0, 0);
	pair<int, int> max10 = pair<int, int>(0, 0);
	pair<int, int> max11 = pair<int, int>(0, 0);
	map<int, int> m0;
	map<int, int> m1;
	for (int i = 0; i != n; ++i) {
		int v;
		cin >> v;
		if (i % 2 ==0) {
			++m0[v];
		}
		else {
			++m1[v];
		}
	}
	vector< pair<int, int> > vp;
	for (auto x : m0) {
		vp.push_back(pair<int, int>(x.first, x.second))
	}
	
	cout << n - max0 - max1 << endl;
	return 0;
}
