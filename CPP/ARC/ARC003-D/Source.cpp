#include <cstdio>
#include <random>
using namespace std;

int N, M, K;
int P[10][2];
int t1, t2;
random_device rnd;
mt19937 mt(rnd());

void input() {
	scanf_s("%d %d %d", &N, &M, &K);
	for (int i(0); i < M; ++i) {
		scanf_s("%d %d", &P[i][0], &P[i][1]);
	}
}

bool trail() {
	uniform_int_distribution<> rnd10(0, N - 1);
	int T[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i(0); i < K; ++i) {
		t1 = rnd10(mt);
		while (1) {
			t2 = rnd10(mt);
			if (t1 != t2) {
				break;
			}
		}
		swap(T[t1],T[t2]);
	}
	for (int i(0); i < N - 1; ++i) {
		for (int j(0); j < M; ++j) {
			if (T[i] == P[j][0] && T[i + 1] == P[j][1]) {
				return false;
			}
			else if (T[i] == P[j][1] && T[i + 1] == P[j][0]) {
				return false;
			}
		}
	}
	for (int j(0); j < M; ++j) {
		if (T[N - 1] == P[j][0] && T[0] == P[j][1]) {
			return false;
		}
		else if (T[N - 1] == P[j][1] && T[0] == P[j][0]) {
			return false;
		}
	}
	return true;
}

int main() {
	input();
	int count0(0);
	int count1(0);
	for (int i(0); i < 5000000; ++i) {
		if (trail()) {
			++count1;
		}
		else {
			++count0;
		}
	}
	printf("%14.12f", double(count1) / double(count1 + count0));
	return 0;
}
