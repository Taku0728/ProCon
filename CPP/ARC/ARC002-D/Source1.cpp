#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int H;
int W;
char B[2010][2010];
vector<vector<int>> Bo;
vector<vector<int>> Bx;
vector<vector<int>> value;

void input() {
	cin >> H >> W;
	for (int i(0); i < H; ++i) {
		cin >> B[i];
	}
}

int solve1() {
	int minx(9999);
	int mino(9999);
	for (int i(0); i < H; ++i) {
		for (int j(0); j < W; ++j) {
			if (B[i][j] == 'o') {
				break;
			}
			if (B[i][j] == 'x') {
				if (j < minx) {
					minx = j;
				}
				break;
			}
		}
	}
	for (int i(0); i < H; ++i) {
		for (int j(0); j < W; ++j) {
			if (B[i][W - j - 1] == 'x') {
				break;
			}
			if (B[i][W - j - 1] == 'o') {
				if (j < mino) {
					mino = j;
				}
				break;
			}
		}
	}
	if (minx == 9999 && mino == 9999) {
		return 0;
	}
	if (minx < mino) {
		return 2;
	}
	else {
		return 1;
	}
}

void solve2() {
	vector<int> temv(3, 0);
	int dist(0);
	int counto(0);
	int countx(0);
	int ready(0);
	for (int i(0); i < H; ++i) {
		counto = 0;
		countx = 0;
		dist = 0;
		for (int j(0); j < W; ++j) {
			if (B[i][j] == 'o') {
				dist = 0;
				++counto;
				if (ready) {
					temv[0] += countx;
					value.emplace_back(temv);
					ready = 0;
				}
				countx = 0;
			}
			else if (B[i][j] == 'x') {
				++countx;
				if (counto != 0) {
					if (dist == 2) {
						temv[0] = counto;
						temv[1] = i;
						temv[2] = j - 2;
						ready = 1;
					}
					else if (dist > 2) {
						if (dist % 2 == 1) {
							B[i][j - dist - 1] = '.';
							B[i][j - (dist + 3) / 2] = 'o';
							B[i][j] = '.';
							B[i][j - (dist - 1) / 2] = 'x';
						}
						else {
							B[i][j - dist - 1] = '.';
							B[i][j - (dist + 4) / 2] = 'o';
							B[i][j] = '.';
							B[i][j - (dist - 2) / 2] = 'x';
							temv[0] = counto;
							temv[1] = i;
							temv[2] = j - (dist + 2) / 2;
							ready = 1;
						}
					}
					counto = 0;
				}
				dist = 0;
			}
			else {
				if (counto != 0) {
					++dist;
				}
			}
		}
		if (ready) {
			temv[0] += countx;
			value.emplace_back(temv);
			ready = 0;
		}
	}
}

void solve3() {
	int leg(value.size());
	sort(value.begin(), value.end());
	reverse(value.begin(), value.end());
	int n(0);
	while (n < leg) {
		B[value[n][1]][value[n][2] - 1] = '.';
		B[value[n][1]][value[n][2]] = 'o';
		++n;
		if (n == leg) {
			break;
		}
		B[value[n][1]][value[n][2] + 2] = '.';
		B[value[n][1]][value[n][2] + 1] = 'x';
		++n;
	}
	return;
}

int solve4() {
	int timeso(0);
	int timesx(0);
	for (int i(0); i < H; ++i) {
		int j(0);
		int layer(0);
		while (j < W) {
			if (B[i][j] == 'o') {
				++layer;
			}
			else if (B[i][j] == '.') {
				timeso += layer;
			}
			else {
				if (layer) {
					timeso -= layer;
					layer = 0;
				}
			}
			++j;
		}
		j = W - 1;
		while (j >= 0) {
			if (B[i][j] == 'x') {
				++layer;
			}
			else if (B[i][j] == '.') {
				timesx += layer;
			}
			else {
				if (layer) {
					timesx -= layer;
					layer = 0;
				}
			}
			--j;
		}
	}
	if (timesx < timeso) {
		return 1;
	}
	else {
		return 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int ans(0);
	input();
	ans = solve1();

	if (ans == 1) {
		cout << "o" << endl;
		return 0;
	}
	else if (ans == 2) {
		cout << "x" << endl;
		return 0;
	}
	solve2();
	solve3();
	if (solve4() == 1) {
		cout << "o" << endl;
	}
	else {
		cout << "x" << endl;
	}
	return 0;
}