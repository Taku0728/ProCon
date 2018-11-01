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

ll mod = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	ll n = 1;
	ll a = 0;
	ll ab = 0;
	ll abc = 0;
	repv(i, s) {
		if (s[i] == 'A') {
			a += n;
			a %= mod;
		}
		else if (s[i] == 'B') {
			ab += a;
			ab %= mod;
		}
		else if (s[i] == 'C') {
			abc += ab;
			abc %= mod;
		}
		else if (s[i] == '?') {
			abc += 2 * abc + ab;
			abc %= mod;
			ab += 2 * ab + a;
			ab %= mod;
			a += 2 * a + n;
			a %= mod;
			n *= 3;
			n %= mod;
		}
	}
	cout << abc << endl;
}
