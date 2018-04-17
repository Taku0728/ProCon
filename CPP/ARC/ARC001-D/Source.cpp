#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
int start;
int goal;
vector<int> l;
vector<int> r;


void input() {
	scanf_s("%d", &N);
	l.resize(N + 1);
	r.resize(N + 1);
	scanf_s("%d%d", &start, &goal);
	for (int i(0); i < N + 1; ++i) {
		scanf_s("%d%d", &l[i], &r[i]);
	}
}

double min_dis(int i1, int j1, int i2, int j2) {
	double ans;
	if (i1 == i2) {
		return 0;
	}
	double slope(double(j2 - j1) / double(i2 - i1));
	double slopel(slope);
	double sloper(slope);
	int max_li = i1;
	int max_ri = i1;
	for (int i(i1 + 1); i < i2 + 1; ++i) {
		double t_slopel(double(l[i] - j1) / double(i - i1));
		if (t_slopel > slopel) {
			slopel = t_slopel;
			max_li = i;
		}
		double t_sloper(double(r[i] - j1) / double(i - i1));
		if (t_sloper < sloper) {
			sloper = t_sloper;
			max_ri = i;
		}
	}
	if (max_li == i1 && max_ri == i1) {
		return sqrt(pow(double(j2 - j1), 2.0) + pow(double(i2 - i1), 2.0));
	}
	//if (max_ri > max_li) {
	//	ans = min_dis(i1, j1, max_li, l[max_li]);
	//	ans += min_dis(max_li, l[max_li], i2, j2);
	//}
	//else {
	//	ans = min_dis(i1, j1, max_ri, r[max_ri]);
	//	ans += min_dis(max_ri, r[max_ri], i2, j2);
	//}
	if (max_ri > max_li) {
		ans = min_dis(i1, j1, max_li, l[max_li]);
		ans += min_dis(max_li, l[max_li], max_ri, r[max_ri]);
		ans += min_dis(max_ri, r[max_ri], i2, j2);
	}
	else {
		ans = min_dis(i1, j1, max_ri, r[max_ri]);
		ans += min_dis(max_ri, r[max_ri], max_li, l[max_li]);
		ans += min_dis(max_li, l[max_li], i2, j2);
	}

	return ans;
}


int main() {
	double ans;
	input();
	ans = min_dis(0, start, N, goal);
	if (ans == int(ans)) {
		cout << int(ans) << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}