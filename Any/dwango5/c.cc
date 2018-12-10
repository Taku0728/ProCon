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
	int N;
	cin >> N;
	string s;
	cin >> s;
	int Q;
	cin >> Q;
	vector<int> vk;
	vector<int> va;
	for (int i = 0; i != Q; ++i) {
		int k;
		cin >> k;
		vk.push_back(k - 1);
		va.push_back(0);
	}
	for (int i = 0; i != Q; ++i) {
		int d = 0, m = 0, dm = 0;
		for (int j = 0; j != vk[i]; ++j) {
			if (s[j] == 'C') va[i] += dm;
			else if (s[j] == 'D') ++d;
			else if (s[j] == 'M') {
				++m;
				dm += d;
			}
		}
		for (int j = 0; j + vk[i] < N; ++j) {
			if (s[j + vk[i]] == 'C') va[i] += dm;
			else if (s[j + vk[i]] == 'D') ++d;			
			else if (s[j + vk[i]] == 'M') {
				++m;
				dm += d;
			}

			if (s[j] == 'D') {
				--d;
				dm -= m;
			}
			else if (s[j] == 'M') --m;

		}
	}
	for (auto a : va) {
		cout << a << endl;
	}
	return 0;
}
