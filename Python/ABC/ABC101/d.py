# N = int(input())


def S(n):
    s = 0
    while n > 0:
        s += n % 10
        n = int(n / 10)
    return s


def fni(i):
    a = 1
    while i > 0:
        a * 10
        i = int(i / 10)
    return a


K = int(input())
T = [1]
d = 1
i = 1
ni = 10
while len(T) < K:
    si = S(i + d)
    ii = i + d
    b = True
    ni = fni(i + d + 1)
    while ii < ni:
        ii += d
        if ((i + d) / si) > (ii / S(ii)):
            b = False
            break
    if b:
        T.append(i + d)
        i += d
    else:
        d *= 10

for i in T:
    print(i)
