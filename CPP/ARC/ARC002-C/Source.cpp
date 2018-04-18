#include <stdio.h>
#include <iostream>
#include <istream>
#include <vector>

using namespace std;

int N;
char ar[1001];
char L[2];
char R[2];
int minl(1000000);

void input() {
	cin >> N;
	cin >> ar;
}

char itoch(int i) {
	switch (i)
	{
	case 0:
		return 'A';
	case 1:
		return 'B';
	case 2:
		return 'X';
	case 3:
		return 'Y';
	}
}

void setLR(int i1,int i2,int i3,int i4) {
	L[0] = itoch(i1);
	L[1] = itoch(i2);
	R[0] = itoch(i3);
	R[1] = itoch(i4);
}

int leng() {
	int dif(0);
	for (int i(0); i < N - 1; ++i) {
		if (ar[i] == L[0]) {
			if (ar[i + 1] == L[1]) {
				++dif;
				i += 1;
				continue;
			}
		}
		if (ar[i] == R[0]) {
			if (ar[i + 1] == R[1]) {
				++dif;
				i += 1;
				continue;
			}
		}
	}
	return (N - dif);
}

int main() {
	input();
	int tem(0);
	for (int i1(0); i1 < 4; ++i1) {
		for (int i2(0); i2 < 4; ++i2) {
			for (int i3(0); i3 < 4; ++i3) {
				for (int i4(0); i4 < 4; ++i4) {
					if (i1 == i2 && i2 == i4) {
						continue;
					}
					setLR(i1, i2, i3, i4);
					tem = leng();
					if (tem < minl) {
						minl = tem;
					}
				}
			}
		}
	}
	cout << minl << endl;
	
	return 0;
}
