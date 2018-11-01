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
	int d, g;
	int tab[10][2];
	cin >> d >> g;
	rep(i, 0, d) {
		int p, c;
		cin >> p >> c;
		tab[i][0] = p;
		tab[i][1] = c;
	}
	int m = 99999;
	rep(i, 0, 1 << d) {
		int gg = g;
		int s = 0;
		rep(j, 0, d) {
			if (i >> j & 1) {
				gg -= 100 * (j + 1) * tab[j][0] + tab[j][1];
				s += tab[j][0];
			}
		}
		if (gg > 0) {
			repr(j, d, 0) {
				if (!(i >> j & 1)) {
					if (gg < 100 * (j + 1) * tab[j][0]) {
						s += gg / (100 * (j + 1)) + (gg % (100 * (j + 1)) != 0);
					}
					else {
						s = 99999;
					}
					break;
				}
			}
		}
		m = min(m, s);
	}
	cout << m << endl;

}
