#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int mod = 1e9+7;

int main() {
	int H, W, K;
	cin >> H >> W >> K;
	ll dp[101][9] = {0};
	dp[1][0] = 1;
	vector<int> com(9, 1);
	for (int i = 2; i != 9; ++i) {
		com[i] = com[max(0, i - 1)] + com[max(0, i - 2)];
	}
	for (int j = 1; j != H + 1; ++j) {
		for (int i = 1; i != W + 1; ++i) {
			dp[i][j] += dp[i-1][j-1] * com[max(0,i-2)] * com[W-i+1];
			dp[i][j] %= mod;
			dp[i][j] += dp[i][j-1] * com[i-1] * com[W-i];
			dp[i][j] %= mod;
			dp[i][j] += dp[i+1][j-1] * com[i] * com[W-i];
			dp[i][j] %= mod;
		}
	}

	for (int j = 0; j != H + 1; ++j) {
		for (int i = 1; i != W + 1; ++i) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[K][H] << endl;
}
