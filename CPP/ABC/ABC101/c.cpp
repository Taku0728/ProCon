#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	cin.ignore();
	string s;
	getline(cin, s);
	if ((N - K) % (K - 1) == 0) {
		cout << (N - K) / (K - 1) + 1 << endl;
	}
	else {
		cout << (N - K) / (K - 1) + 2 << endl;
	}
	return 0;
}