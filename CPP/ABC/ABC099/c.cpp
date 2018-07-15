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

bool once(int i) {
	int ii = i;
	while (ii % 6 == 0) {
		ii /= 6;
	}
	if (ii == 1) {
		return true;
	}
	int ij = i;
	while (ij % 9 == 0) {
		ij /= 9;
	}
	if (ij == 1) {
		return true;
	}
	return false;
}

class two {
public:
	int a;
	int b;
	two(int i, int j)
	:a(i), b(j)
	{};
};

bool operator>(const two &lhs, const two &rhs) {
	return lhs.a > rhs.b;
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vi T(1, 1);
	priority_queue<two, vector<two>, greater<two> > T0;
	T0.push(two(1, 1));

	T.reserve(n);
	int i = 1;
	while (i != n) {
		++i;
		int t = 99999;
		if (once(i)) {
			t = 1;
		}
		else {
			priority_queue<two, vector<two>, greater<two> > T1(T0);
			while (!T1.empty()) {
				two tt = T1.top();
				T1.pop();
				if (tt.a > t) {
					break;
				}
				t = min(t, tt.a + T[i - tt.b - 1]);
			}
		}
		T.emplace_back(t);
		T0.push(two(t, i));
	}
	cout << T[i - 1] << "\n";
    return 0;
}
