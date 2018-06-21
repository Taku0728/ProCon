from collections import deque
H, W = [int(x) for x in input().split()]
c = [input() for _ in range(H)]
for i, x in enumerate(c):
    for j, y in enumerate(x):
        if y == 's':
            s = [i, j, 0]
tab = [[3 for _ in range(W)] for _ in range(H)]
dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
dq = deque()
dq.append(s)
yes = 0
while len(dq):
    i, j, k = dq.pop()
    a = 1 if c[i][j] == '#' else 0
    if tab[i][j] <= k + a:
        continue
    if k + a > 2:
        break
    if c[i][j] == 'g':
        print('YES')
        yes = 1
        break
    tab[i][j] = k + a
    for d in dir:
        nl = [i + d[0], j + d[1], k + a]
        if 0 <= nl[0] < H and 0 <= nl[1] < W:
            if a: dq.appendleft(nl)
            else: dq.append(nl)
if not yes:
    print('NO')

