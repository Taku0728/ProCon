#include <iostream>

using namespace std;

int S(int N) {
	int s(0);
	while (N > 0) {
		s += N % 10;
		N /= 10;
	}
	return s;
}

int main() {
	int N;
	cin >> N;
	if (N % S(N) == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}