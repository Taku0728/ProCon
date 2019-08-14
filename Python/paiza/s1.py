

def s2n2n2s(s2n):
    n2s = {}
    for key in s2n:
        n2s[s2n[key]] = key
    return n2s


def rotate(n2s, s2n, num):
    if n2s[num] == 'T':
        return n2s, s2n, 0
    if n2s[num] == 'D':
        tem = s2n['D']
        s2n['D'] = s2n['B']
        s2n['B'] = s2n['U']
        s2n['U'] = s2n['T']
        s2n['T'] = tem
        n2s = s2n2n2s(s2n)
        return n2s, s2n, 1
    if n2s[num] == 'U':
        tem = s2n['U']
        s2n['U'] = s2n['B']
        s2n['B'] = s2n['D']
        s2n['D'] = s2n['T']
        s2n['T'] = tem
        n2s = s2n2n2s(s2n)
        return n2s, s2n, 1
    if n2s[num] == 'R':
        tem = s2n['R']
        s2n['R'] = s2n['B']
        s2n['B'] = s2n['L']
        s2n['L'] = s2n['T']
        s2n['T'] = tem
        n2s = s2n2n2s(s2n)
        return n2s, s2n, 1
    if n2s[num] == 'L':
        tem = s2n['L']
        s2n['L'] = s2n['B']
        s2n['B'] = s2n['R']
        s2n['R'] = s2n['T']
        s2n['T'] = tem
        n2s = s2n2n2s(s2n)
        return n2s, s2n, 1
    if n2s[num] == 'B':
        tem = s2n['B']
        s2n['B'] = s2n['T']
        s2n['T'] = tem
        tem = s2n['R']
        s2n['R'] = s2n['L']
        s2n['L'] = tem
        n2s = s2n2n2s(s2n)
        return n2s, s2n, 2


s2n = {}
T, B, U, D, L, R = map(int, input().split())
s2n['T'] = T
s2n['B'] = B
s2n['U'] = U
s2n['D'] = D
s2n['L'] = L
s2n['R'] = R
n2s = s2n2n2s(s2n)
N = int(input())
p = []
for i in range(N):
    p.append(int(input()))
count = 0
for pp in p:
    n2s, s2n, a = rotate(n2s, s2n, pp)
    count += a
print(count)
