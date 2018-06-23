N = int(input())
Tab = [[int(x) for x in input().split()] for i in range(N)]

t, x, y = 0, 0, 0
b = True
for a in Tab:
    dt, dx, dy = a[0] - t, a[1] - x, a[2] - y
    if dt < dx + dy or (dt - dx - dy) % 2 != 0:
        b = False
        break
    t, x, y = a
if b: print('Yes')
else: print('No')

# 12:36