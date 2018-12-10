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

ll eat(ll x, ll i, ll s[51], ll p[51]) {
	if (x <= 0) {
		return 0;
	}
	if (i == 0) {
		return 1;
	}
	if (x >= s[i] - i + 1) {
		return p[i];
	}
	else if (x >= s[i-1] + 1) {
		ll r = 0;
		if (x >= s[i-1] + 2) {
			++r;
		}
		r += p[i-1];
		return r + eat(x - s[i-1] - 2, i-1, s, p);
	}
	else {
		return eat(x - 1, i-1, s, p);
	}
}

int main() {
	ll N, X;
	cin >> N >> X;
	ll s[51];
	s[0] = 1; 
	for (ll i = 1; i <= N; ++i) {
		s[i] = 2 * s[i - 1] + 3;
	}
	ll p[51];
	p[0] = 1; 
	for (ll i = 1; i <= N; ++i) {
		p[i] = 2 * p[i - 1] + 1;
	}
	cout << eat(X, N, s, p) << endl;
	return 0;
}
