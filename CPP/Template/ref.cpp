#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <map>

#define rep(i, n, m) for (int(i)(n); (i)<(m);++(i))
using namespace std;
using ll = long long;

// split(文字列, 区切り文字) //
std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while( std::getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

// count(文字列全体, 数える文字列) //
int count(const std::string &lhs, const std::string &rhs)
{
    int n(0), s0(lhs.size()), s1(rhs.size());
    for (int i(0); i < s0 - s1 + 1; ++i) {
        if (rhs == lhs.substr(i, s1)) {
            ++n;
        }
    }
    return n;
}

// count(文字列全体, 数える文字) //
int count(const std::string &lhs, char rhs)
{
    int n(0);
    for (unsigned i(0); i < lhs.size(); ++i) {
        if (rhs == lhs[i]) {
            ++n;
        }
    }
    return n;
}

// replace(文字列全体, 置換前, 置換後)
void replace(std::string &s0, const std::string &s1, const std::string &s2)
{
    unsigned l(s1.size());
    for (unsigned i(0); i < s0.size() - l + 1; ++i) {
        if (s1 == s0.substr(i, l)) {
            s0.replace(i, l, s2);
        }
    }
}

// charをintにキャスト
int ctoi(const char c) {
    return c - '0';
}

// 最大公約数 //
template<class T>
T GCD(T a, T b) {
	T c = max(a, b);
	T d = min(a, b);
	while (c%d != 0) {
		T t = d;
		d = c % d;
		c = t;
	}
	return d;
}

// 最小公倍数 //
template<class T>
T LCM(T a, T b) {
		T c = max(a, b);
	T d = min(a, b);
	while (c%d != 0) {
		T t = d;
		d = c % d;
		c = t;
	}
	return a * b / d;
}

// モジュラ逆数 //
ll mod_inv(ll a, ll m) {
    ll b(m), u(1), v(0);
    while (b) {
        ll t(a / b);
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    if (u < 0) {
        u += m;
    }
    return u;
}

const ll mod = 1e9 + 7;

struct mll {
  ll n;
  mll(ll n = 0) : n(n) {}
};
 
mll operator+(mll a, mll b) { return (a.n += b.n) >= mod ? a.n - mod : a.n; }
mll operator-(mll a, mll b) { return (a.n -= b.n) < 0 ? a.n + mod : a.n; }
mll operator*(mll a, mll b) { return 1LL * a.n * b.n % mod; }
mll operator/(mll a, mll b) { return 1LL * a.n * mll(mod_inv(a.n, mod)); }
mll &operator+=(mll &a, mll b) { return a = a + b; }
mll &operator-=(mll &a, mll b) { return a = a - b; }
mll &operator*=(mll &a, mll b) { return a = a * b; }
mll &operator/=(mll &a, mll b) { return a = a / b; }
ostream &operator<<(ostream &o, mll a) { return o << a.n; }

// 累積和
template<class T>
void accum(vector<T> &v) {
	for (signed i(1); i < v.size(); ++i) {
		v[i] += v[i - 1];
	}
}

// 2次元累積和
template<class T>
void accum(vector<vector<T> > &v) {
	for (signed i(1); i < v.size(); ++i) {
		for (signed j(1); j < v[0].size(); ++j) {
			v[i][j] = v[i][j] + v[i][j - 1];
		}
	}
	for (signed i(1); i < v[0].size(); ++i) {
		for (signed j(1); j < v.size(); ++j) {
			v[j][i] = v[j][i] + v[j - 1][i];
		}
	}
}

// 3次元累積和
template<class T>
void accum(vector<vector<vector<T> > > &v) {
	for (signed i(1); i < v.size(); ++i) {
		for (signed j(1); j < v[0].size(); ++j) {
			for (signed k(1); k < v[0][0].size(); ++k) {
				v[i][j][k] += v[i][j][k - 1];
			}
		}
	}
	for (signed i(1); i < v[0].size(); ++i) {
		for (signed j(1); j < v[0][0].size(); ++j) {
			for (signed k(1); k < v.size(); ++k) {
				v[k][i][j] += v[k - 1][i][j];
			}
		}
	}
	for (signed i(1); i < v[0][0].size(); ++i) {
		for (signed j(1); j < v.size(); ++j) {
			for (signed k(1); k < v[0].size(); ++k) {
				v[j][k][i] += v[j][k - 1][i];
			}
		}
	}
}

// nの素因数分解
// vector<各素因数の数>
vector<ll> primes(ll n) {
	vector<ll> p;
	ll i(2);
	while (n != 1) {
		int s(0);
		while (n % i == 0) {
			n /= i;
			++s;
		}
		p.push_back(s);
		++i;
	}
	return p;
}

// nの素因数分解
// map<素因数, 数>
map<ll, ll> prime_map(ll n) {
	map<ll, ll> mp;
	ll i(2);
	while (n != 1) {
		while (n % i == 0) {
			n /= i;
			++mp[i];
		}
		++i;
	}
	return mp;
}

// nの素因数分解
// vector< pair<素因数, 数> >
vector< pair<ll, ll> > prime_vpii(ll n) {
	vector< pair<ll, ll> > vp;
	ll i(2);
	while (n != 1) {
		ll s(0);
		while (n % i == 0) {
			n /= i;
			++s;
		}
		vp.push_back(pair<ll, ll>(i, s));
		++i;
	}
	return vp;
}


int main() {

    // 空白を含めた一列を読み込む //
	int N;
	cin >> N;
	cin.ignore();
	string s;
	getline(cin, s);
	
}


