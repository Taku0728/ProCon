s = []
p = []


def eat(x, i):
    if x <= 0:
        return 0
    if i == 0:
        return 1
    if x - i + 1 >= s[i]:
        return p[i]
    elif x >= s[i - 1] + 1:
        r = p[i - 1] + 1 if x >= s[i - 1] + 2 else 0
        return r + eat(x - s[i - 1] - 2, i - 1)
    else:
        return eat(x - 1, i - 1)


def solve():
    N, X = map(int, input().split())
    s.append(1)
    p.append(1)
    for i in range(N):
        s.append(2 * s[i] + 3)
        p.append(2 * p[i] + 1)
    print(eat(X, N))


solve()
