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
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

auto chnow = [](){ return chrono::system_clock::now(); };
auto chdis = [](auto a) { return chrono::duration_cast<chrono::milliseconds>(chnow() - a).count(); };

/*
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    auto start = chnow();

    cout << chdis(start) << " milli sec \n";
    return 0;
}
*/