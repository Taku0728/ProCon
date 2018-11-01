N = int(input())
v = list(map(int, input().split()))
d0 = {0: 0}
d1 = {0: 0}
for j, i in enumerate(v):
    if j % 2 == 0:
        if i in d0:
            d0[i] += 1
        else:
            d0[i] = 1
    else:
        if i in d1:
            d1[i] += 1
        else:
            d1[i] = 1

l0 = sorted(d0.items(), key=lambda x: -x[1])
l1 = sorted(d1.items(), key=lambda x: -x[1])

if l0[0][0] == l1[0][0]:
    a = min(N - l0[0][1] - l1[1][1], N - l0[1][1] - l1[0][1])
    print(a)
else:
    print(N - l0[0][1] - l1[0][1])
