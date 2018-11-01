#include <iostream>

using namespace std;
using ll = long long;

int main() {
	int N;
	// 入力を受け取る
	cin >> N;
	// 1なら"Hello World"を出力
	if (N == 1) {
		cout << "Hello World" << endl;
	}
	// そうでなければa, bを受け取り,a+bを出力
	else {
		int a, b;
		cin >>a;
		cin >>b;
		cout << a + b << endl;
	}
	return 0;
}
