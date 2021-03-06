#include<iostream>
#include<math.h>
#include<random>
#include "Source.h"

using namespace std;

int main() {
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::uniform_int_distribution<> rand100(0, 99);        // [0, 100] 範囲の一様乱数
	int H;
	int W;
	cin >> H;
	cin >> W;
	int con(0);
	for (int i(0); i < H; ++i) {
		cout << "o";
		con = 1;
		for (int j(0); j < W - 3; ++j) {
			float t = rand100(rnd) / 100.0;
			if (con == 0) {
				if (t < 0.33) {
					cout << "o";
					con = 1;
				}
				else if (t < 0.66) {
					cout << "x";
					con = 2;
				}
				else {
					cout << ".";
					con = 0;
				}
			}
			else if (con == 1) {
				if (t < 0.5) {
					cout << "o";
					con = 1;
				}
				else {
					cout << ".";
					con = 0;
				}
			}
			else {
				if (t < 0.5) {
					cout << "x";
					con = 2;
				}
				else {
					cout << ".";
					con = 0;
				}
			}
		}
		cout << ".";
		cout << "x\n";
	}

	return 0;
}