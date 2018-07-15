#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <map>

#define rep(i, n, m) for (int(i)(n); (i)<(m);++(i))
using namespace std;

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

int main() {

    // 空白を含めた一列を読み込む //
	int N;
	cin >> N;
	cin.ignore();
	string s;
	getline(cin, s);

}

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
