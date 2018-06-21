#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

vi vb(0);
int maxel(0);
vector<vii> vvv(0);
vector<vii> vvvl(0);

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
    rep(i, vb.size() - loc) {
        bool found1(false);
        vret = make(a - vb[loc + i], loc + i, found1, num);
        if (found1) {
            found = true;
            vret.emplace_back(vb[loc + i]);
            return vret;
        }
    }
    return vret;
}

vii ans(ll a, int n, bool &found) {
    vii vret(0);
    if (a == 0) {
        found = true;
        return vret;
    }
    int a0(a%10);
    for (int i(vvvl[a0].size() - 1); i >= 0; -- i) {
        if (vvvl[a0][i][1] > n) {
            continue;
        }
        ll aa(a - a0);
        aa -= vvvl[a0][i][0] * 10;
        if (aa < 0) {
            continue;
        }
        aa = aa / 10;
        bool found1(false);
        vret = ans(aa, n, found1);
        if (found1) {
            found = true;
            vi veb(vvv[a0][i]);
            while(n > veb.size()) {
                veb.emplace_back(0);
            }
            vret.emplace_back(veb);
            return vret;
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
    sort(vb.begin(), vb.end());
    ll price;
    cin >> price;
    rep(i, 10) {
        vii vu;
        vii vl;
        rep(j, 9) {
            bool found(false);
            vi vv(0);
            int k(1);
            while (!found && k < 10) {
                if (maxel*k >= i + j*10) {
                    vv = make(i + j*10, 1, found, k);
                }
                ++k;
            }
            if (found) {
                vu.emplace_back(vv);
                vl.emplace_back(vi({j, int(vv.size())}));
            }
        }
        vvv.emplace_back(vu);
        vvvl.emplace_back(vl);
    }
    vvv[0][0] = {0};
    vvvl[0][0] = {0, 1};

    for (int i(1); i < 10; ++i) {
        bool found(false);
        vii vans(ans(price, i, found));
        if (found) {
            vector<ll> vll(0);
            vll.resize(i);
            rep(j, vans.size()){
                rep(k, vans[j].size()){
                    if (vll[k] != 0 || vans[j][k] != 0) {
                        vll[k] *= 10;
                        vll[k] += vans[j][k];
                    }
                }
            }
            if (vll.size() == 1) {
                cout << vll[0] << "\n";
            }
            else {
                rep(j, vll.size() - 1) {
                    cout << vll[j] << "+";
                }
                cout << vll[vll.size() - 1] << "=\n";
            }
            return 0;
        }
    }
}

// 6:44:29