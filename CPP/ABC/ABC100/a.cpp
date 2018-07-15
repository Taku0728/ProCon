#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	if (A <= 8 && B <= 8) {
		cout << "Yay!\n";
	}
	else {
		cout << ":(\n";
	}
	return 0;
}
