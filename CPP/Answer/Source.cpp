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

map <pss, int> mp;

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	rep(i, 0, 1<<n) {
		string s0, s1;
		int ii = i;
		rep(j, 0, n) {
			if (ii == 0) break;
			if (ii & 1) {
				s0 += s[j];
			}
			ii >>= 1;
		}
		ii = i;
		repr(j, n, 0) {
			if (ii > j) break;
			if (!(ii & 1)) {
				s1 += s[j];
			}
			ii <<= 1;
		}
		++mp[pss(s0, s1)];
	}
	ll ans = 0;
	rep(i, 0, 1<<n) {
		string s0, s1;
		int ii = i;
		rep(j, 0, n) {
			if (ii == 0) break;
			if (ii & 1) {
				s0 += s[n + j];
			}
			ii >>= 1;
		}
		ii = i;
		repr(j, n, 0) {
			if (ii == 0) break;
			if (!(ii & 1)) {
				s1 += s[n + j];
			}
			ii >>= 1;
		}
		ans += mp[pss(s1, s0)];
	}
	cout << ans << endl;
}
