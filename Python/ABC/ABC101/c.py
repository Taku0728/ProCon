N, K = [int(x) for x in input().split()] 
A = [int(x) for x in input().split()]
# i = A.index(min(A))
# sum = 0
# ii = 0
# while ii + 1 < i:
#     sum += 1
#     ii += K - 1
if N == K:
    print(1)
else:
    print(int((N - 1) / (K - 1)) + 1)