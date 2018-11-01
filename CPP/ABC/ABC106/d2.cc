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
void accum(vector<vector<T> > &v) {
	for (signed i(1); i < v.size(); ++i) {
		for (signed j(1); j < v[i].size(); ++j) {
			v[i][j] = v[i][j] + v[i][j - 1];
		}
	}
	for (signed i(1); i < v.size(); ++i) {
		for (signed j(1); j < v[i].size(); ++j) {
			v[j][i] = v[j][i] + v[j - 1][i];
		}
	}
}


int main() {
	int N, M, Q;
	scanf("%d %d %d", &N, &M ,&Q);
	vvi lr(N + 1, vi(N + 1, 0)); 
	rep(i, 0, M) {
		int l, r;
		scanf("%d %d", &l, &r);
		++lr[l][r];
	}
	accum(lr);
	rep(i, 0, Q) {
		int p, q;
		scanf("%d %d", &p, &q);
		printf("%d\n", lr[q][q] - lr[p-1][q] - lr[q][p-1] + lr[p-1][p-1]);
	}
}
