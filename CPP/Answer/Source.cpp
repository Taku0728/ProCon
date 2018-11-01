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

int main() {
	ll N;
	cin >> N;
	vector<ll> a;
	for (ll i = 0; i != N; ++i) {
		ll c;
		cin >> c;
		a.push_back(c);
	}
	if (N == 2) {
		cout << abs(a[0] - a[1]) << endl;
		return 0;
	}
	sort(begin(a), end(a));
	vector<ll> small;
	for (ll i = 0; i < ll(a.size()/2) + a.size()%2; i += 2) {
		small.insert(begin(small), a[i]);
		if (i + 1 < ll(a.size()/2) + a.size()%2) {
			small.push_back(a[i + 1]);
		}
	}
	vector<ll> big;
	for (ll i = a.size() - 1; i >= ll(a.size()/2) + a.size()%2; i -= 2) {
		big.push_back(a[i]);
		big.insert(begin(big), a[i]);
		if (i - 1 >= ll(a.size()/2) + a.size()%2) {
			big.push_back(a[i - 1]);
		}
	}
	ll sum = 0;
	ll sum0 = 0;
	for (ll i = 0; i < big.size(); ++i) {
		sum0 += big[i] - small[i];
		if (i + 1 < small.size()) {
			sum0 += big[i] - small[i + 1];
		}
	}
	sum = max(sum, sum0);
	sum0 = 0;
	ll pa = big[0];
	for (ll i = 0; i < small.size(); ++i) {
		sum0 += abs(pa - small[i]);
		if (i + 1 < big.size()) {
			sum0 += big[i + 1] - small[i];
			pa = big[i + 1];
		}
		else {
			pa = small[i];
		}
	}
	sum = max(sum, sum0);
	sum0 = 0;
	small.insert(begin(small), small[small.size() - 1]);
	small.erase(end(small) - 1);
	for (ll i = 0; i < big.size(); ++i) {
		sum0 += big[i] - small[i];
		if (i + 1 < small.size()) {
			sum0 += big[i] - small[i + 1];
		}
	}
	sum = max(sum, sum0);
	sum0 = 0;
	for (ll i = 0; i < small.size(); ++i) {
		sum0 += abs(pa - small[i]);
		if (i + 1 < big.size()) {
			sum0 += big[i + 1] - small[i];
			pa = big[i + 1];
		}
		else {
			pa = small[i];
		}
	}
	sum = max(sum, sum0);
	sum0 = 0;

	big.insert(begin(big), big[big.size() - 1]);
	big.erase(end(big) - 1);
	for (ll i = 0; i < big.size(); ++i) {
		sum0 += big[i] - small[i];
		if (i + 1 < small.size()) {
			sum0 += big[i] - small[i + 1];
		}
	}
	sum = max(sum, sum0);
	sum0 = 0;
	for (ll i = 0; i < small.size(); ++i) {
		sum0 += abs(pa - small[i]);
		if (i + 1 < big.size()) {
			sum0 += big[i + 1] - small[i];
			pa = big[i + 1];
		}
		else {
			pa = small[i];
		}
	}
	sum = max(sum, sum0);
	sum0 = 0;

	cout << sum << endl;
}

