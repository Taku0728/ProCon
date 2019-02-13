N = int(input())
h = list(map(int, input().split()))

c = 0
while 1:
    for i in range(N):
        if h[i] != 0:
            break
    else:
        break
    con0 = 1
    for i in range(N):
        if con0 == 1 and h[i] != 0:
            c += 1
            con0 = 0
        elif con0 == 0 and h[i] == 0:
            con0 = 1
        if h[i] != 0:
            h[i] -= 1

print(c)
