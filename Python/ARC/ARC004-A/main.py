N = int(input())
plot = [[int(x) for x in input().split()] for _ in range(N)]
l = 0
for p0 in plot:
    for p1 in plot:
        l = max(l, ((p0[0] - p1[0])**2 + (p0[1] - p1[1])**2)**0.5)
print(l)