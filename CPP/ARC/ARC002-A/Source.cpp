#include <stdio.h>
#include <iostream>

using namespace std;

int u(0);
int Y;

int main() {
	cin >> Y;
	if (Y % 4 == 0) {
		u = 1;
	}
	if (Y % 100 == 0) {
		u = 0;
	}
	if (Y % 400 == 0) {
		u = 1;
	}
	if (u) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}