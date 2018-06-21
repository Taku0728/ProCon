A = ['.......',
    '...o...',
    '..o.o..',
    '.o...o.',
    '.ooooo.',
    '.o...o.',
    '.......']

B = ['.......',
    '.oooo..',
    '.o...o.',
    '.oooo..',
    '.o...o.',
    '.oooo..',
    '.......']

C = ['.......',
    '..ooo..',
    '.o...o.',
    '.o.....',
    '.o...o.',
    '..ooo..',
    '.......']

def rotate(alp):
    size = len(alp)
    bet = [['' for x in range(size)] for y in range(size)]
    for i in range(size):
        for j in range(size):
            bet[i][j] = alp[j][size - 1 - i]
    return bet

def multi(alp, n):
    size = len(alp)
    bet = [['' for x in range(size*n)] for y in range(size*n)]
    for i in range(size):
        for j in range(size):
            for k in range(n):
                for l in range(n):
                    bet[i * n + k][j * n + l] = alp[i][j]
    return bet

H, W = [int(x) for x in input().split()]
c = [input() for _ in range(H)]

tab = [A, B, C]
for i in range(9):
    tab.append(rotate(tab[len(tab) - 3]))

for i in range(int(min(H, W) / 7) - 1):
    for j in range(12):
        tab.append(multi(tab[j], i + 2))

count = [0, 0, 0]
for i in range(H):
    for j in range(W):
        for n, x in enumerate(tab):
            size = len(x)
            if i + size <= H and j + size <= W:
                f = 1
                for k in range(size):
                    for l in range(size):
                        if c[i + k][j + l] != x[k][l]:
                            f = 0
                            break
                    if not f:
                        break
                if f:
                    count[n % 3] += 1
print(' '.join([str(n) for n in count]))