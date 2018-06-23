N, Y = [int(x) for x in input().split()]
Y = int(Y / 1000)
a, b, c = -1, -1, -1
f = False
for i in range(0, N + 1):
    y0 = Y - 10 * i
    if y0 < 0: break
    for j in range(0, N + 1 - i):
        y1 = y0 - 5 * j
        if y1 < 0: break
        if y1 == N - i - j:
            a, b, c = i, j, y1
            f = True
            break
    if f: break
print(a, b, c)