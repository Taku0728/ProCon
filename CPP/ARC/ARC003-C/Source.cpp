#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int M;
char c[500][500];
<<<<<<< HEAD
int sc[2];
int gc[2];
int mov(0);
bool cmo[500][500] = {};

int ctimelimit[500][500];
double cmaxb[500][500];
int croute[500][500];
=======
int ci[500][500];
int sc[2];
int gc[2];
bool cmo[500][500] = {};

int ctimelimit[500][500] = {};
int cmint[500][500];
bool croute[510][510];
>>>>>>> parent of 2f3d61c... 1

void input() {
	scanf_s("%d%d", &N, &M);
	for (int i(0); i < N; ++i) {
<<<<<<< HEAD
		scanf_s("%s", c[i],500);
=======
		scanf_s("%s", c[i], 501);
>>>>>>> parent of 2f3d61c... 1
	}
	//scanf("%d%d", &N, &M);
	//for (int i(0); i < N; ++i) {
	//	scanf("%s", c[i]);
	//}
}

<<<<<<< HEAD
void initialize() {
	mov = N * M - 1;
=======
void init() {
>>>>>>> parent of 2f3d61c... 1
	//s‚Æg‚ÌêŠ‚ğŠm”F
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			if (c[i][j] == 's') {
				sc[0] = i;
				sc[1] = j;
<<<<<<< HEAD
=======
				ci[i][j] = 9;
>>>>>>> parent of 2f3d61c... 1
			}
			else if (c[i][j] == 'g') {
				gc[0] = i;
				gc[1] = j;
			}
<<<<<<< HEAD
			else if(c[i][j] == '#') {
				--mov;
=======
			else if (c[i][j] != '#') {
				ci[i][j] = c[i][j] - '0';
>>>>>>> parent of 2f3d61c... 1
			}
		}
	}
}

<<<<<<< HEAD
=======
void caltime(double bri) {
	int time[10];
	for (int i(1); i < 10; ++i) {
		if (i <= bri) {
			time[i] = 0;
		}
		else {
			time[i] = int(log(bri / double(i)) / log(0.99));
		}
	}
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			if (c[i][j] != 's' && c[i][j] != 'g' && c[i][j] != '#') {
				ctimelimit[i][j] = time[ci[i][j]];
			}
		}
	}
	return;
}

>>>>>>> parent of 2f3d61c... 1
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

<<<<<<< HEAD
int solve1() {
	if (spread(sc[0],sc[1])){
	}


	return 0;
=======
double spreadrd(int i, int j, int di, int dj, int t);

double spreadr(int i, int j, int t) {
	cmint[i][j] = t;
	int di(1);
	if (i > gc[0]) di = -1;
	int dj(1);
	if (j > gc[1]) dj = -1;
	if (abs(gc[0] - i) - abs(gc[1] - j) > 0) {
		double tem = spreadrd(i, j, di, 0, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
		tem = spreadrd(i, j, 0, dj, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
		tem = spreadrd(i, j, 0, -dj, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
		tem = spreadrd(i, j, -di, 0, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
	}
	else {
		double tem = spreadrd(i, j, 0, dj, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
		tem = spreadrd(i, j, di, 0, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
		tem = spreadrd(i, j, -di, 0, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
		tem = spreadrd(i, j, 0, -dj, t);
		if (tem < 10) return min(tem, double(ci[i][j]) * pow(0.99, t));
	}
	return 11;
}

void tswap(bool &b1, bool &b2) {
	bool tem(b1);
	b1 = b2;
	b2 = tem;
	return;
}

double spreadrd(int i, int j, int di, int dj, int t) {
	if (croute[i + di + 1][j + dj + 1]) {
		if (c[i + di][j + dj] == 'g') {
			return 9;
		}
		else if (t < ctimelimit[i + di][j + dj] &&
			t + 1 < cmint[i + di][j + dj] &&
			c[i + di][j + dj] != '#') {
			bool t1(false), t2(false), t3(false), t4(false);
			tswap(croute[i + 2][j + 1], t1);
			tswap(croute[i + 1][j + 2], t2);
			tswap(croute[i][j + 1], t3);
			tswap(croute[i + 1][j], t4);
			double tem = spreadr(i + di, j + dj, t + 1);
			if (tem < 10) return tem;
			else {
				tswap(croute[i + 2][j + 1], t1);
				tswap(croute[i + 1][j + 2], t2);
				tswap(croute[i][j + 1], t3);
				tswap(croute[i + 1][j], t4);
			}
		}
	}
	return 11;
}

void init2() {
	for (int i(1); i < N + 1; ++i) {
		for (int j(1); j < M + 1; ++j) {
			croute[i][j] = true;
		}
	}
	for (int i(0); i < N + 2; ++i) {
		croute[i][0] = false;
		croute[i][M + 1] = false;
	}
	for (int j(0); j < M + 2; ++j) {
		croute[0][j] = false;
		croute[N + 1][j] = false;
	}
	croute[sc[0] + 1][sc[1] + 1] = false;
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M; ++j) {
			cmint[i][j] = 999999;
		}
	}
}

double solve() {
	double bmax(9);
	double bmin(0);

	while (bmax - bmin > 2E-9) {
		init2();
		double bave((bmax + bmin) / 2.0);
		caltime(bave);
		double tem = spreadr(sc[0], sc[1], 0);
		if (tem < 10) {
			bmin = tem;
		}
		else {
			bmax = bave;
		}
	}
	return (bmax + bmin) / 2.0;
>>>>>>> parent of 2f3d61c... 1
}

int main() {
	input();
<<<<<<< HEAD
	initialize();
	if (!spread(sc[0], sc[1])) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", 1);
	}
	printf("%d\n", 0);
=======
	init();
	if (!spread(sc[0], sc[1])) {
		printf("%d\n", -1);
		return 0;
	}
	double ans = solve();
	printf("%16.14f\n", ans);
>>>>>>> parent of 2f3d61c... 1
	return 0;
}