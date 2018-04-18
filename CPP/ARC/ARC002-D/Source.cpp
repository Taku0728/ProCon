#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int H;
int W;
char B[2000][2000];
vector<vector<int>> Bo;
vector<vector<int>> Bx;
vector<vector<int>> dspace;
//vector<vector<int>> sspace;

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
	//sspace.resize(4);
	dspace.resize(4);
	int dist(0);
	int counto(0);
	int countx(0);
	int sd(0);
	for (int i(0); i < H; ++i) {
		sd = 0;
		counto = 0;
		countx = 0;
		dist = 0;
		for (int j(0); j < W; ++j) {
			if (B[i][j] == 'o') {
				dist = 0;
				++counto;
				if (countx != 0) {
					if (sd == 1) {
						//sspace[3].emplace_back(countx);
					}
					else {
						dspace[3].emplace_back(countx);
					}
					countx = 0;
				}
			}
			else if (B[i][j] == 'x') {
				++countx;
				if (counto != 0) {
					switch (dist) {
					case 1:
						//sspace[0].emplace_back(i);
						//sspace[1].emplace_back(j - 1);
						//sspace[2].emplace_back(counto);
						sd = 1;
						break;
					case 2:
						dspace[0].emplace_back(i);
						dspace[1].emplace_back(j - 2);
						dspace[2].emplace_back(counto);
						sd = 2;
						break;
					default:
						if (dist % 2 == 1) {
							B[i][j - dist - 1] = '.';
							B[i][j - (dist + 3) / 2] = 'o';
							B[i][j] = '.';
							B[i][j - (dist - 1) / 2] = 'x';
							//sspace[0].emplace_back(i);
							//sspace[1].emplace_back(j - (dist + 1) / 2);
							//sspace[2].emplace_back(counto);
							sd = 1;
						}
						else {
							B[i][j - dist - 1] = '.';
							B[i][j - (dist + 4) / 2] = 'o';
							B[i][j] = '.';
							B[i][j - (dist - 2) / 2] = 'x';
							dspace[0].emplace_back(i);
							dspace[1].emplace_back(j - (dist + 2) / 2);
							dspace[2].emplace_back(counto);
							sd = 2;
						}
						break;
					}
					counto = 0;
				}
				dist = 0;
			}
			else {
				++dist;
			}
		}
		if (sd == 1) {
			//sspace[3].emplace_back(countx);
		}
		else if (sd == 2) {
			dspace[3].emplace_back(countx);
		}
		countx = 0;
	}
}

void solve3() {
	vector<vector<int>> value;
	value.resize(3);
	int leg(dspace[0].size());
	for (int i(0); i < leg; ++i) {
		value[0].emplace_back(dspace[2][i] + dspace[3][i]);
		value[1].emplace_back(dspace[0][i]);
		value[2].emplace_back(dspace[1][i]);
	}
	sort(value[0].begin(), value[0].end());
	int n(0);
	while (n < leg) {
		B[value[1][n]][value[2][n] - 1] = '.';
		B[value[1][n]][value[2][n]] = 'o';
		++n;
		if (n >= leg) {
			break;
		}
		B[value[1][n]][value[2][n] + 2] = '.';
		B[value[1][n]][value[2][n] + 1] = 'x';
		++n;
	}
	return;
}

int solve4() {
	int timeso(0);
	int timesx(0);
	for (int i(0); i < H; ++i) {
		int j(0);
		while (j < W) {
			if (B[i][j] == 'o' && B[i][j + 1] == '.' && B[i][j + 2] != 'x') {
				B[i][j] = '.';
				B[i][j + 1] = 'o';
				++timeso;
				j = 0;
			}
			++j;
		}
		j = 0;
		while (j < W) {
			if (B[i][W - j - 1] == 'x' && B[i][W - j - 2] == '.' && B[i][W - j - 3] != 'o') {
				B[i][W - j - 1] = '.';
				B[i][W - j - 2] = 'x';
				++timesx;
				j = 0;
			}
			++j;
		}
	}
	if (timesx > timeso) {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int ans(0);
	input();
	ans = solve1();
	if (ans == 1) {
		cout << "o";
		return 0;
	}
	else if (ans == 2) {
		cout << "x";
		return 0;
	}
	solve2();
	solve3();
	if (solve4() == 1) {
		cout << "o";
	}
	else {
		cout << "x";
	}
	return 0;
}