#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <utility>
#include <chrono>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define cnow() chrono::system_clock::now()
#define msec(s) chrono::duration_cast<chrono::milliseconds>(s).count()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using chrono::system_clock;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    auto start = cnow();

    auto end = cnow();
    auto sec = msec(start - end);
    cout << sec << " milli sec \n";
}
