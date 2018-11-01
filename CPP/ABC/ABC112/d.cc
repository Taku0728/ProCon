#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// nの約数を求める
vector<long long> divisor(long long n) {
	vector<long long> d;
	for (ll i(1); i * i <= n; ++i) {
		if (n % i == 0) {
			d.push_back(i);
			if (i * i != n) d.push_back(n / i);
		}
	}
	return d;
}


int main() {
	ll N, M;
	cin >> N >> M;
	// dはnの約数のベクター
	vector<long long> d(divisor(M));
	// dをソート
	sort(begin(d), end(d));
	ll g = M / N;
	ll i(0);
	// g以下で最大の約数を調べる
	while (i < d.size() && d[i] <= g) {
		++i;
	}
	cout << d[i - 1] << endl;
}
