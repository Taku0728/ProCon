N = int(input())
L = [int(input()) for _ in range(N)]
print(sum(L))
print(0 if sum(L) - 2*max(L) > 0 else sum(L) - max(L))