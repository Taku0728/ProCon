#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

template <typename T>
T inv(T x) {
    T a(x), b(MOD), u(1), v(0);
    while (b) {
        T t(a / b);
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    if (u < 0) {
        u += MOD;
    }
    return u;
}

template <typename T>
T cbn(T n, T r){
    r = min(r, n - r);
    T a(1);
    for (T i(0); i < r; ++i) {
        a = a * (n - i) * inv(r - i) % MOD;
    }
    return a;
}

int main(){
    long long N, M;
    scanf("%lld %lld", &N, &M);
    if (N < 0) { N = -N; }
    vector<long long> vp(0);
    long long i(2);
    while(i <= static_cast<long long>(pow(N, 0.5) + 1) && N != 1) {
        long long k(0);
        while (N % i == 0) {
            N /= i;
            ++k;
        }
        if(k){
            vp.emplace_back(k);
        }
        ++i;
    }
    if (N != 1) {
        vp.emplace_back(1);
    }
    long long ans(1);
    for (long long j(0); j != vp.size(); ++j) {
        ans = ans * cbn(vp[j] + M - 1, vp[j]) % MOD;
    }

    long long mul(0);
    for (long long i(0); i < M - 1; ++i) {
        ans = ans * 2 % MOD;
    }
    printf("%lld\n", ans);
}