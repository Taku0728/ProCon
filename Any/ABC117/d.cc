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
	int N, K;
	cin >> N >> K;
	map<int, ll> n_max;
	vector<pair<int, ll> > al;
	for (int i = 0; i != N; ++i) {
		int t;
		ll d;
		cin >> t >> d;
		n_max[t] = max(n_max[t], d);
		al.push_back(pair<int, ll>(t, d));
	}
	sort(begin(al), end(al), [](auto l, auto r){ return l.second > r.second; });
	map<int, int> num;
	vector<ll> a;
	ll oishi = 0;
	for (int i = 0; i != K; ++i) {
		++num[al[i].first];
		if (num[al[i].first] > 1) {
			a.push_back(al[i].second);
		}
		oishi += al[i].second;
	}
	vector<ll> b;
	for (auto it = begin(n_max); it != end(n_max); ++it) {
		if (num.count(it->first) == 0) {
			b.push_back(it->second);
		}
	}
	int count = num.size();
	ll best = count * count + oishi;
	sort(begin(a), end(a));
	sort(begin(b), end(b), [](auto l, auto r){ return l > r; });
	for (int i = 0; i < a.size() && i < b.size(); ++i) {
		oishi += - a[i] + b[i];
		++count;
		best = max(best, count * count + oishi);
	}
	cout << best << endl;
	return 0;
}
