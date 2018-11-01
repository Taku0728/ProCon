#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	int N, T;
	// N(ルート数)とT(時間制限))を受け取る
	cin >> N >> T;
	// a(最小コスト)の初期値を9999
	int a = 9999;
	// N回のループ
	for (int i = 0; i != N; ++i) {
		int c, t;
		// c(コスト)とt(時間)を受け取る
		cin >> c >> t;
		// tがT以下の場合、最小コストを更新
		if (t <= T) {
			a = min(a, c);
		}
	}
	// aが更新されていなければTLE
	if (a == 9999) {
		cout << "TLE" << endl;
	}
	// 更新されていればそれを出力
	else {
		cout << a << endl;
	}
	return 0;
}
