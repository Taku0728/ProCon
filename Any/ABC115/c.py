n, k = map(int, input().split())
h = []
for i in range(n):
    h.append(int(input()))
h.sort()
mind = 9999999999
for i in range(n-k+1):
    mind = min(mind, h[i+k-1] - h[i])
print(mind)
