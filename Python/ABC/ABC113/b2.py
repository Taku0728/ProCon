N = int(input())
T, A = map(int, input().split())
H = list(map(int, input().split()))
best = 9999
ind = 0
for i, h in enumerate(H):
    tem_dis = abs(A - (T - h*0.006))
    if best > tem_dis:
        best = tem_dis
        ind = i + 1
print(ind)
