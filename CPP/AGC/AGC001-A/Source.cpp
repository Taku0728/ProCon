#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> L;

void input() {
	scanf_s("%d", &N);
	for (int i(0); i < 2*N; ++i) {
		int t;
		scanf_s("%d", &t);
		L.emplace_back(t);
	}
}

int main() {
	input();
	sort(L.begin(), L.end());
	int sum(0);
	for (int i(0); i < N; ++i) {
		sum += L[2 * i];
	}
	printf("%d", sum);
	return 0;
}