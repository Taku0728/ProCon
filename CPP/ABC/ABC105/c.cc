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
using vpii = vector<pii>;
using pqi = priority_queue<int>;
using pqd = priority_queue<double>;
using pqll = priority_queue<ll>;
using pqvi = priority_queue<vi>;
using pqvll = priority_queue<vll>;

ll dig(ll n) {
	if (n == 0) {
		return 0;
	}
	ll i = 1;
	ll j = 1;
	ll d = 0;
	if (n > 0) {
		i = 1;
		while (1) {
			if (n <= i) {
				return d;
			}
			j *= 4;
			i += j;
			d += 2;
		}
	}
	else {
		++d;
		i = -2;
		j = -2;
		while (1) {
			if (i <= n) {
				return d;
			}
			j *= 4;
			i += j;
			d += 2;
		}

	}
}

int main() {
	ll n;
	cin >> n;
	vi v(100, 0);
	ll md = 0;
	while (n != 0) {
		ll d = dig(n);
		md = max(md, d);
		v[d] = 1;
		ll a = 1;
		rep(i, 0, d) {
			a *= -2;
		}
		n -= a;
	}
	repr(i, md + 1, 0) {
		cout << v[i];
	}
	cout << endl;
}
