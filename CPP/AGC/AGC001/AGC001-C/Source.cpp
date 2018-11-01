#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class L
{
public:
	int A;
	int B;
	int len;
	bool operator < (const L &l) const {
		return len < l.len;
	}
	bool operator > (const L &l) const {
		return len > l.len;
	}

private:

};

class Apex
{
public:
	int neibs;
	vector<int> neib;
	Apex();

private:

};

Apex::Apex() {
	neibs = 0;
}

int N, K;
vector<L> Vec;
Apex Ape[2002];

void input() {
	cin >> N >> K;
	int a, b;
	for (int i(0); i < N - 1; ++i) {
		cin >> a >> b;
		Ape[a].neib.emplace_back(b);
		Ape[b].neib.emplace_back(a);
		++Ape[a].neibs;
		++Ape[b].neibs;
	}
}

void getL(const int orig, const int loca, const int prev, const int len) {
	for (int i(0); i < Ape[loca].neibs; ++i) {
		if (Ape[loca].neib[i] == prev) {
			continue;
		}
		if (Ape[loca].neib[i] > orig) {
			Vec.push_back({ orig, Ape[loca].neib[i], len });
		}
		getL(orig, Ape[loca].neib[i], loca, len + 1);
	}
}

int getAns() {
	int ans(0);
	for (int i(1); i <= N; ++i) {
		getL(i, i, 0, 1);
	}
	sort(Vec.begin(), Vec.end());
	while (!Vec.empty() && Vec.back().len > K) {
		vector<vector<int>> VecN;
		int maxl(Vec.back().len);
		int i(Vec.size() - 1);
		while (i >= 0 && Vec[i].len == maxl) {
			bool c1(false), c2(false);
			for (int j(0); j < VecN.size(); ++j) {
				if (Vec[i].A == VecN[j][0]) {
					++VecN[j][1];
					c1 = true;
				}
				if (Vec[i].B == VecN[j][0]) {
					++VecN[j][1];
					c2 = true;
				}
			}
			if (!c1) {
				VecN.push_back({ Vec[i].A, 1 });
			}
			if (!c2) {
				VecN.push_back({ Vec[i].B, 1 });
			}
			--i;
		}
		while (!Vec.empty() && Vec.back().len == maxl) {
			int maxn(0);
			int tem(0);
			for (int j(0); j < VecN.size(); ++j) {
				if (VecN[j][1] > tem) {
					maxn = VecN[j][0];
					tem = VecN[j][1];
				}
			}
			int j(0);
			while (j < Vec.size()) {
				if (Vec[j].A == maxn || Vec[j].B == maxn) {
					Vec.erase(Vec.begin() + j);
				}
				else {
					++j;
				}
			}
			j = 0;
			while (j < VecN.size()) {
				if (VecN[j][0] == maxn) {
					VecN.erase(VecN.begin() + j);
				}
				else {
					++j;
				}
			}
			++ans;
		}
	}
	return ans;
}

int main() {
	input();
	int ans = getAns();
	cout << ans << "\n";
	return 0;
}