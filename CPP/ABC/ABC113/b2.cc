#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, T, A;
	cin >> N >> T >> A;
	double min_dis = 9999;
	int ind = 0;
	for (int i = 0; i != N; ++i) {
		int H;
		cin >> H;
		double t = T - H * 0.006;
		if (min_dis > abs(T - t)) {
			min_dis = abs(T - t);
			ind = i + 1;
		}
	}
	cout << ind << endl;
	return 0;
}
