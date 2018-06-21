#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))

using namespace std;
using ll = long long;

void inv(int (&dir)[2], bool a, bool b) {
    if (a) {
        dir[0] = -dir[0];
    }
    if (b) {
        dir[1] = -dir[1];
    }
}

int main(){
    int c[9][9];
    int si, sj;
    string sd;
    cin >> sj >> si >> sd;
    --si;
    --sj;
    rep(i, 9) {
        string s;
        cin >> s;
        rep(j, 9){
            c[i][j] = int(s[j] - '0');
        }
    }
    int dir[2];
    if (sd == "R") {
        dir[0] = 0;
        dir[1] = 1;
    } else if (sd == "L") {
        dir[0] = 0;
        dir[1] = -1;
    } else if (sd == "U") {
        dir[0] = -1;
        dir[1] = 0;
    } else if (sd == "D") {
        dir[0] = 1;
        dir[1] = 0;
    } else if (sd == "RU") {
        dir[0] = -1;
        dir[1] = 1;
    } else if (sd == "RD") {
        dir[0] = 1;
        dir[1] = 1;
    } else if (sd == "LU") {
        dir[0] = -1;
        dir[1] = -1;
    } else if (sd == "LD") {
        dir[0] = 1;
        dir[1] = -1;
    }
    int ans[4];
    rep(i, 4){
        cout << c[si][sj];
        inv(dir,
            si + dir[0] < 0 || si + dir[0] > 8,
            sj + dir[1] < 0 || sj + dir[1] > 8);
        si += dir[0];
        sj += dir[1];
    }
    cout << "\n";
}

// 38:42