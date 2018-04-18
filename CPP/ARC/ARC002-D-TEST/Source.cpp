#include<iostream>
#include<math.h>
#include<random>
#include "Source.h"

using namespace std;

int main() {
	std::random_device rnd;     // ”ñŒˆ’è“I‚È—”¶¬Ší‚ğ¶¬
	std::uniform_int_distribution<> rand100(0, 99);        // [0, 100] ”ÍˆÍ‚Ìˆê—l—”
	int H;
	int W;
	cin >> H;
	cin >> W;
	int con(0);
	for (int i(0); i < H; ++i) {
		cout << ".";
		cout << "o";
		con = 1;
		for (int j(0); j < W - 5; ++j) {
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
		float t = rand100(rnd) / 100.0;
		cout << ".x";
		cout << "." << endl;
	}

	return 0;
}