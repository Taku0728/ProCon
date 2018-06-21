#include <iostream>
#include <vector>
#include <numeric>
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

vi make(int a, int loc, bool &found, int n) {
    vi vret(0);
    if (a == 0) {
        found = 1;
        return vret;
    }
    if (n < 1) {
        return vret;
    }
    rep(i, 0, vb.size() - loc - 1) {
        if (a - vb[loc + i] >= 0) {
            vret = make(a - vb[loc + i], loc + i, found, n - 1);
            if (found) {
                vret.emplace_back(vb[loc + i]);
                break;
            }
        }
    }
    return vret;
}

vll ans(ll a, int n, int &len) {
    vll vret(n, 0);
    if (a <= 0) {
        len = a ? 1000 : 0;
        return vret;
    }
    int a0(a % 10);
    rep(nn, 1, n + 1) {
        int lenmin(1000);
        vi vn(0);
        rep(i, 0, 9) {
            int a1(a0 + i * 10);
            bool found(false);
            vi vv(0);
            if (maxel * nn >= a1){
                vv = make(a1, 0, found, nn);
            }
            if(found) {
                int lent(1000);
                found = 0;
                vll vt(ans((a - a1) / 10, nn, lent));
                if (lent < lenmin) {
                    lenmin = lent;
                    vret = vt;
                    vn = vv;
                }
            }
        }
        if (lenmin < 1000) {
            len = lenmin + nn;
            while (vret.size() < nn) {
                vret.emplace_back(0);
            }
            rep(k, 0, nn) {
                vret[k] *= 10;
                if (k < vn.size()) {
                    vret[k] += vn[k];
                }
            }
            return vret;
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

    bool found(false);
    int len(1000);
    vll vans(ans(price, 9, len));
    if (vans.size() == 1) {
        cout << vans[0] << endl;
    }
    else {
        rep(j, 0, vans.size() - 1) {
            cout << vans[j] << "+";
        }
        cout << vans[vans.size() - 1] << "=\n";
    }
}

// ??