import queue
import sys
input = sys.stdin.readline


def toab(s, ab, node):
    toa, tob = False, False
    for k in ab:
        if k not in node:
            continue
        if s[k - 1] == 'A':
            toa = True
            if tob:
                return True
        elif s[k - 1] == 'B':
            tob = True
            if toa:
                return True
    return False


ab = {}
node = {}
N, M = map(int, input().split())
s = input()
for i in range(M):
    a, b = map(int, input().split())
    if a not in ab:
        ab[a] = {}
    ab[a][b] = True
    if b not in ab:
        ab[b] = {}
    ab[b][a] = True
    node[a] = True
    node[b] = True

for i in range(N + 1):
    if i not in node:
        continue
    q = queue.Queue()
    q.put(i)
    while not q.empty():
        j = q.get()
        if j in node and not toab(s, ab[j], node):
            print(j)
            node.pop(j)
            for k in ab[j]:
                if k in node:
                    q.put(k)

if not node:
    print('No')
else:
    print('Yes')
