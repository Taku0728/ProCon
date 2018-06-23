N = int(input())
X = [int(input()) for x in range(N)]
s = 0
for i, x in enumerate(X):
    b = 0
    for y in X[i:]:
        if x == y:
            b += 1
    if b == 1:
        s += 1
print(s)