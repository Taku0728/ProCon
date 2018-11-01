mod = 1000000007

# nの素因数分解


def prime(n):
    d = []
    i = 2
    while n != 1:
        s = 0
        while n % i == 0:
            n /= i
            s += 1
        d.append(s)
        i += 1
    return d


# xのn乗を計算する
def mod_pow(x, n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        half = int(n / 2)
        half_x = mod_pow(x, half)
        return half_x * half_x % mod
    else:
        return x * mod_pow(x, n - 1) % mod


def nCr(n, r):
    x = 1
    r = min(r, n - r)
    for i in range(r):
        x *= n - i
        x %= mod
        x *= mod_pow(i + 1, mod - 2)
        x %= mod
    return x


def solve():
    N, M = map(int, input().split())
    p = prime(M)
    s = 1
    for i in p:
        s *= nCr(i + N - 1, N - 1)
        s %= mod
    print(s)


solve()
