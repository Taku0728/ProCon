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

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repr(i, m, n) for (int (i)(m - 1); (i)>=(n); --(i))
#define repv(i, v) for (unsigned (i)(0); (i)<(v.size()); ++(i))
#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define sortgi(v) sort(all(v), greater<int>())
#define sortgd(v) sort(all(v), greater<double>())
#define sortgll(v) sort(all(v), greater<ll>())
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using pii = pair<int, int>;
using pss = pair<string, string>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using ll = long long;
using pllll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using pqi = priority_queue<int>;
using pqd = priority_queue<double>;
using pqll = priority_queue<ll>;
using pqvi = priority_queue<vi>;
using pqvll = priority_queue<vll>;

int main() {
	int n , m;
	cin >> n >> m;
	vector<pii> v;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		int aa = min(a, b), bb = max(a, b);
		v.push_back(pii(aa, bb));
	}
	int sum = 0;
	while  (!v.empty()) {
		++sum;
		int loc = 0;
		repv(i, v) {
			loc = max(loc, v[i].first);
		}
		sort(all(v), [](const pii &l, const pii &r)
		{return l.second < r.second;});
		bool f = true;
		repr(i, v.size(), 0) {
			if (v[i].second <= loc) {
				v.erase(v.begin() + i + 1, v.end());
				f = false;
				break;
			}
		}
		if (f) {
			break;
		}
	}
	cout << sum << endl;
}
