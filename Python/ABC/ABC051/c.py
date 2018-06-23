sx, sy, tx, ty = [int(x) for x in input().split()]
ss = ''
for i in range(tx - sx):
    ss += 'R'
for i in range(ty - sy):
    ss += 'U'
for i in range(tx - sx):
    ss += 'L'
for i in range(ty - sy):
    ss += 'D'
ss += 'D'
for i in range(tx - sx + 1):
    ss += 'R'
for i in range(ty - sy + 1):
    ss += 'U'
ss += 'L'
ss += 'U'
for i in range(tx - sx + 1):
    ss += 'L'
for i in range(ty - sy + 1):
    ss += 'D'
ss += 'R'
print(ss)