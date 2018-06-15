#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

template <typename T>
void red(T &x, T &y){
    T a(max(x, y)), b(min(x, y));
    T c(a % b);
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    x /= b;
    y /= b;
}

int main(){
    long long x, y;
    scanf("%lld/%lld", &x, &y);
    red(x, y);
    long long d = y * (y + 1) / 2 - x;
    long long xx(x), yy(y);
    if (d < 0) {
        long long n = static_cast<long long>((2 * x - y) / y / y) + 1;
        xx *= n;
        yy *= n;
    }
    bool ans(false);
    d = yy * (yy + 1) / 2 - xx;
    while (d <= yy) {
        if (d > 0) {
            printf("%lld %lld\n", yy, d);
            ans = true;
        }
        xx += x;
        yy += y;
        d = yy * (yy + 1) / 2 - xx;
    }
    if (!ans) {
        printf("Impossible\n");
    }
}