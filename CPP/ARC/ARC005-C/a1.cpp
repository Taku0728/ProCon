#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))

using namespace std;

vector<vector<char>> c;
vector<vector<int>> cb;
int H, W;
int si, sj;

bool spread(int i, int j, int b) {
    if (cb[i][j] <= b)
        return false;
    if (c[i][j] == '#') {
        ++b;
        if (b > 2)
            return false;
    }
    cb[i][j] = b;
    if (c[i][j] == 'g'
    || (i > 0 && spread(i - 1, j, b))
    || (i < H - 1 && spread(i + 1, j, b))
    || (j > 0 && spread(i, j - 1, b))
    || (j < W - 1 && spread(i, j + 1, b))) {
        return true;
    }
    return false;
}

int main(){
    scanf("%d %d", &H, &W);
    c.resize(H);
    cb.resize(H);
    string s;
    rep(i, H) {
        c[i].resize(W);
        cb[i].resize(W);
        scanf("%s", s);
        rep(j, W) {
            c[i][j] = s[j];
            if (s[j] == 's') {
                si = i;
                sj = j;
            }
            cb[i][j] = 3;
        }
    }
    if(spread(si, sj, 0))
        printf("YES\n");
    else
        printf("NO\n");
}