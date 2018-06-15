#include<iostream>
#include<random>
#include<algorithm>
#include<math.h>
using namespace std;
char c[500][500];

int main() {
	int N;
	int M;
	cin >> N >> M;
	random_device rnd;
	uniform_int_distribution<> nd10(0, 9);
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			int tem = nd10(rnd);
			if (tem == 0) {
				c[i][j] = '#';
			}
			else {
				c[i][j] = tem + '0';
			}
		}
	}
	uniform_int_distribution<> ndN(0, N - 1);
	uniform_int_distribution<> ndM(0, M - 1);
	c[ndN(rnd)][ndM(rnd)] = 's';
	while (1) {
		int tem1(ndN(rnd)), tem2(ndM(rnd));
		if (c[tem1][tem2] != 's') {
			c[tem1][tem2] = 'g';
			break;
		}
	}
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			cout << c[i][j];
		}
		cout << "\n";
	}
	return 0;

}