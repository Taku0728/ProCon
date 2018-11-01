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

bool toab(const string &s, const vi &ab, const bool isNode[]) {
	bool toa = false, tob = false;
	repv(j, ab) {
		if (!isNode[ab[j]]) {
			continue;
		}
		if (s[ab[j] - 1] == 'A') {
			toa = true;
			if (tob) {
				return true;
			}
		}
		if (s[ab[j] - 1] == 'B') {
			tob = true;
			if (toa) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	vvi ab;
	ab.resize(N + 1);
	bool isNode[200001];
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		ab[a].push_back(b);
		if (a != b) {
			ab[b].push_back(a);
		}
		isNode[a] = true;
		isNode[b] = true;
	}
	queue<int> q;
	rep(i, 1, N + 1) {
		if (isNode[i]) {
			q.push(i);
		}
		while(!q.empty()) {
			int j = q.front();
			q.pop();
			if (!toab(s, ab[j], isNode)) {
				isNode[j] = false;
				repv(k, ab[j]) {
					if (isNode[ab[j][k]]) {
						q.push(ab[j][k]);
					}
				}
			}
		}
	}
	rep(i, 1, N + 1) {
		if (isNode[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
