#include <stdio.h>
#include <iostream>

using namespace std;

int u(0);
int DAYS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int Uruu(int Y) {
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
		return 1;
	}
	else {
		return 0;
	}
}

int y, m, d;

int main() {
	scanf_s("%d/%d/%d", &y, &m, &d);
	int con = 1;
	while (con) {
		if (y % m == 0) {
			if ((y / m) % d == 0) {
				cout << y << "/";
				if (m < 10) {
					cout << "0" << m << "/";
				}
				else {
					cout << m << "/";
				}
				if (d < 10) {
					cout << "0" << d << endl;
				}
				else {
					cout << d << endl;
				}
				return 0;
			}
		}
		if (d < DAYS[m - 1]) {
			++d;
		}
		else if (m == 12) {
			++y;
			m = 1;
			d = 1;
		}
		else if (m == 2 && d == 28 && Uruu(y) == 1) {
			++d;
		}
		else {
			++m;
			d = 1;
		}
	}
	return 0;
}