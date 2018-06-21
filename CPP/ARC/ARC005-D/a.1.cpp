#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vll = vector<ll>;

vi vb(0);
int maxel(0);
vii vvx(0);
vii vvl(0);

vi make(int a, int loc, bool &found, int num) {
    vi vret(0);
    if (a <= 0) {
        found = a ? 0 : 1;
        return vret;
    }
    --num;
    if (num < 0) {
        return vret;
    }
    rep(i, 0, vb.size() - loc - 1) {
        vret = make(a - vb[loc + i], loc + i, found, num);
        if (found) {
            vret.emplace_back(vb[loc + i]);
            return vret;
        }
    }
    return vret;
}

vll ans(ll a, int n, bool &found) {
    vll vret(n, 0);
    if (a <= 0) {
        found = a ? 0 : 1;
        return vret;
    }
    int a0(a % 10);
    rep(nn, 1, n + 1) {
        repv(j, vvl) {
            if (vvl[j][0] % 10 != a0 || vvl[j][1] > n) {
                continue;
            }
            vret = ans((a - vvl[j][0]) / 10, nn, found);
            if (found) {
                while (vret.size() < n) {
                    vret.emplace_back(0);
                }
                rep(k, 0, n) {
                    vret[k] *= 10;
                    if (k < vvx[j].size()) {
                        vret[k] += vvx[j][k];
                    }
                }
                return vret;
            }
        }
    }
    return vret;
}

int main(){
    string s;
    cin >> s;
    repv(i, s) {
        vb.emplace_back(int(s[i] - '0'));
        maxel = max(maxel, vb[i]);
    }
    sort(vb.begin(), vb.end(), greater<int>());
    ll price;
    cin >> price;
    rep(i, 0, 100) {
        vi vv(0);
        int k(1);
        while (k < 10) {
            bool found(false);
            if (maxel*k >= i) {
                vv = make(i, 0, found, k);
            }
            if (found) {
                vvx.emplace_back(vv);
                vvl.push_back({i, int(vv.size())});
                break;
            }
            ++k;
        }
    }
    vvl[0][1] = 1;
    vvx[0] = {0};

    rep(i, 1, 10) {
        bool found(false);
        vll vans(ans(price, i, found));
        if (found) {
            if (vans.size() == 1) {
                cout << vans[0] << endl;
            }
            else {
                rep(j, 0, vans.size() - 1) {
                    cout << vans[j] << "+";
                }
                cout << vans[vans.size() - 1] << "=" << endl;
            }
            return 0;
        }
    }
}

// ??