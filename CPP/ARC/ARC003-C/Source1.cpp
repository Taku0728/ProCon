#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int M;
char c[501][501];
int ci[501][501];
int mint[501][501];
int sc[2];
const int dir[4][2] = { { 1,0 }, { -1,0 }, { 0,1 }, { 0,-1 } };

class D
{
public:
	int i;
	int j;
	int t;
	double b;
	bool operator < (const D &d) const {
		return b < d.b;
	}

private:

};


void input() {
	scanf_s("%d%d", &N, &M);
	for (int i(0); i < N; ++i) {
		scanf_s("%s", c[i], 510);
	}
	//scanf("%d%d", &N, &M);
	//for (int i(0); i < N; ++i) {
	//	scanf("%s", c[i]);
	//}
}

void init() {
	//s‚Æg‚ÌêŠ‚ðŠm”F
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			if (c[i][j] == 's') {
				sc[0] = i;
				sc[1] = j;
			}
			else if (c[i][j] != '#') {
				ci[i][j] = c[i][j] - '0';
			}
		}
	}
	fill(mint[0], mint[501], 999999);
}

double getAns() {
	priority_queue<D> que;
	que.push({ sc[0],sc[1],0,10.0 });
	while (!que.empty()) {
		const D d(que.top());
		que.pop();
		if (mint[d.i][d.j] < d.t) {
			continue;
		}
		for (int n(0); n < 4; ++n) {
			int i = d.i + dir[n][0];
			int j = d.j + dir[n][1];
			if (i < 0 || N <= i || j < 0 || M <= j) {
				continue;
			}
			if (c[i][j] == 'g') {
				return d.b;
			}
			if (c[i][j] == '#' || c[i][j] == 's') {
				continue;
			}
			if (d.t + 1 < mint[i][j]) {
				mint[i][j] = d.t + 1;
				que.push({ i, j, d.t + 1, min(d.b, ci[i][j]*pow(0.99, d.t + 1)) });
			}
		}
	}
	return -1;
}

int main() {
	input();
	init();
	double ans = getAns();
	if (ans >= 0) {
		printf("%16.14f\n", ans);
	}
	else {
		printf("%d\n", -1);
	}
	return 0;
}