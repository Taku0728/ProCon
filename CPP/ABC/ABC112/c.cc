#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> vx, vy, vh;
	for (int i = 0; i != N; ++i) {
		int x, y, h;
		cin >> x >> y >> h;
		vx.push_back(x);
		vy.push_back(y);
		vh.push_back(h);
	}
	// すべての座標(i, j)について全探索
	// つまり全ての座標について頂点かどうか確認する
	for (int i = 0; i != 101; ++i) {
		for (int j = 0; j != 101; ++j) {
			// 高さが0でないところを一つ探す
			int k = 0;
			while(vh[k] == 0) {
				++k;
			}
			// その高さから頂点の高さHを計算する
			int H = int(abs(vx[k]-i)) + int(abs(vy[k]-j)) + vh[k];
			bool b = true;
			k = 0;
			// すべての点について高さhが正しいか検証
			while(k < vh.size()) {
				if (vh[k] != max(H - int(abs(vx[k]-i)) - int(abs(vy[k]-j)), 0)) {
					b = false;
					break;
				}
				++k;
			}
			// すべての高さが正しければ頂点の座標と高さを出力する
			if (b) {
				cout << i << " " << j << " " << H << endl;
				return 0;
			}
		}
	}
}
