x, y, R = input().split()
c = [input() for _ in range(9)]
d = [0, 0]
if R.find('U') > -1:
    d[0] = -1
if R.find('D') > -1:
    d[0] = 1
if R.find('L') > -1:
    d[1] = -1
if R.find('R') > -1:
    d[1] = 1
l = [int(y) - 1, int(x) - 1]
ans = ''
for _ in range(4):
    ans += c[l[0]][l[1]]
    if not 0 <= l[0] + d[0] < 9:
        d[0] = -d[0]
    if not 0 <= l[1] + d[1] < 9:
        d[1] = -d[1]
    l[0] += d[0]
    l[1] += d[1]
print(ans)
    
