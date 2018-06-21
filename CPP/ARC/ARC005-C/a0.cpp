#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, n) for (int i(0); (i)<n; ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;

vector<vector<char>> c;
vector<vector<char>> cc;
vector<vector<bool>> cb;
int H, W;
int si, sj;

bool spread(int i, int j) {
    if (cb[i][j] || cc[i][j] == '#') {
        return false;
    }
    cb[i][j] = true;
    if (cc[i][j] == 'g')
        return true;
    if (i > 0 && spread(i - 1, j))
        return true;
    if (i < H - 1 && spread(i + 1, j))
        return true;
    if (j > 0 && spread(i, j - 1))
        return true;
    if (j < W - 1 && spread(i, j + 1))
        return true;
    return false;
}

void init(){
    rep(k, H) {
        rep(l, W) {
            cb[k][l] = false;
            cc[k][l] = c[k][l];
        }
    }
}

int main(){
    cin >> H >> W;
    c.resize(H);
    cc.resize(H);
    cb.resize(H);
    string s;
    rep(i, H) {
        c[i].resize(W);
        cc[i].resize(W);
        cb[i].resize(W);
        cin >> s;
        rep(j, W) {
            c[i][ j] = s[j];
            if (s[j] == 's') {
                si = i;
                sj = j;
            }
        }
    }
    init();
    if(spread(si, sj)) {
        printf("YES\n");
        return 0;
    }

    rep(i, H) {
        rep(j, W) {
            if (c[i][j] == '#') {
                init();
                cc[i][j] = '.';
                if(spread(si, sj)) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    
    rep(i, H) {
        rep(j, W) {
            if (c[i][j] == '#') {
                rep(k, H) {
                    rep (l, W) {
                        if (c[k][l] == '#') {
                            init();
                            cc[i][j] = '.';
                            cc[k][l] = '.';
                            if(spread(si, sj)) {
                                printf("YES\n");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("NO\n");
}

// 38:41