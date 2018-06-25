#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, m, n) for (int(i)(m); (i) < (n); ++(i))
#define repv(i, v) for (int(i)(0); (i) < (v.size()); ++(i))
#define all(v) (v).begin(), (v).end()

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi vabc;

bool func(vi v0)
{
	vvi vcand(1, v0);
	while (!vcand.empty())
	{
		vi v1 = vcand.back();
		vcand.pop_back();
		repv(i, vabc)
		{
			if (vabc[i][2] < v1[2] && (vabc[i][0] == v1[0] || vabc[i][1] == v1[0]))
			{
				int ai = vabc[i][0] == v1[0] ? 0 : 1;
				int bi = ai ? 0 : 1;
				if (vabc[i][bi] == v1[1])
				{
					return true;
				}
				vcand.push_back({vabc[i][bi], v1[1], v1[2] - vabc[i][2]});
			}
		}
		sort(all(vcand), [](const vi &lhs, const vi &rhs) { return lhs[2] > rhs[2]; });
	}
	return false;
}

int main()
{
	int N, M;
	cin >> N >> M;
	rep(i, 0, M)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vabc.push_back({a, b, c});
	}
	int ans(0);
	repv(i, vabc)
	{
		if (func(vabc[i]))
		{
			vabc.erase(vabc.begin() + i);
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
