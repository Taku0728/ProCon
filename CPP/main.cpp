#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <deque>
#include <algorithm>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define all(v) (v).begin(), (v).end()

using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using vs = vector<string>;
using vb = vector<bool>;
using vbb = vector<vb>;
using vbbb = vector<vbb>;

int H, W;
vbbb tab;
vs cs;
vbb cb;
viii vid;
vii vis;

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

vi is(vbb alp) {
    int si(0), sj(0);
    bool f(false);
    while (si < 6 && !f) {
        ++si;
        while (sj < 6 && !f) {
            ++sj;
            if (alp[si][sj]) {
                f = true;
            }
        }
    }
    return vi({si, sj});
}

vii id(vbb alp) {
    vii vret(0);
    vi s(is(alp));
    bool f(false);
    deque<vi> dq({{0, 0}});
    alp[s[0]][s[1]] = false;
    while (!dq.empty()) {
        vi v(dq.back());
        dq.pop_back();
        rep(i, -1, 2) {
            rep(j, -1, 2) {
                if (alp[s[0] + v[0] + i][s[1] + v[1] + j]) {
                    vret.push_back({v[0] + i, v[1] + j});
                    dq.push_front({v[0] + i, v[1] + j});
                    alp[s[0] + v[0] + i][s[1] + v[1] + j] = false;
                }
            }
        }
    }
    return vret;
}

int mulsize(int si, int sj) {
    bool f(false);
    int i(1);
    while (!f) {
        ++i;
        rep(j, 0, i) {
            if (!cb[si + i - 1][sj + j]
                || !cb[si + j][sj + i - 1]) {
                f = true;
                break;
            }
        }
    }
    return --i;
}

int match(int si, int sj, int n) {
    vb line(12, true);
    int left(12);
    int loc(0);
    deque<vi> dq({{0, 0}});
    cb[si][sj] = false;
    while (left > 1) {
        vi v(dq.back());
        dq.pop_back();
        rep(i, -1, 2) {
            rep(j, -1, 2) {
                if (cb[si + (v[0] + i) * n][sj + (v[1] + j) * n]) {
                    rep(k, 0, 12) {
                        if (line[k]) {
                            if (vid[k].size() <= loc
                            || vid[k][loc][0] != v[0] + i
                            || vid[k][loc][1] != v[1] + j) {
                                line[k] = false;
                                --left;
                            }
                        }
                    }
                    ++loc;
                    dq.push_front({v[0] + i, v[1] + j});
                    cb[si + (v[0] + i) * n][sj + (v[1] + j) * n] = false;
                }
            }
        }
    }
    int ans(find(all(line), true) - line.begin());
    rep(i, 0, 7*n) {
        rep(j, 0, 7*n) {
            cb[si - vis[ans][0] * n + i][sj - vis[ans][1] * n + j] = false;
        }
    }
    return ans % 3;
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    cin >> H >> W;
    rep(i, 0, H){
        string s;
        cin >> s;
        cs.emplace_back(s);
    }
    cb = vstovbb(cs);
    vb sr(W, false);

    tab.emplace_back(vstovbb(A));
    tab.emplace_back(vstovbb(B));
    tab.emplace_back(vstovbb(C));
    rep(i, 0, 9){
        tab.emplace_back(rotate(tab[tab.size() - 3]));
    }
    repv(i, tab) {
        vid.emplace_back(id(tab[i]));
        vis.emplace_back(is(tab[i]));
    }

    vi ans(3, 0);
    rep(i, 0, H){
        rep(j, 0, W){
            if (cb[i][j]) {
                int n(mulsize(i, j));
                ++ans[match(i, j, n)];
            }
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
