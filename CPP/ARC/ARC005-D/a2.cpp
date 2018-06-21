#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))
#define repf(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'

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
int maxvl(0);

vi make(int a, int loc, bool &found, int num) {
    vi vret(0);
    if (a < 0) {
        return vret;
    }
    if (a == 0) {
        found = true;
        return vret;
    }
    --num;
    if (num < 0) {
        return vret;
    }
    rep(i, vb.size() - loc - 1) {
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
    repf(nn, 1, n + 1) {
        for (int j(vvl.size() - 1); j >= 0; --j) {
            if (vvl[j][0] % 10 != a0 || vvl[j][1] > n) {
                continue;
            }
            vret = ans((a - vvl[j][0]) / 10, nn, found);
            if (found) {
                while (vret.size() < n) {
                    vret.emplace_back(0);
                }
                rep(k, n) {
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
    rep(i, s.size()) {
        vb.emplace_back(int(s[i] - '0'));
        maxel = max(maxel, vb[i]);
    }
    sort(vb.begin(), vb.end(), greater<int>());
    ll price;
    cin >> price;
    rep(i, 100) {
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
                maxvl = max(maxvl, i);
                break;
            }
            ++k;
        }
    }
    vvl[0][1] = 1;
    vvx[0] = {0};

    repf(i, 1, 10) {
        bool found(false);
        vll vans(ans(price, i, found));
        if (found) {
            if (vans.size() == 1) {
                cout << vans[0] << "\n";
            }
            else {
                rep(j, vans.size() - 1) {
                    cout << vans[j] << "+";
                }
                cout << vans[vans.size() - 1] << "=\n";
            }
            return 0;
        }
    }
}

// 6:44:29