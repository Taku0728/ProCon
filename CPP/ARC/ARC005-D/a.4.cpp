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
vi ind(100, 9);
vii dic(100, vi(0));
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

vll ans(ll a, int n, int alp, int &bet) {
    vll vret(n, 0);
    if (a <= 0) {
        bet = a ? 1000 : 0;
        return vret;
    }
    int a0(a % 10);
    rep(nn, 1, n + 1) {
        if (alp - nn < 0) {
            break;
        }
        bet = alp;
        int am(0);
        rep(i, 0, 9) {
            int a1(a0 + i * 10);
            if (ind[a1] <= nn) {
                int betn(0);
                vll vt(ans((a - a1) / 10, nn, bet - nn, betn));
                if (betn <= bet - nn) {
                    bet = betn + nn - 1;
                    vret = vt;
                    am = a1;
                }
                if (betn == 0) {
                    break;
                }
            }
        }
        if (bet < alp) {
            while (vret.size() < nn) {
                vret.emplace_back(0);
            }
            rep(k, 0, nn) {
                vret[k] *= 10;
                if (k < dic[am].size()) {
                    vret[k] += dic[am][k];
                }
            }
            return vret;
        }
    }
    bet = 1000;
    return vret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    repv(i, s) {
        vb.emplace_back(int(s[i] - '0'));
        maxel = max(maxel, vb[i]);
    }
    sort(begin(vb), end(vb), greater<int>());
    ll price;
    cin >> price;
    rep(i, 0, 82) {
        rep(j, 1, 10) {
            if (maxel * j >= i){
                bool b(false);
                vi vv(make(i, 0, b, j));
                if (b) {
                    dic[i] = vv;
                    ind[i] = j;
                    break;
                }
            }
        }
    }

    int len(0);
    vll vans(ans(price, 9, 1000, len));
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