#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

double snk(ll n) {
	ll nn = n;
	ll s = 0;
	while (nn > 0) {
		s += nn % 10;
		nn /= 10;
	}
	return double(n) / s;
}

ll nextdig(ll n) {
	ll nn = n;
	ll s = 1;
	while (nn > 0) {
		s *= 10;
		nn /= 10;
	}
	return s;
}

bool clear(ll n, ll d) {
	ll nn = n;
	double snkn = snk(n);
	ll lim = nextdig(n);
	bool b(true);
	while (nn < lim) {
		nn += d;
		if (snk(nn) < snkn) {
			b = false;
			break;
		}
	}
	return b;
}

int main() {
	int K;
	cin >> K;
	vll v(1, 1);
	ll a = 1;
	ll d = 1;
	while (v.size() < K) {
		ll n = 1;
		while (1) {
			ll aa = a + n * d;
			if (clear(aa, d)) {
				v.emplace_back(aa);
				a = aa;
				d = n * d;
				break;
			}
			++n;
		}
	}
	for (int i(0); i < v.size(); ++i) {
		cout << v[i] << "\n";
	}
	return 0;
}