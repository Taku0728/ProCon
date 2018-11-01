# nの約数を求める
def divisor(n):
    d = []
    for i in range(int(n**(0.5)+1))[1:]:
        if n % i == 0:
            d.append(i)
            if i * i != n:
                d.append(int(n / i))
    return d


N, M = map(int, input().split())
# d はnの約数のベクター
d = divisor(M)
g = int(M / N)
# 可能なものはg以下
d = [x for x in d if x <= g]
print(max(d))
