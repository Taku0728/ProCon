N = input()
A = [int(x) for x in input().split()]
b = True
o = -1
while (b):
    o += 1
    for i, a in enumerate(A):
        if a % 2 != 0:
            b = False
            break
        else:
            A[i] /= 2
print(o)