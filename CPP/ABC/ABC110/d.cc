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

vll prime(ll n) {
	vll p;
	map<ll, ll> mp;
	ll i = 2;
	while (n != 1) {
		while (n % i == 0) {
			n /= i;
			++mp[i];
		}
		++i;
	}
	for (auto j = mp.begin(); j != mp.end(); ++j) {
		p.push_back(j->second);
	}
	return p;
}

// モジュラ逆数 //
ll mod_inv(ll a, ll m) {
    ll b(m), u(1), v(0);
    while (b) {
        ll t(a / b);
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    if (u < 0) {
        u += m;
    }
    return u;
}

ll nCm(ll n, ll m, ll mod) {
	ll a = 1;
	m = min(n-m, m);
	rep(i, 0, m) {
		a *= n - i;
		a %= mod;
	}
	rep(i, 1, m + 1) {
		a *= mod_inv(i, mod);
		a %= mod;
	}
	return a;
}

int main() {
	ll N, M;
	cin >> N >> M;
	vll p = prime(M);
	ll a = 1;
	ll mod = 1e9 + 7;
	repv(i, p) {
		// cout << p[i] << endl;
		a *= nCm(p[i] + N - 1, N - 1, mod);
		a %= mod;
	}
	cout << a << endl;
}


