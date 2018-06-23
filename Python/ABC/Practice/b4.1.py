N = int(input())
A = [int(x) for x in input().split()]

A.sort(reverse=True)
sumA = 0
sumB = 0
for i, x in enumerate(A):
    if i % 2 == 0:
        sumA += x
    else:
        sumB += x
print(sumA- sumB)