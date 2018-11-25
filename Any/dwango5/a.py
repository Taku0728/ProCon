N = int(input())
a = list(map(int, input().split()))
ave = sum(a) / len(a)
c = []
for i in a:
    c.append(abs(i - ave))
print(c.index(min(c)))
