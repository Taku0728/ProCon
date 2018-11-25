N = int(input())
T, A = map(int, input().split())
list_H = list(map(int, input().split()))
best = float('inf')
for i, H in enumerate(list_H):
    cost = abs(A - (T - H * 0.006))
    if cost < best:
        best = cost
        ind = i + 1
print(ind)
