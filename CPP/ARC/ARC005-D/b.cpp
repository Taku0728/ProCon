#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)
 
const int N_MAX = 10;
 
typedef long long ll;
typedef pair<vector<ll>, int> P;
 
char b[N_MAX + 1];
ll price;
 
int n;
int ds[N_MAX];
int dx;
vector<ll> cs[100];
map<ll, P> memo;
 
pair<vector<ll>, int> rec(ll pr) {
  if (memo.find(pr) == memo.end()) {
    if (pr < 10) {
      memo[pr] = P(cs[pr], (int) cs[pr].size());
    } else {
      int vz = 10000, vl = 10000;
      vector<ll> vs1, vs2;
      for (int r = pr % 10; r <= dx && r <= pr; r += 10) {
        P ws = rec((pr - r) / 10);
        int wz = max(cs[r].size(), ws.first.size());
        int wl = ws.second + wz;
        if (wl < vl || wl == vl && wz < vz) {
          vl = wl; vz = wz;
          vs1 = cs[r]; vs2 = ws.first;
        }
      }
      vector<ll> vs;
      vs1.resize(vz); vs2.resize(vz); vs.resize(vz);
      REP(i, vz) vs[i] = vs2[i] * 10 + vs1[i];
      memo[pr] = P(vs, vl);
    }
  }
  return memo[pr];
}
 
void init() {
  for (n = 0; n < N_MAX; n++) {
    if (b[n] == '\0') break;
    ds[n] = b[n] - '0';
  }
  dx = ds[n - 1] * 9;
}
 
void solve() {
  init();
 
  FOR(j, 1, dx) cs[j].resize(10);
  REP(k, 9) for (int j = dx; j > 0; j--) FOR(i, 1, n - 1) {
    int d = ds[i];
    if (j >= d && cs[j].size() > cs[j - d].size() + 1) {
      cs[j] = cs[j - d];
      cs[j].push_back(d);
    }
  }
 
  vector<ll> ans = rec(price).first;
 
  REP(i, ans.size()) {
    if (i > 0) printf("+");
    printf("%lld", ans[i]);
  }
  puts(ans.size() > 1 ? "=" : "");
 
  // ITR(memo, it) {
  //   printf("%lld :\n", it->first);
  //   vector<ll> vs = it->second.first;
  //   REP(i, vs.size()) {
  //     printf("  %lld\n", vs[i]);
  //   }
  // }
}
 
void input() {
  scanf("%s", b);
  scanf("%lld", &price);
}
 
int main() {
  input();
  solve();
  return 0;
}