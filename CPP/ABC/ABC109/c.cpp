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

template<class T>
T GCD(T a, T b) {
	T c = max(a, b);
	T d = min(a, b);
	while (c%d != 0) {
		T t = d;
		d = c % d;
		c = t;
	}
	return d;
}

int main() {
	int n, x;
	cin >> n >> x;
	int a, b, t;
	rep(i, 0, n) {
		if (i == 0) {
			cin >> a;
			a = abs(a - x);
			t = a;
			continue;
		}
		if (i == 1) {
			cin >> b;
			b = abs(b - x);
			t = GCD(a, b);
			continue;
		}
		int c;
		cin >> c;
		c = abs(c - x);
		t = GCD(t, c);
	}
	cout << t << endl;
}
