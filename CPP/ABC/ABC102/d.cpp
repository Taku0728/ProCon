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

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (unsigned (i)(0); (i)<(v.size()); ++(i))
#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define sortgi(v) sort(all(v), greater<int>())
#define sortgd(v) sort(all(v), greater<double>())
#define sortgll(v) sort(all(v), greater<ll>())
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using pii = pair<int, int>;
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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vll s;
	ll ss = 0;
	rep(i, 0, N) {
		ll a;
		cin >> a;
		ss += a;
		s.push_back(ss);
	}
	int l = 0, r = 2, t = s.size() - 1;
	ll c = s[t];
	rep(m, 1, t - 1) {
		vll pqrs;
		while (s[l] < s[m] - s[l + 1]) {
			++l;
		}
		pqrs.push_back(s[l]);
		pqrs.push_back(s[m] - s[l]);
		while (s[r] - s[m] < s[t] - s[r + 1]) {
			++r;
		}
		pqrs.push_back(s[r] - s[m]);
		pqrs.push_back(s[t] - s[r]);
		sortv(pqrs);
		c = min(c, pqrs[3] - pqrs[0]);
	}
	cout << c << endl;
    return 0;
}
