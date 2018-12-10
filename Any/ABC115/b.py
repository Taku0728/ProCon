n = int(input())
p = []
for i in range(n):
    p.append(int(input()))
print(sum(p) - int(max(p)/2))
