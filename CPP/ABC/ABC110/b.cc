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
using namespace std;

int main() {
	int n, m;
	int max_x;
	int min_y;
	cin >> n >> m >> max_x >> min_y;
	for (int i = 0; i < n; ++i) {
		int xx;
		cin >> xx;
		max_x = max(max_x, xx);
	}
	for (int i = 0; i < m; ++i) {
		int yy;
		cin >> yy;
		min_y = min(min_y, yy);
	}
	if (max_x < min_y) {
		cout << "No War" << endl;
	}
	else {
		cout << "War" << endl;
	}
}
