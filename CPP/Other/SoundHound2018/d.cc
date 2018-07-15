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

const ll fond = 1e16;

class two {
public:
	int loc;
	ll snk;
	bool en;
	two(int l, ll s, bool e)
	:loc(l), snk(s), en(e){};
};

bool operator>(const two &l, const two &r) {
	return l.snk > r.snk; 
};

bool operator<(const two &l, const two &r) {
	return l.snk < r.snk; 
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	vvi uvab;
	rep(i, 0, m) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		uvab.push_back({u, v, a, b});
	}
	rep(i, 0, n) {
		vll maxsnk0(n + 1, 0);
		vll maxsnk1(n + 1, 0);
		priority_queue<two, vector<two>, greater<two> > pq;
		pq.push(two(s, fond, true));
		maxsnk0[s] = fond;
		if (s > i) {
			pq.push(two(s, fond, false));
			maxsnk1[s] = fond;
		}
		while (!pq.empty()) {
			two set = pq.top();
			pq.pop();
			rep(j, 0, m) {
				if (set.loc == uvab[j][0] || set.loc == uvab[j][1]) {
					int s1 = set.loc == uvab[j][0] ? uvab[j][1] : uvab[j][0];
					ll rest = set.snk - (set.en ? uvab[j][2] : uvab[j][3]);
					if (s1 == t) {
						if (!set.en || s1 > i) {
							maxsnk1[s1] = max(set.en ? maxsnk0[s1] : maxsnk1[s1], rest);
						}
					}
					else if (set.en) {
						if (maxsnk0[s1] < rest) {
							pq.push(two(s1, rest, true));
							maxsnk0[s1] = rest;
							if (s1 > i) {
								pq.push(two(s1, rest, false));
								maxsnk1[s1] = rest;
							}
						}
					}
					else {
						if (maxsnk1[s1] < rest) {
							pq.push(two(s1, rest, false));
							maxsnk1[s1] = rest;
						}
					}
				}
			}
		}
		cout << maxsnk1[t] << endl;
	}
    return 0;
}
