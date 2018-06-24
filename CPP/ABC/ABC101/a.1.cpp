#include <iostream>
#include <string>

#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define all(v) (v).begin(), (v).end()
using namespace std;

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

int main() {
	string s;
	cin >> s;
	cout << count(all(s), '+') - count(all(s), '-') << endl;
	return 0;
}