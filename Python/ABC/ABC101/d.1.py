# N = int(input())


def S(n):
    s = 0
    while n > 0:
        s += n % 10
        n = int(n / 10)
    return s


L = [i / S(i) for i in range(1, 10000)]
SL = [[i + 1, x] for i, x in enumerate(L) if x == min(L[i:])]
print(SL)
