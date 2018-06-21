N = int(input())
l = []
for _ in range(N):
    w = int(input())
    f = 0
    for i in range(len(l)):
        if w <= l[i]:
            l[i] = w
            f = 1
            break
    if not f:
        l.append(w)
print(len(l))

#11:49