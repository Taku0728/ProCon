#include <iostream>

using namespace std;
int n;
char r[110];
double gpa(0);

double tra(char a) {
	switch (a)
	{
	case 'A':
		return 4.0;
	case 'B':
		return 3.0;
	case 'C':
		return 2.0;
	case 'D':
		return 1.0;
	default:
		return 0.0;
	}
}

int main() {
	scanf_s("%d",&n);
	scanf_s("%s",r, 110);
	for (int i(0); i < n; ++i) gpa += tra(r[i]);
	printf("%20.18f\n", gpa / n);
	return 0;
}