#include <iostream>
#include <vector>
using namespace std;

vector<int> min(vector<int> s0, vector<int> s1) {
	for (int i = 0; i < s0.size(); ++i) {
		if (s0[i] < s1[i]) {
			return s0;
		}
		else if (s0[i] > s1[i]) {
			return s1;
		}
	}
	return s0;
}

vector<int> exchange(vector<int> s, vector<int> p) {
	vector<int> s1(s);
	for (int i = 0; i < s.size(); ++i) {
		s1[p[i] - 1] = s[i];
	}
	return s1;
}

vector<int> minimum(vector<int> s, vector< vector<int> > p) {
	if (p.size() == 0) {
		return s;
	}
	vector<int> min_s(s.size(), 10);
	for (int i = 0; i < p.size(); ++i) {
		vector< vector<int> > p1(p);
		vector<int> pp = p1[i];
		p1.erase(begin(p1) + i);
		vector<int> s1 = minimum(s, p1);
		vector<int> s2 = exchange(s, pp);
		s2 = minimum(s2, p1);
		min_s = min(min_s, s1);
		min_s = min(min_s, s2);
	}

	return min_s;
}

int main(){
	int n;
	cin >> n;
	vector<int> s(0);
	for (int i = 0; i < n; ++i) {
		int ss;
		cin >> ss;
		s.push_back(ss);
	}
	int m;
	cin >> m;
	vector< vector<int> > p(0);
	for (int i = 0; i < m; ++i) {
		vector<int> pp(0);
		for (int j = 0; j < n; ++j) {
			int ppp;
			cin >> ppp;
			pp.push_back(ppp);
		}
		p.push_back(pp);
	}
	vector<int> min_s = minimum(s, p);
	for (int i = 0; i < min_s.size() - 1; ++i) {
		cout << min_s[i] << " ";
	}
	cout << min_s[min_s.size() - 1] << endl;
}
