#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <chrono>
using namespace std;
using ll = long long;


ll maxd(vector<ll> &v, ll maxa, ll k) {
	ll a = 1;
	while(maxa >= a) {
		a <<= 1;
	}
	a >>= 1;
	while (a > 0) {
		a >>= 1;
		ll count = 0;
		for (auto i : v) {
			if ((i & a) >= a) {
				++count;
				if (count == k) {
					return a;
				}
			}
		}
	}
	return a;
}

vector<ll> cut(vector<ll> &v, ll a) {
	vector<ll> vv(0);
	for (auto i : v) {
		if ((i & a) >= a) {
			vv.push_back(i);
		}
	}
	return vv;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	ll N, K;
	cin >> N >> K;
	ll s[1002][1002];
	for (ll i = 0; i != N; ++i) {
		for (ll j = 0; j <= N; ++j) {
			s[i][j] = 0;
		}
	}
	vector<ll> vs;
	for (ll i = 0; i != N; ++i) {
		ll a;
		cin >> a;
		for (ll j = 0; j <= i; ++j) {
			s[i + 1][j] = s[i][j] + a;
			vs.push_back(s[i + 1][j]);
		}
	}
	ll out = 0;
	ll a = 1e14;
	while (a > 0) {
		a = maxd(vs, a, K);
		out += a;
		vs = cut(vs, a);
		// for (auto i : vs) {
		// 	cout << i << endl;
		// }
		// cout << endl;
	}
	cout << out << endl;
}
