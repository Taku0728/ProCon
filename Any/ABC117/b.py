def f(n):
    if n % 2 == 0:
        return int(n/2)
    else:
        return 3*n+1


s = int(input())
i = 2
a = s
b = f(s)
d = {s: 1}
while b not in d:
    d[b] = 1
    a = b
    b = f(b)
    i += 1
print(i)
