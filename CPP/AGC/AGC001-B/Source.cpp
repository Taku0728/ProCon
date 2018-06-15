#include <stdio.h>
#include <iostream>
using namespace std;

long long N, X;

long long max(long long a, long long b) {
	return a > b ? a : b;
}

long long min(long long a, long long b) {
	return a < b ? a : b;
}

void input() {
	cin >> N >> X;
}
int main() {
	input();
	long long sum(N);
	long long a;
	long long b;
	a = max(X, N - X);
	b = min(X, N - X);
	while (1) {
		if (a % b == 0) {
			sum += a * 2 - b;
			break;
		}
		else {
			sum += (a - a % b) * 2;
			long long tem(a);
			a = b;
			b = tem % b;
		}
	}
	cout << sum << endl;
	return 0;
}