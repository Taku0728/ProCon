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

class pid{
public:
	int first;
	double second; 
	pid(int a, double b):first(a),second(b){
	}
};

int main() {
	int d, g;
	vector<pid> v;
	int tab[10][3];
	cin >> d >> g;
	rep(i, 0, d) {
		int p, c;
		cin >> p >> c;
		tab[i][0] = p;
		tab[i][1] = c;
		tab[i][2] = 1;
		v.push_back(pid(p, double(100*(i+1)*p+c)/p));
	}
	sort(all(v), [](pid &a, pid &b){ return a.second > b.second; });
	int s = 0;
	rep(i, 0, d) {
		int loc = v[i].first;
		if (g <= 100*(loc+1)*tab[loc][0] + tab[loc][1]) {
			int m = 100;
			rep(j, 0, d) {
				if (tab[j][2] && g <= 100*(j+1)*tab[j][0] + tab[j][1]) {
					int a = 0;
					if (g % (100*(j+1)*tab[j][0]) == 0) {
						a = g / (100*(j+1)*tab[j][0]);
					}
					else {
						a = g / (100*(j+1)*tab[j][0]) + 1;
					}
					a = min(a, tab[j][0]);
					m = min(m, a);
				}
			}
			s += m;
			break;
		}
		else {
			g -= 100*(loc+1)*tab[loc][0] + tab[loc][1];
			s += tab[loc][0];
			tab[loc][2] = 0;
		}
	}
	cout << s << endl;
}
