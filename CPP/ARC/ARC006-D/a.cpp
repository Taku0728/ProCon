#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))

using namespace std;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vbb = vector<vb>;
using vbbb = vector<vbb>;

vs A = {".......",
        "...o...",
        "..o.o..",
        ".o...o.",
        ".ooooo.",
        ".o...o.",
        "......."};

vs B = {".......",
        ".oooo..",
        ".o...o.",
        ".oooo..",
        ".o...o.",
        ".oooo..",
        "......."};

vs C = {".......",
        "..ooo..",
        ".o...o.",
        ".o.....",
        ".o...o.",
        "..ooo..",
        "......."};

vbb vstovbb(vs alp) {
    int H = alp.size();
    int W = alp[0].size();
    vbb bet(H, vb(W, false));
    rep(i, 0, H) {
        rep(j, 0, W) {
            bet[i][j] = alp[i][j] == 'o' ? true : false;
        }
    }
    return bet;
}

vbb rotate(vbb alp) {
    int size = alp.size();
    vbb bet(size, vb(size, false));
    rep(i, 0, size) {
        rep(j, 0, size) {
            bet[i][j] = alp[j][size - 1 - i];
        }
    }
    return bet;
}

vbb multi(vbb alp, int n){
    int size = alp.size();
    vbb bet(size * n, vb(size * n, false));
    rep(i, 0, size) {
        rep(j, 0, size) {
            rep(k, 0, n) {
                rep(l, 0, n) {
                    bet[i*n + k][j*n + l] = alp[i][j];
                }
            }
        }
    }   
    return bet;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vbbb tab;
    vs cs;
    vbb cr;
    rep(i, 0, H){
        string s;
        cin >> s;
        cs.emplace_back(s);
    }
    vbb cb = vstovbb(cs);
    vb sr(W, false);
    cr.assign(H, sr);

    tab.emplace_back(vstovbb(A));
    tab.emplace_back(vstovbb(B));
    tab.emplace_back(vstovbb(C));
    rep(i, 0, 9){
        tab.emplace_back(rotate(tab[tab.size() - 3]));
    }
    rep(i, 2, min(H, W)/7 + 1){
        rep(j, 0, 12){
            tab.emplace_back(multi(tab[j], i));
        }
    }
    vi ans(3, 0);
    rep(i, 0, H){
        rep(j, 0, W){
            repv(k, tab){
                bool lap(false);
                int size(tab[k].size());
                if (i + size > H || j + size > W){
                    break;
                }
                if (k % 12 == 0) {
                    rep(l, 0, size){
                        rep(m, 0, size){
                            if (cr[i + l][j + m]) {
                                lap = true;
                            }
                        }
                        if (lap) {
                            break;
                        }
                    }
                }
                if (lap) {
                    break;
                }
                bool f(true);
                rep(l, 0, size){
                    rep(m, 0, size){
                        if (tab[k][l][m] != cb[i + l][j + m]){
                            f = false;
                            break;
                        }
                    }
                    if (!f) {
                        break;
                    }
                }
                if (f) {
                    ++ans[k % 3];
                    rep(l, 0, size){
                        rep(m, 0, size){
                            cr[i + l][j + m] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
