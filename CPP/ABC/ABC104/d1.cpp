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

const ll mod = 1e9 + 7;

struct mll {
  ll n;
  mll(ll n = 0) : n(n) {}
};
 
mll operator+(mll a, mll b) { return (a.n += b.n) >= mod ? a.n - mod : a.n; }
mll operator-(mll a, mll b) { return (a.n -= b.n) < 0 ? a.n + mod : a.n; }
mll operator*(mll a, mll b) { return 1LL * a.n * b.n % mod; }
mll operator/(mll a, mll b) { return 1LL * a.n * mll(mod_inv(a.n, mod)); }
mll &operator+=(mll &a, mll b) { return a = a + b; }
mll &operator-=(mll &a, mll b) { return a = a - b; }
mll &operator*=(mll &a, mll b) { return a = a * b; }
mll &operator/=(mll &a, mll b) { return a = a / b; }
ostream &operator<<(ostream &o, mll a) { return o << a.n; }

int main() {
	string s;
	cin >> s;
	mll n = 1;
	mll a = 0;
	mll ab = 0;
	mll abc = 0;
	repv(i, s) {
		if (s[i] == 'A') {
			a += n;
		}
		else if (s[i] == 'B') {
			ab += a;
		}
		else if (s[i] == 'C') {
			abc += ab;
		}
		else if (s[i] == '?') {
			abc += 2 * abc + ab;
			ab += 2 * ab + a;
			a += 2 * a + n;
			n *= 3;
		}
	}
	cout << abc << endl;
}
