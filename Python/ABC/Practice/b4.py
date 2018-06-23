N = int(input())
A = [int(x) for x in input().split()]

A.sort()
sumA = 0
sumB = 0
while len(A) > 0:
    sumA += A[len(A) - 1]
    A.pop()
    if (len(A) > 0):
        sumB += A[len(A) - 1]
        A.pop()
print(sumA- sumB)