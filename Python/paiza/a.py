

def clear(field, r, c):
    for row in field[r:]:
        if row[c] == '#':
            break
    else:
        return True
    return False


def drop(field, block):
    si = 0
    sj = block[2]
    for i in range(len(field)):
        si = i
        for j in range(block[1]):
            if not clear(field, i, sj + j):
                break
        else:
            break
        continue
    for i in range(block[0]):
        for j in range(block[1]):
            field[si + i][sj + j] = '#'
    return field


def out(field):
    for row in field[::-1]:
        print(''.join(row))


H, W, N = map(int, input().split())
blocks = []
for i in range(N):
    block = list(map(int, input().split()))

field = [['.' for _ in range(W)] for __ in range(H)]

for block in blocks:
    field = drop(field, block)
out(field)
