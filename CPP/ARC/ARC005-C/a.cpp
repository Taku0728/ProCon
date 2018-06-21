#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, n) for (int i(0); (i)<n; ++(i))

using namespace std;

vector<vector<char>> c;
vector<vector<char>> cc;
vector<vector<int>> cb;
int H, W;
int si, sj;

bool spread(int i, int j, int b) {
    if (cb[i][j] <= b) {
        return false;
    }
    if (cc[i][j] == '#') {
        ++b;
        if (b > 2) {
            return false;
        }
    }
    cb[i][j] = b;
    if (cc[i][j] == 'g')
        return true;
    if (i > 0 && spread(i - 1, j, b))
        return true;
    if (i < H - 1 && spread(i + 1, j, b))
        return true;
    if (j > 0 && spread(i, j - 1, b))
        return true;
    if (j < W - 1 && spread(i, j + 1, b))
        return true;
    return false;
}

void init(){
    rep(k, H) {
        rep(l, W) {
            cb[k][l] = 3;
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
    if(spread(si, sj, 0)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}


// 46:31