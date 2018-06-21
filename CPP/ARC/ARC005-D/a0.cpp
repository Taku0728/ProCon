#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <utility>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

vi vb(0);

vi make(int a, vi v0, int loc) {
    int aa(0);
    rep(i, v0.size()) {
        aa += v0[i];
    }
    if (a == aa % 10) {
        return v0;
    }
    vi va(1000, 0);
    rep(i, vb.size() - v0.size()) {
        vi v1(v0);
        v1.emplace_back(vb[loc + i + 1]);
        vi vb(make(a, v1, loc + i + 1));
        if (vb.size() < va.size()) {
            va = vb;
        }
    }
    return va;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    rep(i, s.size()) {
        vb.emplace_back(int(s[i] - '0'));
    }
    ll price;
    cin >> price;
    s = to_string(price);
    vi vp;
    rep(i, s.size()) {
        vp.emplace_back(int(s[i] - '0'));
    }
    vp.emplace_back(0);
    vii vn;
    rep(i, 10) {
        vi vv;
        vn.emplace_back(make(i, vv, -1));
    }
    vii va;
    rep(i, vp.size() - 1) {
        vi vv(vn[vp[i]]);
        rep(j, vv.size()){
            price -= int(vv[j] - '0');
        }
    }
}
