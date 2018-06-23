#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;
using vbb = vector<vb>;

int main(){
	int a, b, c;
	string s;
	cin >> a;
	cin >> b >> c;
	cin >> s;
	cout << a + b + c << " " + s << endl;
}

// 2:39
