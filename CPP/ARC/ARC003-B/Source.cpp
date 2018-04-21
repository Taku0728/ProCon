#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#define R for (int i(0); i < N; ++i) 
using namespace std;
int N;
vector<string> s;
int main() {
	cin >> N;
	R {
		string t;
		cin >> t;
		s.push_back(t);
		reverse(s[i].begin(),s[i].end());
	}
	sort(s.begin(), s.end());
	R {
		reverse(s[i].begin(), s[i].end());
		cout << s[i] << "\n";
	}
}