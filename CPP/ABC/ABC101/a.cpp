#include <iostream>
#include <string>

#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
using namespace std;

int main(){
	string s;
	cin >> s;
	int a(0);
	repv(i, s) {
		if (s[i] == '+') {
			++a;
		}
		else {
			--a;
		}
	}
	cout << a << endl;
	return 0;
}