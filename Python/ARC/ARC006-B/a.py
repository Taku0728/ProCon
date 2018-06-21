N, L = [int(x) for x in input().split()]
c = [input().split('|') for _ in range(L)]
y = input()

sj = int(y.index('o')/2)
si = L - 1
while si > -1:
    if c[si][sj] == '-':
        sj -= 1
    elif c[si][sj + 1] == '-':
        sj += 1
    si -= 1
print(sj + 1)