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

ll mod = 0;

int main() {
	ll n;
	cin >> n >> mod;
	vector<ll> v(0);
	rep(i, 0, n) {
		ll a;
		cin >> a;
		a %= mod;
		v.push_back(a);
	}
	ll sum(0);
	vector<pllll> vs(0);
	rep(i, 0, n) {
		bool flag(false);
		ll a = v[i];
		repv(j, vs) {
			vs[j].first += a;
			vs[j].first %= mod;
			if (vs[j].first == a) {
				++vs[j].second;
				flag = true;
			}
			if (vs[j].first == 0) {
				sum += vs[j].second;
			}
		}
		if (!flag) {
			vs.push_back(pllll(a, 1));
			if (a == 0) {
				++sum;
			}
		}
	}
	cout << sum << endl;
}
