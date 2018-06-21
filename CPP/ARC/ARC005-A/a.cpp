#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, n) for (int (i)(0); (i)<(n); ++(i))

using namespace std;
using ll = long long;

int main() {
    int N;
    scanf("%d", &N);
    vector<string> vs(0);
    int a(0);
    string s;
    rep(i, N-1) {
        cin >> s;
        if (s == "TAKAHASHIKUN"
        || s == "Takahashikun"
        || s == "takahashikun") {
            ++a;
        }
    }
    cin >> s;
        if (s == "TAKAHASHIKUN."
        || s == "Takahashikun."
        || s == "takahashikun.") {
            ++a;
        }
    cout << a << "\n";

}

// 06:18