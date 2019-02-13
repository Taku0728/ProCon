#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <chrono>
using namespace std;

int main() {
	int a = 0;
	cout << ++a + ++a << endl;
	cout << a << endl;
	a = 0;
	cout << a++ + a++ << endl;
	cout << a << endl;
	return 0;
}
