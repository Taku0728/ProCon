#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int M;
char c[500][500];
int sc[2];
int gc[2];
int mov(0);
bool cmo[500][500] = {};

int ctimelimit[500][500];
double cmaxb[500][500];
int croute[500][500];

void input() {
	scanf_s("%d%d", &N, &M);
	for (int i(0); i < N; ++i) {
		scanf_s("%s", c[i],500);
	}
	//scanf("%d%d", &N, &M);
	//for (int i(0); i < N; ++i) {
	//	scanf("%s", c[i]);
	//}
}

void initialize() {
	mov = N * M - 1;
	//s‚Æg‚ÌêŠ‚ðŠm”F
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			if (c[i][j] == 's') {
				sc[0] = i;
				sc[1] = j;
			}
			else if (c[i][j] == 'g') {
				gc[0] = i;
				gc[1] = j;
			}
			else if(c[i][j] == '#') {
				--mov;
			}
		}
	}
}

bool spread(int i, int j) {
	if (cmo[i][j]) {
		return false;
	}
	else if (c[i][j] == 'g') {
		return true;
	}
	else if (c[i][j] == '#') {
		return false;
	}
	else {
		cmo[i][j] = true;
		if (i > 0) {
			if (spread(i - 1, j)) return true;
		}
		if (i < N - 1) {
			if (spread(i + 1, j)) return true;
		}
		if (j > 0) {
			if (spread(i, j - 1)) return true;
		}
		if (j < M - 1) {
			if (spread(i, j + 1)) return true;
		}
		return false;
	}
}

int solve1() {
	if (spread(sc[0],sc[1])){
	}


	return 0;
}

int main() {
	input();
	initialize();
	if (!spread(sc[0], sc[1])) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", 1);
	}
	printf("%d\n", 0);
	return 0;
}