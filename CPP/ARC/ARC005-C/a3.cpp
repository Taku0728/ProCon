#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <deque>
#include <utility>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))

using namespace std;
using pii = pair<int, int>;

vector<vector<char>> c;
vector<vector<int>> cb;
int H, W;
int si, sj;
int dij[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
deque<pii> q(0);

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W;
    c.resize(H);
    cb.resize(H);
    string s;
    rep(i, H) {
        c[i].resize(W);
        cb[i].resize(W);
        cin >> s;
        rep(j, W) {
            c[i][j] = s[j];
            cb[i][j] = 3;
            if (s[j] == 's') {
                si = i;
                sj = j;
                cb[i][j] = 0;
                q.emplace_front(pii(i, j));
            }
        }
    }
    while (!q.empty()){
        pii p(q.front());
        q.pop_front();
        int i(p.first), j(p.second);
        rep(k, 4) {
            int di(dij[k][0]), dj(dij[k][1]);
            int ni(i + di), nj(j + dj);
            if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                int b(c[ni][nj] == '#' ? 1 : 0);
                int nb(cb[i][j] + b);
                if (cb[i + di][j + dj] <= nb || nb > 2) {
                    continue;
                }
                if (c[ni][nj] == 'g') {
                    cout << "YES" << endl;
                    return 0;
                }
                cb[ni][nj] = nb;
                if (b) {
                    q.emplace_back(pii(ni, nj));
                } else {
                    q.emplace_front(pii(ni, nj));
                }
            }
        }
    }
    cout << "NO" << endl;
}


// FINAL