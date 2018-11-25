#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, t, a;
	cin >> n;
	cin >> t >> a;
	// ind:答え
	int ind = 0;
	// best:最も小さい温度差
	double best = 99999999;
	for (int i = 0; i != n; ++i) {
		int h;
		cin >> h;
		// cost:標高hの地点の温度差 
		double cost = abs(a - (t - h * 0.006));
		// 温度差がいままでの最小より小さければ更新
		if (cost < best) {
			best = cost;
			// 番号を記録
			ind = i + 1;
		}
	}
	cout << ind << endl;
}

