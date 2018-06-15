#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

const long long c = 1e9 + 7;

template <typename T>
T modC(T x){
    return x % c;
}

template <typename T>
vector<T> pas(T n) {
    vector<T> v0({ 1, 1 });
    vector<T> v1(v0);
    for (T i(0); i < n; ++i) {
        for (T j(1); j < v0.size(); ++j) {
            v1[j] = v0[j - 1] + v0[j];
        }
        if (i % 2) {
            v1.emplace_back(v0[v0.size() - 1]);
        }
        v0 = v1;
    }
    return v0;
}

template <typename T>
vector<T> pas2(T m, vector<T> v0) {
    vector<T> v1(v0);
    T n(m - v0[1]);
    T ii(v0[1] % 2 ? 0 : 1)
    for (T i(0); i < n; ++i) {
        for (T j(1); j < v0.size(); ++j) {
            v1[j] = v0[j - 1] + v0[j];
        }
        if ((i + ii) % 2) {
            v1.emplace_back(v0[v0.size() - 1]);
        }
        v0 = v1;
    }
    return v0;
}

template <typename T>
T cbn(T n, T r){
    r = min(r, n - r);
    vector<T> v(0);
    for (T i(n); i > n - r; --i) {
        v.emplace_back(i);
    }
    for (T i(r); i > 1; --i) {
        T j(i);
        T k(0);
        T d(j);
        while (j != 1) {
            ++k;
            if (k > j) {
                k = 1;
            }
            while (j % k != 0) {
                ++k;
            }
            d = j / k;
            T loc(n % d);
            while (j != 1 && loc < r) {
                red(v[loc], j);
                loc += d;
            }
        }
    }
    T a(1);
    for (T i(0); i < r; ++i) {
        a = modC(a * v[i]);
    }
    return a;
}

int main(){
    long long N, M;
    scanf("%lld %lld", &N, &M);
    long long minus(N < 0 ? 1 : 0);
    if (minus) { N = -N; }
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
        ans = modC(ans * cbn(vp[j] + M - 1, vp[j]));
    }

    long long mul(0);
    i = minus;
    while (i <= M) {
        mul = modC(mul + cbn(M, i));
        i += 2;
    }
    ans = modC(ans * mul);
    printf("%lld\n", ans);
}