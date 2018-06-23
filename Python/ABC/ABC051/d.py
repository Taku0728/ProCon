import math
N, M = [int(x) for x in input().split()] 
T = [[int(x) for x in input().split()] for i in range(N)]

def func(a, b, l):
    a1T = [x for x in T if (x[0] == a or x[1] == a) and x[2] < l]
    for x in a1T:
        an = x[0] if x[1] == a else x[1]
        if an == b or func(an, b, l - t[2]):
            return True
    return False

sum = 0
for t in T:
    if func(t[0], t[1], t[2]):
       sum += 1
print(sum)

# 28:13