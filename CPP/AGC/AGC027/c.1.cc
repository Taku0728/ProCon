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

int main() {
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	vvi ab;
	ab.resize(N + 1);
	bool check[200001] = {};
	bool again = false;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		ab[min(a,b)].push_back(max(a,b));
		check[a] = true;
		check[b] = true;
	}
	rep(i, 1, N + 1) {
		if (check[i]) {
			again = true;
		}
	}
	while (again) {
		bool checkn[200001] = {};
		again = false;
		rep(i, 1, N + 1) {
			if (!check[i]) {
				continue;
			}
			bool toab[2] = {false, false};
			bool fab = false;
			rep(j, 0, ab[i].size()) {
				if (s[ab[i][j] - 1] == 'A') {
					toab[0] = true;
					if (toab[1]) {
						fab = true;
						break;
					}
				}
				else if (s[ab[i][j] - 1] == 'B') {
					toab[1] = true;
					if (toab[0]) {
						fab = true;
						break;
					}
				}
			}
			if (!fab) {
				rep(k, 1, i) {
					int ind0 = 0;
					int ind1 = 1;
					if (s[k - 1] == 'B') {
						ind0 = 1;
						ind1 = 0;
					}
					repv(j, ab[k]) {
						if (ab[k][j] == i) {
							toab[ind0] = true;
							if (toab[ind1]) {
								fab = true;
								break;
							}
						}
					}
					if (fab) {
						break;
					}
				}
			}
			if (!fab) {
				rep(j, 0, ab[i].size()) {
					checkn[ab[i][j]] = true;
				}
				ab[i].resize(0);
				rep(k, 1, i) {
					repr(j, ab[k].size(), 0) {
						if (ab[k][j] == i) {
							ab[k].erase(begin(ab[k]) + j);
							checkn[k] = true;
						}
					}
				}
			}
		}
		rep(i, 1, N + 1) {
			if (checkn[i]) {
				again = true;
			}
			check[i] = checkn[i];
		}
	}
	rep(i, 0, N) {
		if (ab[i].size() > 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
