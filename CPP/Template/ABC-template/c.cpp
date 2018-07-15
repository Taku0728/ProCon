
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

int main(){
	int n;
	ll sum;
	cin >> n;
	string s;
	cin >> s;
	vi va(n);
	repv(i, va) {
		va.push_back(i);
	}
	while(1) {
		bool flag = false;
		rep (i, 0, n) {
			if (va[n - i] == 2*n - i - 1) {
				continue;
			}
			int t = va[n - i];
			rep (j, 0, i + 1) {
				va[n - j - i] = t;
				++t;
			}
			flag = true;
			break;
		}
		if (flag) {
			string s0;
			string s1;
			int j = 0;
			repv (i, s) {
				if (va[j] == i) {
					s0 += s[i];
					++j;
				}
				else {
					s1.insert(s1.begin(), s[i]);
				}
			}
			if (s0 == s1) {
				++sum;
			}
		}
	}
}
