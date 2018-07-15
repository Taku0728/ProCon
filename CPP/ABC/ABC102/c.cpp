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
	ll sum = 0;
	ll n = 0;
	vll A;
	rep(i, 0, N) {
		n += 1;
		ll a;
		cin >> a;
		a -= n;
		sum += a;
		A.push_back(a);
	}
	ll b0 = ll(floor(sum / double(n)));
	ll b1 = ll(ceil(sum / double(n)));
	ll out0 = 0, out1 = 0;
	repv(i, A) {
		out0 += ll(abs(A[i] - b0));
	}
	repv(i, A) {
		out1 += ll(abs(A[i] - b1));
	}
	cout << min(out0, out1) << endl;
    return 0;
}
