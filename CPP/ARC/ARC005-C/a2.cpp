#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <queue>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))

using namespace std;

vector<vector<char>> c;
vector<vector<int>> cb;
int H, W;
int si, sj;

class M {
    public:
        int i;
        int j;
        int b;
        M(int ii, int jj, int bb)
        :i(ii),j(jj),b(bb){
        }
        M(){}
};

bool operator<(M &lhs, M &rhs){
    return lhs.b < rhs.b;
}

priority_queue<M> q;

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
            cb[i][j] = 0;
            if (s[j] == 's') {
                si = i;
                sj = j;
                q.push(M(i, j, 2));
            } else {
                q.push(M(i, j, 0));
            }
        }
    }
    while (!q.empty()){
        M m(q.top());
        q.pop();
        int i(m.i), j(m.j), b(m.b);
        if (cb[i][j] >= b){
            continue;
        }
        if (c[i][j] == '#'){
            --b;
            if (b < 0) {
                continue;
            }
        }
        if (c[i][j] == 'g'){
            printf("YES\n");
            return 0;
        }
        cb[i][j] = b;
        if (i > 0) {
            q.push(M(i - 1, j, b));
        }
        if (i < H - 1) {
            q.push(M(i + 1, j, b));
        }
        if (j > 0) {
            q.push(M(i, j - 1, b));
        }
        if (j < W - 1) {
            q.push(M(i, j + 1, b));
        }
    }
    printf("NO\n");
}

// ERROR