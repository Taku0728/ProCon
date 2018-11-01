N, T = map(int, input().split())
a = 9999
for _ in range(N):
    c, t = map(int, input().split())
    if t <= T:
        a = min(a, c)
if a == 9999:
    print('TLE')
else:
    print(a)
